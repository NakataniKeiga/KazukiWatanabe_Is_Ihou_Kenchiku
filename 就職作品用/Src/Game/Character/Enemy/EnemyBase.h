#pragma once
#include"../../ObjectBase/Object3DBase.h"

class CEenmyBase :public CObjectBase
{
protected:


	VECTOR m_vGravity;
	float m_fGravity;


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

	void SetPos(VECTOR pos) { m_vPos = pos; }
	void SetRot(VECTOR rot) { m_vRot = rot; }

	void SetRadius(float radius) { m_fRadius = radius; }

	//�����o�ϐ��̎擾
	VECTOR GetPos() { return m_vPos; }  //���݂̍��W��Ԃ�
	VECTOR GetRot() { return m_vRot; }//���݂̉�]�p��Ԃ�
	float GetRadius() { return m_fRadius; }//�I�u�W�F�g�̔��a��Ԃ�

};