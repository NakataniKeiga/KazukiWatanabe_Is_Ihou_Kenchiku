#include"DxLib.h"
#include"Hit.h"


// 球の当たり判定(3D) 　
bool CHit::IsHitSphereToSphere(VECTOR pos1, float size1, VECTOR pos2, float size2)
{
	// まずは2点間の距離を計算
	VECTOR sub = VSub(pos1, pos2);
	// 距離を求めるために2乗する
	// 先ほどの結果をすべて足す
	float sum = VSquareSize(sub);

	// それぞれの本来の半径を足し、2乗する
	float rad = size1 + size2;
	rad *= rad;

	// 半径を足した距離よりも短くなっていたらヒット！
	if (rad > sum) return true;
	else return false;
}


// ボックスの当たり判定
bool CHit::IsHitBoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2)
{
	// 当たり判定用に、中心から端までの距離(半分の距離)を計算
	VECTOR halfSize1, halfSize2;
	halfSize1 = VScale(size1, 0.5f);
	halfSize2 = VScale(size2, 0.5f);

	// X軸での判定
	bool isHitX = pos1.x - halfSize1.x < pos2.x + halfSize2.x
		&& pos1.x + halfSize1.x > pos2.x - halfSize2.x;
	// Y軸での判定
	bool isHitY = pos1.y - halfSize1.y < pos2.y + halfSize2.y
		&& pos1.y + halfSize1.y > pos2.y - halfSize2.y;
	// Z軸での判定
	bool isHitZ = pos1.z - halfSize1.z < pos2.z + halfSize2.z
		&& pos1.z + halfSize1.z > pos2.z - halfSize2.z;
	// 全ての軸で当たっていたら完了
	if (isHitX && isHitY && isHitZ) return true;
	else return false;
}

//矩形の当たり判定
bool CHit::IsHitRect(float x1, float y1, float h1, float w1, float x2, float y2, float h2, float w2)
{
	if (x2 + h2 > x1 &&
		x2 < x1 + h1 &&
		y2 + w2 > y1 &&
		y2 < y1 + w1)
	{
		return true;
	}
	else
		return false;
}

//直方体の当たり判定
bool CHit::IsHitRect3D(VECTOR pos1, VECTOR size1,VECTOR pos2, VECTOR size2)
{
	//xとy座標の矩形の当たり判定を見る
	if (IsHitRect(pos1.x, pos1.y, size1.y, size1.x, pos2.x, pos2.y, size2.y, size2.x) == true)
	{
		//Z軸の当たり判定を見る
		if (pos2.z + size2.z > pos1.z &&
			pos2.z < pos1.z + size1.z)
		{
			return true;
		}
	}
	return false;
}

//直方体の当たり判定　座標が真ん中同士
bool CHit::IsHitRectCenter3D(VECTOR pos1, VECTOR size1, VECTOR sub1, VECTOR pos2, VECTOR size2, VECTOR sub2)
{
	pos1 = VSub(pos1, sub1);
	pos2 = VSub(pos2, sub2);

	//xとy座標の矩形の当たり判定を見る
	if (IsHitRect(pos1.x, pos1.y, size1.x, size1.y, pos2.x, pos2.y, size2.x, size2.y) == true)
	{
		//Z軸の当たり判定を見る
		if (pos2.z + size2.z > pos1.z &&
			pos2.z < pos1.z + size1.z)
		{
			return true;
		}
	}
	return false;
}
