#pragma once
#include"DxLib.h"

class CDebugCamera {
private:
	VECTOR m_vPos;
	VECTOR m_vRot;
	float m_near, m_far;

public:
	//コンストラクタ
	CDebugCamera();

	//初期関数
	void Init();
	//ニア・ファーセット
	void SetNearFar(float nearLength,float farLength);
	//メイン処理
	void Step(VECTOR focus,float rotY);
	//更新処理
	void Update();
	//描画処理
	void Draw();

	// 座標と角度をセット
	void SetPosition(VECTOR pos) { m_vPos = pos; }
	void SetRotation(VECTOR rot) { m_vRot = rot; }


};