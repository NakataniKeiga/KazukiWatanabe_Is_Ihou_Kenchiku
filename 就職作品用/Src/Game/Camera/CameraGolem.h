#pragma once
#include"DxLib.h"
#include"../Camera/CameraBase.h"

class CGolemCamera:public CCameraBase
{


public:
	CGolemCamera();
	~CGolemCamera();

	//�����ݒ�
	void Init();
	//�j�A�E�t�@�[�Z�b�g
	void SetNeartFar(float m_near,float m_far);
	//���C������
	void Step(VECTOR m_focus);
	//�X�V����
	void Update();

};
