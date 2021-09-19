#pragma once
#include"DxLib.h"

class CUI
{
protected:

	int* m_iHandle;

public:

	CUI() {};
	~CUI() {};

	virtual void Init() {};//初期化
	virtual void Load() {};//ロード処理
	virtual void Step() {};//メイン処理
	virtual void Draw() {};//描画処理
	virtual void Fin() {};	//終了処理

};