#pragma once
#include"DxLib.h"
#include"../StageBase.h"

//座標の総数
const int ROOT_NUM = 4;		// ルートの個数
const int LEVER_POS = 2/*12*/;	//レーバー
const int WALL_POS = 2;		//壁
const int WALL_MOVE_POS = 2;//壁(目的地)
const int ITEM_POS = 1;		//アイテム
const int EXIT_POS = 1;		//出口
const int BOX_POS = 3;		//箱
const int NEEDLE_POS = 24;

const int WALL_2_POS = 2;
const int WALL_2_ROOT_POS = 2;//目的地
const int LEVER_2_POS = 2;

const int DOOR_POS = 1;
const int ZENMAI_POS = 1;

const int GOLEM_POS = 1;


class CField_1 :public CStageBase
{
	public:
		enum tagHandleKind
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

			HANDLE_GOLEMU,//ステージ1でしか使わない

			HANDLE_NUM,
		};
		
private:


	//ステージに設置されたボーン取得
	VECTOR m_vBonePos[HANDLE_NUM][100];

	VECTOR m_vRootPos[HANDLE_NUM][100];

	int m_fRoot[100];
public:
//コンストラクタ・デストラクタ
	CField_1() { Init(), Load(); };
	~CField_1();
	//初期化
	void Init();
	//読み込み
	void Load();
	//メイン処理
	void Step();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
	//ステージの各オブジェクトのボーンの値を返す
	VECTOR GetBone(int NUM,int num) { return m_vBonePos[NUM][num]; }
	//ステージの敵の経路ボーンの値を返す
	VECTOR GetRoot(int NUM, int num) { return m_vRootPos[NUM][num]; }
	//クリアフラグ取得
	bool GetIsClear() { return m_isClearFlg; }
	//クリアフラグセット
	void SetIsClear(bool flg) { m_isClearFlg = flg; }
};