#pragma once
#include"../UI.h"

class CGameUI:public CUI
{
private:

	int m_iHp_x[20];		//体力座標
	int m_iHp_y;			//体力座標
public:

	CGameUI() {};
	~CGameUI() {};
	//モデルハンドル

	


	void Init();//初期化
	void Load();//ロード処理
	void Draw();//描画処理
	void Fin();	//終了処理
};