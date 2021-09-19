#pragma once
#include"../../ObjectBase/Object3DBase.h"

class CEenmyBase :public CObjectBase
{
protected:


	VECTOR m_vGravity;
	float m_fGravity;


public:

	//初期化
	virtual void Init() {};
	//読み込み処理
	virtual void Load() {};
	//メイン処理
	virtual void Step() {};
	//更新処理
	virtual void Update() {};
	//描画処理
	virtual void Draw() {};
	//終了処理
	virtual void Fin() {};

	void SetPos(VECTOR pos) { m_vPos = pos; }
	void SetRot(VECTOR rot) { m_vRot = rot; }

	void SetRadius(float radius) { m_fRadius = radius; }

	//メンバ変数の取得
	VECTOR GetPos() { return m_vPos; }  //現在の座標を返す
	VECTOR GetRot() { return m_vRot; }//現在の回転角を返す
	float GetRadius() { return m_fRadius; }//オブジェトの半径を返す

};