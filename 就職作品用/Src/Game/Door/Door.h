#pragma once
#include"DxLib.h"
#include"../ObjectBase/Object3DBase.h"
#include"../Character/PlayerAnimation.h"
#include"../Gimmick/GimmickBase.h"


class CDoor :public CGimmickBase
{
private:
	//扉が開いたか判定
	bool m_isOpen;

public:

	CDoor() { Init(); Load(); };
	~CDoor() { Fin(); };

	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
	//扉が開く判定取得
	void GetOpen(bool flg) { m_isOpen = flg; }
	//扉が開く判定セット
	bool SetOpen() { return m_isOpen; }

};