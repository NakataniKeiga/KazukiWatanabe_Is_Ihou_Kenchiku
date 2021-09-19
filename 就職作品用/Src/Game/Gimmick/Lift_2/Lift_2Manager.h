
#pragma once
#include"Lift_2/Lift_2.h"
#include"Lift_switch/Lift_switch.h"
#include"../Box_1/Box_1.h"
#include"../GimmickBase.h"

//static const int LIFT_2_MAX = 15;


class CLift_2Manager:public CGimmickBase
{
private:

	std::vector<CLift_2*>m_Lift_2_vec;
	std::vector<CLift_Switch*>m_Lever_Switch_vec;


public:

	CLift_2Manager();
	~CLift_2Manager() {};

	//初期化
	void Init();
	//ロード
	void Load();
	//セット
	void Step(CBox_1* Box,int BoxNum);
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
	//リフトの移動処理
	void Move();
	//箱との当たり判定
	VECTOR GetLeverPos(int num);

};