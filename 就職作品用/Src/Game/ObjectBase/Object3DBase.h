#pragma once
#include"DxLib.h"
#include"list"
#include<vector>

#define PL_RADIUS			( 1.0f )
//オブジェクトクラス
class CObjectBase
{
protected:
	VECTOR m_vPos;    //現在の座標
	VECTOR m_vRot;//回転各
	VECTOR m_vScale;//大きさ
	float m_fRadius;//オブジェクトの半径
	int m_iHndl;//モデルハンドル



//public:
//	//メンバ変数の設定
//	void SetPos(VECTOR pos) { m_vPos = pos; }//現在の座標
//	void SetRot(VECTOR rot) { m_vRot = rot; }//回転角
//
//	
//	void SetRadius(float radius) { m_fRadius = radius; }   //半径
//
//	
//
//	void UpdateGravity() {};
//
//	//メンバ変数の取得
//	VECTOR GetPos() { return m_vPos; }  //現在の座標を返す
//	VECTOR GetRot() { return m_vRot; }//現在の回転角を返す
//
//	VECTOR GetCeneter();
//
//	void ReflecCollision(VECTOR vAddVec); //現在位置に座標加算
//	float GetRadius() { return m_fRadius; }//オブジェトの半径を返す
//
//	//仮想関数
//public:
//	//初期化
//	virtual void Init();
//	//メイン処理
//	virtual void Step();
//	//セット
//	virtual void Update();
//	//描画
//	virtual void Draw();
//	//モデルの削除
//	virtual void DeleteModl();
//	//終了
//	virtual void Fin();
//	//モデルのロード
//	bool LoadModel(const char* pFileName);
//	//モデルのコピー
//	bool DuplicateModel(int iSrcHndl);

};