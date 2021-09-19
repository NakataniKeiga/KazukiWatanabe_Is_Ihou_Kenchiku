#pragma once
#include"../ItemBase.h"

class CZenmai :public CItemBase
{
private:


public:
	CZenmai() {};
	~CZenmai() {};

	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();


};