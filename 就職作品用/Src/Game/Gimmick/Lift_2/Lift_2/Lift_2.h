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

	//初期化
	void Init();
	//ロード
	void Load();
	//セット
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//後処理
	void Fin();

	void PlayerHit(CPlayer* player);

	//現在の移動量を返す
	VECTOR GetMove() { return m_vMove; }
	bool GetIsChange() { return m_isChange; }
	int GetHndl() { return m_iHndl; }
	bool GetIsMove() { return m_isMove; }

	//移動量
	void SetMove(VECTOR move) { m_vMove = move; }
	void SetIsChange(bool flg) { m_isChange = flg; }
	void SetIsMove(bool flg) { m_isMove = flg; }
	void Stage_1SetScale(int number);

};