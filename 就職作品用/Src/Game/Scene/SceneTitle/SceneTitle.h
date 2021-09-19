#pragma once
//#include"SceneTitle.h"
#include"../SceneManager.h"
#include"../SceneBase.h"

//シーンタイトルクラス
class CSceneTitle :public CSceneBase
{
private:
	int* m_iHndle;
public:
	enum tagGraphics {
		TITLE,
		ENTER,
		GRAPHICS_NUM,
	};

	//コンストラクタ
	CSceneTitle();
	~CSceneTitle();

	int m_iSelectNumber;
	int m_iDrawNumber;

	//初期化
	void Init();
	//ループ
	int Step();
	//描画
	void Draw();
	//後処理
	void Fin();

};