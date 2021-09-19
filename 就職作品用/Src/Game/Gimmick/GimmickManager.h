#pragma once

//#include"Lift_1/Lift_1Manager.h"
//#include"Box_1/Box_1Manager.h"
//#include"Needle/NeedleManager.h"
//#include"Lift_2/Lift_2Manager.h"

#include"GimmickBase.h"
#include"GimmickCommon.h"
#include<list>
#include"../../Lib/Singleton.h"

class CGimmickManager:public CSingleton<CGimmickManager>
{
private:
	friend CSingleton;

private:
	std::list<CGimmickBase*>m_PoolGimmick;
	std::list<CGimmickBase*>m_UseGimmick;

	int m_Handle[GIMMICK_NUM];

	CGimmickManager() {};
	~CGimmickManager() {};

public:
	
	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	void Reqest(taggimmick kind);

	void Create(taggimmick kind, VECTOR pos);

	std::list<CGimmickBase*>GetUsePool() { return m_UseGimmick; }
};