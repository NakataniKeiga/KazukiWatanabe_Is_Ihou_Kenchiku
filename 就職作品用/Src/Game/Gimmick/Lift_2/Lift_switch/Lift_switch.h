#pragma once
#include"DxLib.h"
#include"../../GimmickBase.h"
#include"../../../ObjectBase/Object3DBase.h"

class CLift_Switch :public CGimmickBase
{
private:

	enum tagchange
	{
		SWITCH_OFF,
		SWITCH_ON,

		SWITCH_NUM
	};

	int m_State;

	bool IsChange;

public:

	CLift_Switch() {};
	~CLift_Switch() {};

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

	int GetIsState() { return m_State; }
	bool GetIsChange() { return IsChange; }


	void SetChange(bool flg) { IsChange = flg; }
	void SetIsState(int num) { m_State = num; }

};