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

	int GetIsState() { return m_State; }
	bool GetIsChange() { return IsChange; }


	void SetChange(bool flg) { IsChange = flg; }
	void SetIsState(int num) { m_State = num; }

};