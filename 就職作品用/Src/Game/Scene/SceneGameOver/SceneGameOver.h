#pragma once
#include"../SceneBase.h"
#include"../SceneManager.h"

class CSceneGameOver :public CSceneBase
{
private:
	int* m_iHndle;

public:
	CSceneGameOver();
	~CSceneGameOver();



	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	int Step();
	//描画
	void Draw();
	//終了
	void Fin();


};