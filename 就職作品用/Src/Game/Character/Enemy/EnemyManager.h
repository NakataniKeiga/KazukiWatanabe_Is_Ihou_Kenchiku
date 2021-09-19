#pragma once
#include"Enemy.h"
#include"../../../Lib/Singleton.h"

static const int ENEMY_MAX = 2;

class CEnemyManager:public CSingleton<CEnemyManager> {

	friend CSingleton;
private:
	
	std::vector<CEnemy*>m_Enemy_vec;

	int m_iStageType;//�X�e�[�W�^�C�v�����

	int m_iRootID[ENEMY_MAX];

public:

	CEnemyManager();
	~CEnemyManager() {};

	//������
	void Init();
	//���[�h
	void Load();
	//�Z�b�g
	void Step();
	//�ړ�
	void Move();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�㏈��
	void Fin();

};