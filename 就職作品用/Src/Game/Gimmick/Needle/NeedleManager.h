#pragma once
#include"Needle.h"
#include"../../Field/StageManager.h"
#include"../GimmickBase.h"

//針の最大数
static const int NEEDLE_MAX = 40;

class CNeedleManager:public CGimmickBase
{
private:

	std::vector<CNeedle*>m_Needle_vec;

public:

	CNeedleManager() ;
	~CNeedleManager() {};

	//初期値
	void Init();
	//モデルロード
	void Load();
	//更新処理
	void Step();
	//更新処理
	void Update();
	//描画
	void Draw();
	//終了
	void Fin();

};