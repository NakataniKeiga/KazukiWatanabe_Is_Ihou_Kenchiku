#include"UIManager.h"
#include"../UI/GameUI/GameUI.h"
#include"MapUI/MapUI.h"

//静的変数を定義
std::list<CUI*> CUIManager::m_UIList;

//初期化
void CUIManager::Init()
{
	//リストに追加する
	AddUIList(new CGameUI);
	AddUIList(new CMapUI);

	for (auto it : m_UIList)
	{
		it->Init();
	}
	Load();
}
//ロード
void CUIManager::Load()
{
	for (auto it : m_UIList)
	{
		it->Load();
	}
}
//メイン処理
void CUIManager::Step()
{
	for (auto it : m_UIList)
	{
		it->Step();
	}
}

//描画処理
void CUIManager::Draw()
{
	for (auto it : m_UIList)
	{
		it->Draw();
	}
}
//終了処理
void CUIManager::Fin()
{
	AllDeleteUIList();
}
//リストを追加
void CUIManager::AddUIList(CUI* list)
{
	m_UIList.push_back(list);
}

//リストの全削除
void CUIManager::AllDeleteUIList()
{
	for (auto it : m_UIList)
	{
		delete it;
	}

	m_UIList.clear();
}