#pragma once
#include"DxLib.h"

class CMenu 
{
public:
	enum tagMenuType	//メニュー画面時の種類
	{
		TYEP_MAP,		//マップ
		TYPE_OPERATUON,	//操作方法
		TYPE_BACK,		//戻る

		TYPE_NUM,		//総数
	};
	
private:
	int* m_iHandle;		//モデルハンドル
	bool m_isMenuflg;			//メニューフラグ
	int m_MenuType;		//メニュータイプの番号
	int m_iStageType;		//ステージの種類を入れるための変数
	VECTOR DrawPlayerPos;	//ミニマップに移すプレイヤーの現在地座標
	VECTOR DrawGolemPos;	//ミニマップに移すゴーレムの現在地座標

public:

	CMenu() {};
	~CMenu() {};
	//フラグ取得
	bool Getflg() { return m_isMenuflg; }
	//フラグセット
	void Setflg(bool flg) { m_isMenuflg = flg; }
	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	void Step();
	//描画処理
	void Draw();
	//終了
	void Fin();
};