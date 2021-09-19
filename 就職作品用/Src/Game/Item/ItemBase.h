#pragma once
#include"../ObjectBase/Object3DBase.h"
#include"../Field/StageManager.h"
#include"ItemCommon.h"


class CItemBase 
{
protected:
	VECTOR m_vPos;    //���݂̍��W
	VECTOR m_vRot;//��]�e
	VECTOR m_vScale;//�傫��
	float m_fRadius;//�I�u�W�F�N�g�̔��a
	int m_iHndl;//���f���n���h��

	bool m_isAlive;
	tagitem m_kind;
	
public:
	CItemBase() {};
	~CItemBase() {};

	virtual void Init() {};
	//�ǂݍ��ݏ���
	virtual void Load() {};

	virtual void Draw() {};
	//���C������
	virtual void Step() {};
	//�X�V����
	virtual void Update() {};
	//�`�揈��
	//�I������
	virtual void Fin() {};



	//�����o�ϐ��̐ݒ�
	void SetPos(VECTOR pos) { m_vPos = pos; }//���݂̍��W
	void SetRot(VECTOR rot) { m_vRot = rot; }//��]�p
	void SetRadius(float radius) { m_fRadius = radius; }   //���a
	void SetIsAlive(bool isAlive) { m_isAlive = isAlive; }//�����t���O
	void SetKind(tagitem kind) { m_kind = kind; }

	//�����o�ϐ��̎擾
	VECTOR GetPos() { return m_vPos; }  //���݂̍��W��Ԃ�
	VECTOR GetRot() { return m_vRot; }//���݂̉�]�p��Ԃ�
	float GetRadius() { return m_fRadius; }
	bool GetIsAlive() { return m_isAlive; }//�����t���O
	tagitem GetKind() { return m_kind; }

	

};