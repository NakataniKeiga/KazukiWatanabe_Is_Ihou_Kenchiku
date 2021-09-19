#pragma once
#include"DxLib.h"


class CStageBase
{
protected:
	int f_Handl;	//フィールドハンドル

	bool m_isHitFlg;


	int *m_iHandle;

	int *m_iRootHandle;

	int *m_iBoneHandle;

	bool m_isClearFlg;

public:

//コンストラクタ・デストラクタ
	CStageBase() {};
	~CStageBase() {};


	//初期化
	virtual void Init();
	//読み込み
	virtual void Load();
	//描画処理
	virtual void Draw();
	//終了処理
	virtual void Fin();

	bool LoadStageModel(const char* pFileName);
	//クリアフラグ取得
	virtual bool GetIsClear() { return m_isClearFlg; }
	//クリアフラグセット
	virtual void SetIsClear(bool flg) { m_isClearFlg = flg; }

	int GetStageHandle() { return f_Handl; }

	virtual VECTOR GetBone(int NUM, int num) { return VGet(0.0f, 0.0f, 0.0f); }

	virtual VECTOR GetRoot(int NUM, int num) { return VGet(0.0f, 0.0f, 0.0f); }

	virtual int GetRootNum(int NUM) { return 0;}
	

};