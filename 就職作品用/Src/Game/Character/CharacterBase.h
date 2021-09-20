#pragma once
#include"PlayerAnimation.h"
#include"CharacterCommon.h"
#include"DxLib.h"

#define PL_RADIUS			( 1.0f )

class CCharacterBase
{
protected:
	CAnimation m_Anime;

	VECTOR m_vPos;
	VECTOR m_vRot;
	VECTOR m_vScale;
	VECTOR m_vMove;//移動量
	int m_iHandle;
	float m_fRadius;
	bool m_isAlive;//生存フラグ
	bool m_isActivate;//キャラクターの切り替え用
	bool m_isCall;	//playerなら呼ぶ,golemなら呼ばれる

	VECTOR m_vGravity;//オブジェクトの重力処理
	float m_fGravity;//重力処理

	tagcharacter m_kind;


public:
	//メンバ変数の設定
	void SetPos(VECTOR pos) { m_vPos = pos; }//現在の座標
	void SetRot(VECTOR rot) { m_vRot = rot; }//回転角
	void SetRadius(float radius) { m_fRadius = radius; }   //半径
	void SetHandl(int handl) { m_iHandle = handl; }
	void UpdateGravity() {};
	void ReflecCollision(VECTOR vAddVec); //現在位置に座標加算
	void SetKind(tagcharacter kind) { m_kind = kind; }

	//メンバ変数の取得
	VECTOR GetPos() { return m_vPos; }  //現在の座標を返す
	VECTOR GetRot() { return m_vRot; }//現在の回転角を返す
	VECTOR GetCeneter();
	tagcharacter GetKind() { return m_kind; }
	float GetRadius() { return m_fRadius; }//オブジェトの半径を返す
	int GetHndl() { return m_iHandle; }


	//コンストラクタでアクティブをtrueに
	CCharacterBase() { m_isActivate = true; }
	//現在の移動量を返す
	VECTOR GetMove() { return m_vMove; }
	//切り替え用フラグ取得
	bool GetActivate() { return m_isActivate; }
	//呼び出し用フラグ取得
	bool GetCall() { return m_isCall; }
	//生存フラグ
	bool GetIsAlive() { return m_isAlive; }
	//移動量
	void SetMove(VECTOR move) { m_vMove = move; }
	//呼び出し用フラグセット
	void SetCall(bool flg) { m_isCall = flg; }
	//切り替え用フラグセット
	void SetActivate(bool flg) { m_isActivate = flg; }
	//生存フラグ
	void SetIsAlive(bool isalive) { m_isAlive = isalive; }  

	void SetGravity(VECTOR garavity) { m_vGravity = garavity; }

	void SetfGravity(float gravity) { m_fGravity = gravity; }
	VECTOR GeteGravity() { return m_vGravity; }

	//仮想関数
public:
	//初期化
	virtual void Init();
	//メイン処理
	virtual void Step();
	//セット
	virtual void Update();
	//描画
	virtual void Draw();
	//モデルの削除
	virtual void DeleteModl();
	//終了
	virtual void Fin();

	virtual void Collision() {};
	//モデルのロード
	bool LoadModel(const char* pFileName);
	//モデルのコピー
	bool DuplicateModel(int iSrcHndl);

};