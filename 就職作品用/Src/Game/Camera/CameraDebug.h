#pragma once
#include"DxLib.h"

class CDebugCamera {
private:
	VECTOR m_vPos;
	VECTOR m_vRot;
	float m_near, m_far;

public:
	//�R���X�g���N�^
	CDebugCamera();

	//�����֐�
	void Init();
	//�j�A�E�t�@�[�Z�b�g
	void SetNearFar(float nearLength,float farLength);
	//���C������
	void Step(VECTOR focus,float rotY);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();

	// ���W�Ɗp�x���Z�b�g
	void SetPosition(VECTOR pos) { m_vPos = pos; }
	void SetRotation(VECTOR rot) { m_vRot = rot; }


};