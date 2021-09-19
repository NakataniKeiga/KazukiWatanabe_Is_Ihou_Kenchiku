#pragma once
#include"Box_1.h"
#include"../GimmickBase.h"
#include <vector>
class CCollisionManager;
class CStageManager;
static const int BOX_MAX = 3;
//static const int BOX_NUM[3] = { 3,1,0 };

class CBox_1Manager:public CGimmickBase
{
private:

	//ボックスのデータをもって来やすくするためVecterではない
	CBox_1* m_Box;

public:
	CBox_1Manager() ;
	~CBox_1Manager() {};

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

	CBox_1* GetBoxData() { return m_Box; }
	//箱の番号取得
	//int GetBoxNum(int num) { return BOX_NUM[num]; }


};