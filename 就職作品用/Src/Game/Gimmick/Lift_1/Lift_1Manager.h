#pragma once
#include"Lift_1/Lift_1.h"
#include"Lift_Lever/Lever.h"
#include"../GimmickBase.h"
#include"../../Scene/ScenePlay/ScenePlay.h"


// //ウォールの総数
//static const int LIFT_MAX = 3;



class CLift_1Manager:public CGimmickBase
{
private:

	std::vector<CLift_1*>m_Lift_1_vec;
	std::vector<CLever*>m_Lever_1_vec;
	
	//当たり判定用フラグ
	bool m_isHitFlg;



public:

	CLift_1Manager();
	~CLift_1Manager() {};

	//初期化
	void Init();
	//ロード
	void Load();
	//セット
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//後処理
	void Fin();
	//リフトの移動処理
	void Move();

	//リフトレバーの座標
	VECTOR GetLeverPos(int num);
	//リフトのハンドル取得
	int GetLiftHandle(int num);

};