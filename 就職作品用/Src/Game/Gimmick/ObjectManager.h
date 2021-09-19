#pragma once
#include"GimmickManager.h"
#include"../Item/ItemManager.h"
#include"../Exit/ExitManager.h"
#include"../Door/DoorManager.h"
#include"../Item/Zenmai/Zenmai.h"
#include"../../Lib/Singleton.h"


class CObjectManager:public CSingleton<CObjectManager>
{
	friend CSingleton;
private:

	CGimmickManager m_GimmickManager;
	CItemManager m_ItemManager;

	
public:
	CObjectManager() {};
	~CObjectManager() {};

	void Init();//初期化
	void Load();//ロード処理
	void Step();//メイン処理
	void Draw();//描画処理
	void Fin();	//終了処理
};