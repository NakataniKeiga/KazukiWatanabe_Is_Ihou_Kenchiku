#pragma once
#include"DxLib.h"
#include"list"
#include<vector>

#define PL_RADIUS			( 1.0f )
//�I�u�W�F�N�g�N���X
class CObjectBase
{
protected:
	VECTOR m_vPos;    //���݂̍��W
	VECTOR m_vRot;//��]�e
	VECTOR m_vScale;//�傫��
	float m_fRadius;//�I�u�W�F�N�g�̔��a
	int m_iHndl;//���f���n���h��



//public:
//	//�����o�ϐ��̐ݒ�
//	void SetPos(VECTOR pos) { m_vPos = pos; }//���݂̍��W
//	void SetRot(VECTOR rot) { m_vRot = rot; }//��]�p
//
//	
//	void SetRadius(float radius) { m_fRadius = radius; }   //���a
//
//	
//
//	void UpdateGravity() {};
//
//	//�����o�ϐ��̎擾
//	VECTOR GetPos() { return m_vPos; }  //���݂̍��W��Ԃ�
//	VECTOR GetRot() { return m_vRot; }//���݂̉�]�p��Ԃ�
//
//	VECTOR GetCeneter();
//
//	void ReflecCollision(VECTOR vAddVec); //���݈ʒu�ɍ��W���Z
//	float GetRadius() { return m_fRadius; }//�I�u�W�F�g�̔��a��Ԃ�
//
//	//���z�֐�
//public:
//	//������
//	virtual void Init();
//	//���C������
//	virtual void Step();
//	//�Z�b�g
//	virtual void Update();
//	//�`��
//	virtual void Draw();
//	//���f���̍폜
//	virtual void DeleteModl();
//	//�I��
//	virtual void Fin();
//	//���f���̃��[�h
//	bool LoadModel(const char* pFileName);
//	//���f���̃R�s�[
//	bool DuplicateModel(int iSrcHndl);

};