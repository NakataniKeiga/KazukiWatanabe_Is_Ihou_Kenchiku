#pragma once
#include"DxLib.h"
#include"../SceneBase.h"
#include"../ScenePlay/ScenePlay.h"



class CSceneClear :public CSceneBase
{
public:
	int m_iHndle;

private:
	
	CScenePlay m_selectPlay;
public:
	//コンストラクタ
	CSceneClear() { };
	~CSceneClear();

	//初期化
	void Init();
	//メイン処理
	int Step();
	//描画
	void Draw();
	//終了
	void Fin();

};