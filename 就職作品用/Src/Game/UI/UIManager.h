#pragma once


#include"UI.h"
#include<list>

class CUIManager
{
private:

	static std::list<CUI*> m_UIList;
public:
	//コンストラクタ
	CUIManager() {};
	~CUIManager() {};

	void Init();//初期化
	void Load();//ロード処理
	void Step();//メイン処理
	void Draw();//描画処理
	void Fin();	//終了処理

	//リストを追加
	void AddUIList(CUI* list);
	//リストの全削除
	void AllDeleteUIList();
	//リストを取得
	static std::list<CUI*> GetCharactorList() { return m_UIList; }

};