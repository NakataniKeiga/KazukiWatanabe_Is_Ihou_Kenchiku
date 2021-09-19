#include"CameraGolem.h"
#include"../Input/Input.h"
//#include"../Character/Golem/Golem.h"
#include"math.h"

	static const float CAMERA_LENGTH = 0.1f;	//カメラとの距離
	static const float CAMERA_OFFSET_Y = 2.0f; //カメラとの
	static const float FOCUS_DRONE_OFFSET_Y = 0.0f;	//中心との


CGolemCamera::CGolemCamera()
{
	
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	memset(&m_vFocus, 0, sizeof(m_vFocus));
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
	m_fNear = 1.0f;
	m_fFar = 1500.0f;
}

CGolemCamera::~CGolemCamera()
{

}
//初期化
void CGolemCamera::Init()
{

}
//ニア・ファー
void CGolemCamera::SetNeartFar(float nearLength, float farLength)
{
	m_fNear = nearLength;
	m_fFar = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//メイン処理
void CGolemCamera::Step(VECTOR focus)
{
	if (CInputKey::IsPuchTrg(KEY_INPUT_RIGHT))
	{
		m_vRot.y += 0.05f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_LEFT))
	{
		m_vRot.y -= 0.05f;
	}
	//格納する関数
	MATRIX result = MGetIdent();

	//現在地を保管する
	VECTOR return_pos = focus;

	//注視点を原点に
	VECTOR dronePos = VSub(focus, focus);

	//注視点が原点にいるときのマトリックス
	MATRIX dronefocus = MGetTranslate(dronePos);

	//カメラを設置する数値を入れるマトッリクス
	MATRIX campos = MGetTranslate(VGet(dronePos.x, dronePos.y += 2.0f, dronePos.z += 10.0f));

	//回転用の行列
	MATRIX playerCameraPos_X = MGetRotX(m_vRot.x);
	MATRIX playerCameraPos_Y = MGetRotY(m_vRot.y);
	MATRIX playerCameraPos_Z = MGetRotZ(m_vRot.z);

	//もとに戻す行列
	MATRIX playerCamera = MGetTranslate(return_pos);
	//順番に関数に入れていく
	result = MMult(result, dronefocus);
	result = MMult(result, campos);
	result = MMult(result, playerCameraPos_X);
	result = MMult(result, playerCameraPos_Y);
	result = MMult(result, playerCameraPos_Z);
	result = MMult(result, playerCamera);
	//
	m_vPos = VTransform(dronePos, result);

	m_vFocus = focus;

}
//更新処理
void CGolemCamera::Update()
{
	SetCameraNearFar(m_fNear, m_fFar);
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vFocus, m_vUp);
}