#pragma once
#include"DxLib.h"
#include"../Camera/CameraBase.h"

class CGolemCamera:public CCameraBase
{


public:
	CGolemCamera();
	~CGolemCamera();

	//初期設定
	void Init();
	//ニア・ファーセット
	void SetNeartFar(float m_near,float m_far);
	//メイン処理
	void Step(VECTOR m_focus);
	//更新処理
	void Update();

};
