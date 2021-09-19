#pragma once
#include<vector>
#include"StageBase.h"
#include"../../Lib/Singleton.h"
#include"../Scene/SceneManager.h"


//ステージマネージャー
class CStageManager: public CSingleton<CStageManager>
{
private:
	friend CSingleton;

public:

private:
	//ステージ番号
	int m_StageNum;
	//ステージクリアフラグ
	bool m_Clearflag;

	CStageBase* m_StageData;

	
//コンストラクタ
	CStageManager();
	~CStageManager() {};
public:
	

	void Init();//初期化
	void Draw();//描画処理
	void Fin();	//終了処理


	//ステージの切り替え
	void ChengeStage();
	//フラグセット
	void SetStageClearFlg(bool flg);
	//ステージ番号セット
	void SetStageNum(int NUM) { m_StageNum = NUM; }
	//ゲームクリアフラグセット
	void SetStageNum(bool flg) { m_Clearflag = flg; }

	//ステージハンドル取得
	int GetHandle();
	//エネミーのボーンの総数を取得
	int GetRootNum(int root_num);
	//ステージ番号取得
	int GetStageNum() { return m_StageNum; }
	//ステージから各ギミックの座標を取得
	VECTOR GetManeBone(int handle_num, int num);
	//ステージのエネミーの移動ボーンを取得
	VECTOR GetRootBone(int root_path,int num);
	//フラグ取得
	bool GetStageClearFlg();
	//ゲームクリアフラグ取得
	bool GetGameClearFlg() { return m_Clearflag; }
	

};


