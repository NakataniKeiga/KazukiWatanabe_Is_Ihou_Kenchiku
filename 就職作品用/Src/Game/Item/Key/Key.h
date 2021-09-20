#pragma once
#include"../ItemBase.h"


class CKey :public CItemBase
{
private:
	//鍵フラグ
	bool m_isGetFlg;
public:
	CKey() { Init(); Load(); };
	~CKey() {};
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

	void PlayerHit(CPlayer *player);

	//void HitPlayer(CPlayer* player);
	//鍵フラグ取得
	bool GetIsGet() { return m_isGetFlg; }
};