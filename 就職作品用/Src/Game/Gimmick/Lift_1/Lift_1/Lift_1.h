#pragma once
#include"DxLib.h"
#include"../../GimmickBase.h"
#include"../../../ObjectBase/Object3DBase.h"

class CLift_1:public CGimmickBase
{
private:


	enum tagwall
	{
		TYPE_OPEN,//�J���Ă���
		TYPE_CLOSE,//���Ă���

		TYPE_NUM//����
	};

	VECTOR m_vLiftPos;
	VECTOR m_vLiftMovePos;
	VECTOR m_vMove;
	bool m_isChange;//���Ă�����Ă��Ȃ���

public:

	CLift_1() {};
	~CLift_1() {};

	//������
	void Init();
	//���[�h
	void Load();

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

	int  GetHndl() { return m_iHndl; }

	bool GetIsChange() { return m_isChange; }

	VECTOR GetMove() { return m_vMove; }

	void SetIsChange(bool flg) { m_isChange = flg; }

	void SetMove(VECTOR move) { m_vMove = move; }

	void Stage_1SetScale(int number);

	void Stage_2SetScale(int number);

};
