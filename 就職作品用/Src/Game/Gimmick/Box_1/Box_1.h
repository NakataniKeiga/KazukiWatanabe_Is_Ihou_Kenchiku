#pragma once
#include"DxLib.h"
#include"../GimmickBase.h"
#include"../../ObjectBase/Object3DBase.h"




class CBox_1:public CGimmickBase
{
private:
	VECTOR m_vMove;//移動量

	//箱を持っている判定フラグ
	bool m_isHave;

	VECTOR m_vGravity;//オブジェクトの重力処理
	float m_fGravity;//重力処理
public:

	CBox_1() {};
	~CBox_1() {};

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

	void PlayerHit();

	void SetGravity(VECTOR garavity) { m_vGravity = garavity; }
	void Setgravity(float gravity) { m_fGravity = gravity; }//重力セット

	VECTOR GeteGravity() { return m_vGravity; }

	int GetHndl() { return m_iHndl; }

	float GetPosY() { return m_vPos.y; }

	//現在の移動量を返す
	VECTOR GetMove() { return m_vMove; }
	//移動量
	void SetMove(VECTOR move) { m_vMove = move; }

};