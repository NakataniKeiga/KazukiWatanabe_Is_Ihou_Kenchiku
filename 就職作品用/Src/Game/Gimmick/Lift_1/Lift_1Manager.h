#pragma once
#include"Lift_1/Lift_1.h"
#include"Lift_Lever/Lever.h"
#include"../GimmickBase.h"
#include"../../Scene/ScenePlay/ScenePlay.h"


// //�E�H�[���̑���
//static const int LIFT_MAX = 3;



class CLift_1Manager:public CGimmickBase
{
private:

	std::vector<CLift_1*>m_Lift_1_vec;
	std::vector<CLever*>m_Lever_1_vec;
	
	//�����蔻��p�t���O
	bool m_isHitFlg;



public:

	CLift_1Manager();
	~CLift_1Manager() {};

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
	//���t�g�̈ړ�����
	void Move();

	//���t�g���o�[�̍��W
	VECTOR GetLeverPos(int num);
	//���t�g�̃n���h���擾
	int GetLiftHandle(int num);

};