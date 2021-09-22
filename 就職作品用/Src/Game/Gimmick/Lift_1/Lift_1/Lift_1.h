#pragma once
#include"DxLib.h"
#include"../../GimmickBase.h"
#include"../../../ObjectBase/Object3DBase.h"

class CLift_1:public CGimmickBase
{
private:


	enum tagwall
	{
		TYPE_OPEN,//開いている
		TYPE_CLOSE,//閉じている

		TYPE_NUM//総数
	};

	VECTOR m_vLiftPos;
	VECTOR m_vLiftMovePos;
	VECTOR m_vMove;
	bool m_isChange;//閉じている閉じていないか

public:

	CLift_1() {};
	~CLift_1() {};

	//初期化
	void Init();
	//ロード
	void Load();

	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//後処理
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
