
#pragma once
#include"Lift_2/Lift_2.h"
#include"Lift_switch/Lift_switch.h"
#include"../Box_1/Box_1.h"
#include"../GimmickBase.h"

//static const int LIFT_2_MAX = 15;


class CLift_2Manager:public CGimmickBase
{
private:

	std::vector<CLift_2*>m_Lift_2_vec;
	std::vector<CLift_Switch*>m_Lever_Switch_vec;


public:

	CLift_2Manager();
	~CLift_2Manager() {};

	//������
	void Init();
	//���[�h
	void Load();
	//�Z�b�g
	void Step(CBox_1* Box,int BoxNum);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();
	//���t�g�̈ړ�����
	void Move();
	//���Ƃ̓����蔻��
	VECTOR GetLeverPos(int num);

};