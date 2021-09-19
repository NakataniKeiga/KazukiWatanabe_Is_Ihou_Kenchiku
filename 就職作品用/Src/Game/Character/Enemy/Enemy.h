#pragma once
#include"DxLib.h"
#include"EnemyBase.h"
#include"../PlayerAnimation.h"




class CEnemy :public CEenmyBase
{
private:
	enum tagenemy
	{
		STATE_CHASE=2,//追いかける

		STATE_NUM,  //総数
	};


	tagenemy m_state;

	bool m_isChase;

public:

	CEnemy() { Init(), Load(); }
	~CEnemy() { Fin(); };
	//初期化
	void Init();
	//ロード処理
	/*ここでうけとったボーンの座標を入れてあげる*/
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	VECTOR GetAttackPos();

	bool GetChace() { return m_isChase; }

};