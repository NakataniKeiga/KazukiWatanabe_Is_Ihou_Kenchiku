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

	//�����֐�
	virtual void Init() {};
	//�j�A�E�t�@�[�Z�b�g
	virtual void SetNearFar() {};
	//���C������
	virtual void Step() {};
	//�X�V����
	virtual void Update() {};

	VECTOR GetCameraRot() { return m_vRot; }

};