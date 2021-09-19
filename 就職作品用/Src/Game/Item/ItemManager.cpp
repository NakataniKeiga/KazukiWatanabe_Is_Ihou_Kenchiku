#include"ItemManager.h"
#include"Key/Key.h"
#include"Zenmai/Zenmai.h"



void CItemManager::Init()
{
	for (auto& item : m_UseItem)
	{
		item->Init();
	}
}


void CItemManager::Step()
{
	for (auto& item : m_UseItem)
	{
		item->Step();
	}
}

void CItemManager::Update()
{
	for (auto& item : m_UseItem)
	{
		item->Update();
	}
}

void CItemManager::Draw()
{
	for (auto& item : m_UseItem)
	{
		item->Draw();
	}
}

void CItemManager::Fin()
{
	for (auto& item : m_UseItem)
	{
		item->Fin();
	}

	m_UseItem.clear();
	
}

void CItemManager::Reqest(tagitem kind)
{
	CStageManager* Stage = CStageManager::GetInstance();

	VECTOR ITEM_POS;

	if (kind == 0)
	{
		//マジックナンバー何とかする
		ITEM_POS = Stage->GetManeBone(4, 0);
	}
	else if(kind==1)
	{
		ITEM_POS = Stage->GetManeBone(12, 0);
	}

	Create(kind ,ITEM_POS);
}

void CItemManager::Create(tagitem kind, VECTOR pos)
{
	


	switch (kind)
	{
	case KEY_ITEM:
	{
		CKey* key;

		key = new CKey;

		key->SetPos(pos);
		key->SetKind(kind);

		m_UseItem.push_back(key);
	}
	break;
	case ZENMAI_ITEM:
	{
		CZenmai* zenmai;

		zenmai = new CZenmai;

		zenmai->SetPos(pos);
		zenmai->SetKind(kind);

		m_UseItem.push_back(zenmai);
	}
		break;
	
	}
}