#pragma once
#include"../UI.h"
class CMapUI:public CUI
{
private:
	VECTOR m_vDrawPos;

	//マップの表示用フラグ
	bool m_isMapflg;

public:

	void Init();//初期化
	void Load();//ロード処理
	void Step();//メイン処理
	void Draw();//描画処理
	void Fin();	//終了処理

};