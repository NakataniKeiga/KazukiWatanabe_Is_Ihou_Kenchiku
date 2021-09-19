#pragma once
#include"DxLib.h"

class CHit
{
public:	
	//球の当たり判定
	//@pos:当たり判定を行う処理
	static bool IsHitSphereToSphere(VECTOR pos1, float size1, VECTOR pos2, float size2);
	//ボックス当たり判定3D
	static bool IsHitBoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2);

	static bool IsHitRect(float x1, float y1, float h1, float w1, float x2, float y2, float h2, float w2);
	
	static bool IsHitRect3D(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2);

	static bool IsHitRectCenter3D(VECTOR pos1, VECTOR size1, VECTOR sub1, VECTOR pos2, VECTOR size2, VECTOR sub2);
};