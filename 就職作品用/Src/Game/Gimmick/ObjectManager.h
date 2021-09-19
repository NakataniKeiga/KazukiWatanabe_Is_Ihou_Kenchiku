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

	void Init();//������
	void Load();//���[�h����
	void Step();//���C������
	void Draw();//�`�揈��
	void Fin();	//�I������
};