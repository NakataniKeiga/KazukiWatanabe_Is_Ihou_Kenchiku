#pragma once
#include"DxLib.h"
#include"../../ObjectBase/Object3DBase.h"
#include"../../Gimmick/GimmickBase.h"
#include"../../Character/Player/Player.h"


class CNeedle:public CGimmickBase
{
private:

	bool m_isChange;			//レバーフラグ

public:

	CNeedle() { Init(), Load(); };
	~CNeedle() { Fin(); };

	//初期化
	void Init();
	//モデルのロード
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	void PlayerHit(CPlayer* player);

	void PlayerHitPosHit(CPlayer* player);

	void GolemHit(CGolem* golem);

	void GolemHitPosHit(CGolem* golem);

	//ハンドル取得
	int GetHndl() { return m_iHndl; }
	//レバーのフラグ取得
	bool GetIsChange() { return m_isChange; }
	//レバーのフラグセット
	void SetIsChange(bool flg) { m_isChange = flg; }
	
	VECTOR GetCeneter();
};
