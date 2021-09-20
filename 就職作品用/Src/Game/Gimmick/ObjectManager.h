#pragma once
#include"GimmickManager.h"
#include"../Item/ItemManager.h"
#include"../../Lib/Singleton.h"


class CObjectManager:public CSingleton<CObjectManager>
{
private:
	friend CSingleton;
private:

	CGimmickManager* m_GimmickManager;
	CItemManager* m_ItemManager;

	CObjectManager();
	~CObjectManager() {};
public:
	

	void Init();//初期化
	void Load();//ロード処理
	void Step();//メイン処理
	void Draw();//描画処理
	void Fin();	//終了処理
};