#include"UIManager.h"
#include"../UI/GameUI/GameUI.h"
#include"MapUI/MapUI.h"

//�ÓI�ϐ����`
std::list<CUI*> CUIManager::m_UIList;

//������
void CUIManager::Init()
{
	//���X�g�ɒǉ�����
	AddUIList(new CGameUI);
	AddUIList(new CMapUI);

	for (auto it : m_UIList)
	{
		it->Init();
	}
	Load();
}
//���[�h
void CUIManager::Load()
{
	for (auto it : m_UIList)
	{
		it->Load();
	}
}
//���C������
void CUIManager::Step()
{
	for (auto it : m_UIList)
	{
		it->Step();
	}
}

//�`�揈��
void CUIManager::Draw()
{
	for (auto it : m_UIList)
	{
		it->Draw();
	}
}
//�I������
void CUIManager::Fin()
{
	AllDeleteUIList();
}
//���X�g��ǉ�
void CUIManager::AddUIList(CUI* list)
{
	m_UIList.push_back(list);
}

//���X�g�̑S�폜
void CUIManager::AllDeleteUIList()
{
	for (auto it : m_UIList)
	{
		delete it;
	}

	m_UIList.clear();
}