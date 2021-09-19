#pragma once
#include"DxLib.h"
#include"SceneBase.h"
#include"../Common.h"

class CSceneBase;

//シーンマネージャー
class CSceneManager
{
private:

// 各シーンの流れ
	// 基本的にどのシーンもこの流れだけで動くようにする
	// さらに流れを増やしたい場合は、各シーンのStep内で増やす
	enum tagState{
		STATEID_INIT,
		STATEID_STEP,
		STATEID_FIN,

		STATEID_NUM

	};

	CSceneBase* m_Base;									// 各シーンを格納
	int m_iState;										// 現在の状態
	int m_iNextstate;									// 次に移動するシーン
	void (CSceneManager::* m_iScene[STATEID_NUM])();	// シーンを関数ポインタで管理するためのもの

public:
	
	void CreateScene();

public:
	//コンストラクタ・デストラクタ
	CSceneManager();
	~CSceneManager();
	//ループ処理
	int Loop();
	//描画処理
	void Draw();

private:
	//初期化
	void Init();
	//メイン処理
	void Step();
	//後処理
	void Fin();
};