#pragma once
#include"PlayerAnimation.h"
#include"CharacterCommon.h"
#include"DxLib.h"

#define PL_RADIUS			( 1.0f )

class CCharacterBase
{
protected:
	CAnimation m_Anime;

	VECTOR m_vPos;
	VECTOR m_vRot;
	VECTOR m_vScale;
	VECTOR m_vMove;//�ړ���
	int m_iHandle;
	float m_fRadius;
	bool m_isAlive;//�����t���O
	bool m_isActivate;//�L�����N�^�[�̐؂�ւ��p
	bool m_isCall;	//player�Ȃ�Ă�,golem�Ȃ�Ă΂��

	VECTOR m_vGravity;//�I�u�W�F�N�g�̏d�͏���
	float m_fGravity;//�d�͏���

	tagcharacter m_kind;


public:
	//�����o�ϐ��̐ݒ�
	void SetPos(VECTOR pos) { m_vPos = pos; }//���݂̍��W
	void SetRot(VECTOR rot) { m_vRot = rot; }//��]�p
	void SetRadius(float radius) { m_fRadius = radius; }   //���a
	void SetHandl(int handl) { m_iHandle = handl; }
	void UpdateGravity() {};
	void ReflecCollision(VECTOR vAddVec); //���݈ʒu�ɍ��W���Z
	void SetKind(tagcharacter kind) { m_kind = kind; }

	//�����o�ϐ��̎擾
	VECTOR GetPos() { return m_vPos; }  //���݂̍��W��Ԃ�
	VECTOR GetRot() { return m_vRot; }//���݂̉�]�p��Ԃ�
	VECTOR GetCeneter();
	tagcharacter GetKind() { return m_kind; }
	float GetRadius() { return m_fRadius; }//�I�u�W�F�g�̔��a��Ԃ�
	int GetHndl() { return m_iHandle; }


	//�R���X�g���N�^�ŃA�N�e�B�u��true��
	CCharacterBase() { m_isActivate = true; }
	//���݂̈ړ��ʂ�Ԃ�
	VECTOR GetMove() { return m_vMove; }
	//�؂�ւ��p�t���O�擾
	bool GetActivate() { return m_isActivate; }
	//�Ăяo���p�t���O�擾
	bool GetCall() { return m_isCall; }
	//�����t���O
	bool GetIsAlive() { return m_isAlive; }
	//�ړ���
	void SetMove(VECTOR move) { m_vMove = move; }
	//�Ăяo���p�t���O�Z�b�g
	void SetCall(bool flg) { m_isCall = flg; }
	//�؂�ւ��p�t���O�Z�b�g
	void SetActivate(bool flg) { m_isActivate = flg; }
	//�����t���O
	void SetIsAlive(bool isalive) { m_isAlive = isalive; }  

	void SetGravity(VECTOR garavity) { m_vGravity = garavity; }

	void SetfGravity(float gravity) { m_fGravity = gravity; }
	VECTOR GeteGravity() { return m_vGravity; }

	//���z�֐�
public:
	//������
	virtual void Init();
	//���C������
	virtual void Step();
	//�Z�b�g
	virtual void Update();
	//�`��
	virtual void Draw();
	//���f���̍폜
	virtual void DeleteModl();
	//�I��
	virtual void Fin();

	virtual void Collision() {};
	//���f���̃��[�h
	bool LoadModel(const char* pFileName);
	//���f���̃R�s�[
	bool DuplicateModel(int iSrcHndl);

};