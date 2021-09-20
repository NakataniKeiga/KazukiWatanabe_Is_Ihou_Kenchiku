#include"ObjectManager.h"
#include"../Item/ItemCommon.h"
#include"../Gimmick/GimmickCommon.h"
#include"../Collision/CollisionManager.h"


CObjectManager::CObjectManager()
{
	m_GimmickManager = CGimmickManager::GetInstance();
	m_ItemManager = CItemManager::GetInstance();

}

//������
void CObjectManager::Init()
{
	


	m_GimmickManager->Reqest(BOX_GIMMICK);
	m_GimmickManager->Reqest(DOOR_GIMMICK);
	m_GimmickManager->Reqest(LIFT_1_GIMMICK);
	m_GimmickManager->Reqest(LIFT_2_GIMMICK);
	m_GimmickManager->Reqest(LEVER_GIMMICK);
	m_GimmickManager->Reqest(SWITCH_GIMMICK);
	m_GimmickManager->Reqest(NEEDLE_GIMMICK);

	m_ItemManager->Reqest(KEY_ITEM);
	m_ItemManager->Reqest(ZENMAI_ITEM);

m_GimmickManager->Init();
	m_ItemManager->Init();
}
//���[�h����
void CObjectManager::Load()
{
	/*m_GimmickManager.Load();*/
	
}
//���C������
void CObjectManager::Step()
{
	m_GimmickManager->Step();
	m_ItemManager->Step();
	m_GimmickManager->Update();
	m_ItemManager->Update();


}
//�`�揈��
void CObjectManager::Draw()
{
	m_GimmickManager->Draw();
	m_ItemManager->Draw();
	
}

//�I������
void CObjectManager::Fin()
{
	m_GimmickManager->Fin();
	m_ItemManager->Fin();
	
}
