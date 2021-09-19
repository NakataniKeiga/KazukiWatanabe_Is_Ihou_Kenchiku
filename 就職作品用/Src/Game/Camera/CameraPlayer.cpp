#include"CameraPlayer.h"
#include"../Input/Input.h"
#include"DxLib.h"
#include"math.h"
// 定数一覧
//static const float CAMERA_LENGTH = 10.0f;	// ターゲットとカメラの距離
//static const float CAMERA_OFFSET_Y = 20.0f;	// カメラのオフセット
//static const float FOCUS_OFFSET_Y = 30.0f;	// フォーカスのオフセット

static const float CAMERA_LENGTH = 30.0f;
static const float CAMERA_OFFSET_Y = 20.0f;
static const float FOCUS_OFFSET_Y = 10.0f;

//コンストラクタ
CPlayCamera::CPlayCamera()
{
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	memset(&m_vFocus, 0, sizeof(m_vFocus));
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
	m_fNear = 1.0f;
	m_fFar = 1500.0f;
}

//初期化
void CPlayCamera::Init()
{

}
//ニア・ファー
void CPlayCamera::SetNearFar(float nearLength, float farLength)
{
	m_fNear = nearLength;
	m_fFar = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//メイン処理
void CPlayCamera::Step(VECTOR focus)
{
	//VECTOR temp;
	if (CInputKey::IsPuchTrg(KEY_INPUT_UP))
	{
		m_vRot.x += 0.00f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_DOWN))
	{
		m_vRot.x -= 0.00f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_RIGHT))
	{
		m_vRot.y += 0.01f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_LEFT))
	{
		m_vRot.y -= 0.01f;
	}

	

	//格納する関数
	MATRIX result=MGetIdent();

	//現在地を保管する
	VECTOR return_pos = focus;

	//注視点を原点に
	VECTOR playerPos = VSub(focus, focus);

	//注視点が原点にいるときのマトリックス
	MATRIX playerfocus = MGetTranslate(playerPos);

	//カメラを設置する数値を入れるマトッリクス
	MATRIX campos = MGetTranslate(VGet(playerPos.x, playerPos.y += 1.5f, playerPos.z +=5.0f));

	//回転用の行列
	MATRIX playerCameraPos_X = MGetRotX(m_vRot.x);
	MATRIX playerCameraPos_Y = MGetRotY(m_vRot.y);
	MATRIX playerCameraPos_Z = MGetRotZ(m_vRot.z);

	//もとに戻す行列
	MATRIX playerCamera = MGetTranslate(return_pos);

	result = MMult(result,playerfocus);
	result = MMult(result, campos);
	result = MMult(result, playerCameraPos_X);
	result = MMult(result, playerCameraPos_Y);
	result = MMult(result, playerCameraPos_Z);
	result = MMult(result, playerCamera);

	m_vPos = VTransform(playerPos, result);
	//注視点を設定
	m_vFocus = focus;


 
}

//更新処理
void CPlayCamera::Update()
{
	SetCameraNearFar(m_fNear, m_fFar);
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vFocus, m_vUp);
}