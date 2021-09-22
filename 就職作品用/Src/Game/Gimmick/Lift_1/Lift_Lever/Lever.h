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
		SWITCH_OFF,//スイッチOFF
		SWITCH_ON,//スイッチON

		SWITCH_NUM//総数
	};
	

	VECTOR m_vLeverPos;
	int m_iState;
	//レバー座標の数
	bool m_isChange;

public:
	CLever() {};
	~CLever() {};


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

	void PlayerHitPosHit(CPlayer* player);

	void GolemHit(CGolem* golem);

	void GolemHitPosHit(CGolem* golem);

	bool GetIsChange() { return m_isChange; }

	void SetIsChange(bool flg){m_isChange = flg; }

	void SetIsState(int num) { m_iState = num; }
	//スイッチのフラグ
	//bool Get_IsChange() { return Is_Change; }
};