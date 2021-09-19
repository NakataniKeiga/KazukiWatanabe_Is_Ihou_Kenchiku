#pragma once
#include"../ObjectBase/Object3DBase.h"
#include"../Field/StageManager.h"
#include"ItemCommon.h"


class CItemBase 
{
protected:
	VECTOR m_vPos;    //現在の座標
	VECTOR m_vRot;//回転各
	VECTOR m_vScale;//大きさ
	float m_fRadius;//オブジェクトの半径
	int m_iHndl;//モデルハンドル

	bool m_isAlive;
	tagitem m_kind;
	
public:
	CItemBase() {};
	~CItemBase() {};

	virtual void Init() {};
	//読み込み処理
	virtual void Load() {};

	virtual void Draw() {};
	//メイン処理
	virtual void Step() {};
	//更新処理
	virtual void Update() {};
	//描画処理
	//終了処理
	virtual void Fin() {};



	//メンバ変数の設定
	void SetPos(VECTOR pos) { m_vPos = pos; }//現在の座標
	void SetRot(VECTOR rot) { m_vRot = rot; }//回転角
	void SetRadius(float radius) { m_fRadius = radius; }   //半径
	void SetIsAlive(bool isAlive) { m_isAlive = isAlive; }//生存フラグ
	void SetKind(tagitem kind) { m_kind = kind; }

	//メンバ変数の取得
	VECTOR GetPos() { return m_vPos; }  //現在の座標を返す
	VECTOR GetRot() { return m_vRot; }//現在の回転角を返す
	float GetRadius() { return m_fRadius; }
	bool GetIsAlive() { return m_isAlive; }//生存フラグ
	tagitem GetKind() { return m_kind; }

	

};