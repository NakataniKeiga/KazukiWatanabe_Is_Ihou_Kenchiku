#pragma once
#include"DxLib.h"
#include"../../GimmickBase.h"
#include"../../../ObjectBase/Object3DBase.h"

class CLift_2 :public CGimmickBase
{
private:

	VECTOR m_vMove;
	bool m_isChange;
	bool m_isMove;


public:

	CLift_2() {};
	~CLift_2() {};

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

	//���݂̈ړ��ʂ�Ԃ�
	VECTOR GetMove() { return m_vMove; }
	bool GetIsChange() { return m_isChange; }
	int GetHndl() { return m_iHndl; }
	bool GetIsMove() { return m_isMove; }

	//�ړ���
	void SetMove(VECTOR move) { m_vMove = move; }
	void SetIsChange(bool flg) { m_isChange = flg; }
	void SetIsMove(bool flg) { m_isMove = flg; }
	void Stage_1SetScale(int number);

};