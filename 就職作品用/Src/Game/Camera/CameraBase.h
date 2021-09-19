#pragma once

class CCameraBase
{
protected:

	VECTOR m_vPos;
	VECTOR m_vRot;
	VECTOR m_vFocus;
	VECTOR m_vUp;

	float m_fNear, m_fFar;

public:
	CCameraBase() {};
	~CCameraBase() {};

	//初期関数
	virtual void Init() {};
	//ニア・ファーセット
	virtual void SetNearFar() {};
	//メイン処理
	virtual void Step() {};
	//更新処理
	virtual void Update() {};

	VECTOR GetCameraRot() { return m_vRot; }

};