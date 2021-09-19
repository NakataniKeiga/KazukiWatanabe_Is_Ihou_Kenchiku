#include"CameraDebug.h"
#include"math.h"

static const float CAMERA_LENGTH = 30.0f;   //
static const float CAMERA_OFFSET_Y = 20.0f;
static const float FOCUS_OFFSET_Y = 10.0f;	// フォーカスのオフセット
static const float MOVE_SPEED = 2.0f;		// カメラの移動速度


//コンストラクタ
CDebugCamera::CDebugCamera()
{
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	m_near = 1.0f;
	m_far = 1500.0f;
}

//初期化
void CDebugCamera::Init()
{
	m_vPos = VGet(0.0f, 10.0f, -10.0f);
	memset(&m_vRot, 0, sizeof(m_vRot));
	m_near = 1.0f;
	m_far = 1500.0f;

}
//セット・ニア・ファー
void CDebugCamera::SetNearFar(float nearLength, float farLength)
{
	m_near = nearLength;
	m_far = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//メイン処理
void CDebugCamera::Step(VECTOR focus, float rotY)
{
	float camspeed = 0.1f;
	//カメラの上下回転
	if (CheckHitKey(KEY_INPUT_UP))
	{
		if (m_vRot.x > -90.0 * DX_PI_F / 180.0f)
			m_vRot.x -= camspeed;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		if (m_vRot.x < 90.0 * DX_PI_F / 180.0f)
			m_vRot.x += camspeed;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_vRot.y += camspeed;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_vRot.y -= camspeed;
	}
	//カメラの左右回転
	float spped = 0.0f;
	//キャラクター前後移動
	if (CheckHitKey(KEY_INPUT_W))spped = MOVE_SPEED;
	else if (CheckHitKey(KEY_INPUT_S))spped = -MOVE_SPEED;

	//入力したキー情報とプレイヤーの角度から、移動速度を求める
	VECTOR v;
	v.x = sinf(m_vRot.y) * spped;
	v.y = 0.0f;
	v.z = cosf(m_vRot.y) * spped;

	//プレイヤーの座標を更新してセットする
	m_vPos = VAdd(m_vPos, v);

	spped = 0.0f;

	//キャラクター左右移動
	if (CheckHitKey(KEY_INPUT_D))spped = MOVE_SPEED;
	else if (CheckHitKey(KEY_INPUT_A))spped = -MOVE_SPEED;

	v.x = sinf(m_vRot.y + DX_PI_F * 0.5f) * spped;
	v.y = 0.0f;
	v.z = cosf(m_vRot.y + DX_PI_F * 0.5f) * spped;

	m_vPos = VAdd(m_vPos, v); SetCameraPositionAndAngle(m_vPos, m_vRot.x, m_vRot.y, m_vRot.z);

}
//描画
void CDebugCamera::Draw()
{
	int color = GetColor(255, 255, 255);
	DrawFormatString(32, 32, color, "現在デバックモードです！");
	DrawFormatString(32, 64, color, "カメラの座標:x=%f y=%f z=%f", m_vPos.x, m_vPos.y, m_vPos.z);
	DrawFormatString(32, 96, color, "カメラの角度:x=%f y=%f z=%f", m_vPos.x, m_vPos.y, m_vPos.z);
}