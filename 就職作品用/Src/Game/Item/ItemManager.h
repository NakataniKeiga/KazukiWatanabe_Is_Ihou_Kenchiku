#pragma once
#include"ItemBase.h"
#include"ItemCommon.h"
#include"../../Lib/Singleton.h"
#include<list>

class CItemManager: public CSingleton<CItemManager>
{
private:
	friend CSingleton;

private:


	std::list<CItemBase*>m_UseItem;//いま使っているデータプール

	int m_Handle[ITEM_NUM];



public:
	CItemManager() {};
	~CItemManager() {};


	//初期化
	void Init();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	void Reqest(tagitem kind);

	void Create(tagitem kind,VECTOR pos);

	std::list<CItemBase*>GetUsePool() { return m_UseItem; }
};