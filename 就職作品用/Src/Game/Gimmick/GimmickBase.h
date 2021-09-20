#pragma once
#include"../ObjectBase/Object3DBase.h"
#include"../Gimmick/GimmickCommon.h"
#include"../Character/Player/Player.h"

class CGimmickBase/*:public CObjectBase*/
{
protected:

	VECTOR m_vPos;    //���݂̍��W
	VECTOR m_vRot;//��]�e
	VECTOR m_vScale;//�傫��
	float m_fRadius;//�I�u�W�F�N�g�̔��a
	int m_iHndl;//���f���n���h��

	taggimmick m_kind;
	int m_iStageType;

public:
	//������
	virtual void Init() {};
	//�ǂݍ��ݏ���
	virtual void Load() {};
	//���C������
	virtual void Step() {};
	//�X�V����
	virtual void Update() {};
	//�`�揈��
	virtual void Draw() {};
	//�I������
	virtual void Fin() {};

	virtual void PlayerHit(CPlayer* player) {};

	void SetPos(VECTOR pos) { m_vPos = pos; }
	void SetRot(VECTOR rot) { m_vRot = rot; }

	void SetRadius(float radius) { m_fRadius = radius; }

	//�����o�ϐ��̎擾
	VECTOR GetPos() { return m_vPos; }  //���݂̍��W��Ԃ�
	VECTOR GetRot() { return m_vRot; }//���݂̉�]�p��Ԃ�
	VECTOR GetCenter();

	float GetRadius() { return m_fRadius; }//�I�u�W�F�g�̔��a��Ԃ�

	int GetHandle() { return m_iHndl; }

	taggimmick GetKind() { return m_kind; }

	void SetKind(taggimmick kind) { m_kind = kind; }




};