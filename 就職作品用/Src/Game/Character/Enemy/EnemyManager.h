#pragma once
#include"Enemy.h"
#include"../../../Lib/Singleton.h"

static const int ENEMY_MAX = 2;

class CEnemyManager:public CSingleton<CEnemyManager> {

	friend CSingleton;
private:
	
	std::vector<CEnemy*>m_Enemy_vec;

	int m_iStageType;//ステージタイプ入れる

	int m_iRootID[ENEMY_MAX];

public:

	CEnemyManager();
	~CEnemyManager() {};

	//初期化
	void Init();
	//ロード
	void Load();
	//セット
	void Step();
	//移動
	void Move();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//後処理
	void Fin();

};