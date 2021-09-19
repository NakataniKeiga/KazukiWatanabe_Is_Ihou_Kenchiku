#pragma once
#include"DxLib.h"
#include"../../Field/StageManager.h"
#include"../../../Lib/Singleton.h"
#include"../StageBase.h"

//座標の総数
const int ROOT_NUM_2 = 4;		// ルートの個数
const int LEVER_POS_2 = 2;	//レーバー
const int WALL_POS_2 = 2;		//壁
const int WALL_MOVE_POS_2 = 2;//壁(目的地)
const int ITEM_POS_2 = 1;		//アイテム
const int EXIT_POS_2 = 1;		//出口
const int BOX_POS_1_2 = 2;		//箱
const int NEEDLE_POS_2 = 23;

const int WALL_2_POS_2 = 1;
const int WALL_2_ROOT_POS_2 = 1;//目的地
const int LEVER_2_POS_2 = 1;

const int DOOR_POS_2 = 1;
const int ZENMAI_POS_2 = 1;

const int GOLEM_POS_2 = 1;

class CField_2 :public CStageBase
{

public:
	//各ギミックのボーン
	enum tagHandeleKind
	{
		HANDLE_ROOT,
		HANDLE_REVER,
		HANDLE_LIFT,
		HANDLE_LIFT_MOVE,
		HANDLE_ITEM,
		HANDLE_EXIT,
		HANDLE_BOX_1,
		HANDLE_NEEDLE,
		
		HANDLE_LIFT_2,
		HANDLE_LIFT_MOVE_2,
		HANDLE_LEVER_2,

		HANDLE_DOOR,
		HANDLE_ZENMAI,

		HANDLE_GOLEMU_2,

		HANDLE_NUM,

	};
	//敵の経路
	enum rootHandleKind
	{
		ROOT_1,
		ROOT_2,

		ROOT_NUM,

	};
private:

	//ステージに設置されたボーン取得
	VECTOR m_vBonePos[HANDLE_NUM][100];
	//ステージに設置された敵の経路ボーン取得
	VECTOR m_vRootPos[ROOT_NUM][50];
	//ルートの番号
	int m_fRoot[10];
	
public:

//コンストラクタ・デストラクタ
	CField_2() { Init(), Load(); };
	~CField_2();

	//初期化
	void Init();
	//読み込み
	void Load();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
	//ステージのギミックボーンの値を返す*/
	VECTOR GetBone(int NUM,int num) { return m_vBonePos[NUM][num]; }
	//ステージの敵の経路ボーンの値を返す
	VECTOR GetRoot(int NUM, int num) { return m_vRootPos[NUM][num]; }
	//経路の個数を取得
	int GetRootNum(int NUM) { return m_fRoot[NUM]; }
	//クリアフラグ取得
	bool GetIsClear() { return m_isClearFlg; }
	//クリアフラグセット
	void SetIsClear(bool flg) { m_isClearFlg = flg; }
};