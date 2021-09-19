#pragma once
#include"DxLib.h"
#include"../Camera/CameraBase.h"

class CPlayCamera:public CCameraBase
{
private:

public:
	//コンストラクタ
	CPlayCamera();

	//初期関数
	void Init();
	//ニア・ファーセット
	void SetNearFar(float nearLength, float farLength);
	//メイン処理
	void Step(VECTOR focus);
	//更新処理
	void Update();

};