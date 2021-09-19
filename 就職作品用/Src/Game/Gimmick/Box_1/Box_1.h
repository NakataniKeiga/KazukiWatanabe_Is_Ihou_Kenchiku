#pragma once
#include"DxLib.h"
#include"../GimmickBase.h"
#include"../../ObjectBase/Object3DBase.h"




class CBox_1:public CGimmickBase
{
private:
	VECTOR m_vMove;//�ړ���

	//���������Ă��锻��t���O
	bool m_isHave;

	VECTOR m_vGravity;//�I�u�W�F�N�g�̏d�͏���
	float m_fGravity;//�d�͏���
public:

	CBox_1() {};
	~CBox_1() {};

	//������
	void Init();
	//���[�h
	void Load();
	//�Z�b�g
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�㏈��
	void Fin();

	void PlayerHit();

	void SetGravity(VECTOR garavity) { m_vGravity = garavity; }
	void Setgravity(float gravity) { m_fGravity = gravity; }//�d�̓Z�b�g

	VECTOR GeteGravity() { return m_vGravity; }

	int GetHndl() { return m_iHndl; }

	float GetPosY() { return m_vPos.y; }

	//���݂̈ړ��ʂ�Ԃ�
	VECTOR GetMove() { return m_vMove; }
	//�ړ���
	void SetMove(VECTOR move) { m_vMove = move; }

};