#pragma once
#include"DxLib.h"
#include"../../GimmickBase.h"
#include"../../../ObjectBase/Object3DBase.h"
#include"../../../Character/PlayerAnimation.h"

class CLever:public CGimmickBase
{
private:
	CAnimation m_Anime;

	enum tagchange
	{
		SWITCH_OFF,//�X�C�b�`OFF
		SWITCH_ON,//�X�C�b�`ON

		SWITCH_NUM//����
	};
	

	VECTOR m_vLeverPos;
	int m_iState;
	//���o�[���W�̐�
	bool m_isChange;

public:
	CLever() {};
	~CLever() {};


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

	void PlayerHit(CPlayer* player);

	void PlayerHitPosHit(CPlayer* player);

	void GolemHit(CGolem* golem);

	void GolemHitPosHit(CGolem* golem);

	bool GetIsChange() { return m_isChange; }

	void SetIsChange(bool flg){m_isChange = flg; }

	void SetIsState(int num) { m_iState = num; }
	//�X�C�b�`�̃t���O
	//bool Get_IsChange() { return Is_Change; }
};