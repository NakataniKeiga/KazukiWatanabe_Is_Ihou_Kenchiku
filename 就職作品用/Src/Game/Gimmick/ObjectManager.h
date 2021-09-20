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
	

	void Init();//������
	void Load();//���[�h����
	void Step();//���C������
	void Draw();//�`�揈��
	void Fin();	//�I������
};