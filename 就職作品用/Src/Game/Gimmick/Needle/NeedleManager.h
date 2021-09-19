#pragma once
#include"Needle.h"
#include"../../Field/StageManager.h"
#include"../GimmickBase.h"

//�j�̍ő吔
static const int NEEDLE_MAX = 40;

class CNeedleManager:public CGimmickBase
{
private:

	std::vector<CNeedle*>m_Needle_vec;

public:

	CNeedleManager() ;
	~CNeedleManager() {};

	//�����l
	void Init();
	//���f�����[�h
	void Load();
	//�X�V����
	void Step();
	//�X�V����
	void Update();
	//�`��
	void Draw();
	//�I��
	void Fin();

};