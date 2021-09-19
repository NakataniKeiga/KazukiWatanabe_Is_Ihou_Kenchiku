#pragma once
#include"DxLib.h"
#include"EnemyBase.h"
#include"../PlayerAnimation.h"




class CEnemy :public CEenmyBase
{
private:
	enum tagenemy
	{
		STATE_CHASE=2,//�ǂ�������

		STATE_NUM,  //����
	};


	tagenemy m_state;

	bool m_isChase;

public:

	CEnemy() { Init(), Load(); }
	~CEnemy() { Fin(); };
	//������
	void Init();
	//���[�h����
	/*�����ł����Ƃ����{�[���̍��W�����Ă�����*/
	void Load();
	//���C������
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();

	VECTOR GetAttackPos();

	bool GetChace() { return m_isChase; }

};