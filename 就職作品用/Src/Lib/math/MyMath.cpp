#include "MyMath.h"
#include <math.h>

//引数のベクトルのx,y,zの指定された座標以外を
//0にして返す関数	X=0,Y=1,Z=2
VECTOR MyMath::VecToZeros(VECTOR vec, int num) {
	VECTOR result = vec;
	if (num == 0) {	//　X以外を0にする
		result.y = 0.f;
		result.z = 0.f;
	}
	if (num == 1) {	//　Y以外を0にする
		result.x = 0.f;
		result.z = 0.f;
	}
	if (num == 2) {	//　Z以外を0にする
		result.y = 0.f;
		result.x = 0.f;
	}

	return result;
}
//ベクトルの要王がすべて0か返す（0の場合にtrue）
bool MyMath::CheckVecAllZero(VECTOR vec) {
	if (vec.x != 0.f) { return false; }
	if (vec.y != 0.f) { return false; }
	if (vec.z != 0.f) { return false; }
	return true;
}

//2つのベクトルを比較して同じかどうかを返す
bool MyMath::VecSame(VECTOR vec1, VECTOR vec2) {
	if (vec1.x != vec2.x) { return false; }
	if (vec1.y != vec2.y) { return false; }
	if (vec1.z != vec2.z) { return false; }
	return true;
}
//2点間の距離を返す
float MyMath::GetDistance(VECTOR posA, VECTOR posB){
	float x = posB.x - posA.x;
	float y = posB.y - posA.y;
	float z = posB.z - posA.z;

	return sqrtf(x * x + y * y + z * z);
}
float MyMath::GetDistance(float x1, float y1, float z1, float x2, float y2, float z2) {
	// 点Pから点Qまでの直線を斜辺とする直角三角形を作り、
	// ピタゴラスの定理から斜辺の長さを計算する。
	float x = x2 - x1;
	float y = y2 - y1;
	float z = z2 + z1;
	float double_c = x * x + y * y + z * z;

	return sqrtf(double_c);
}
//回転値を0～2πの値にする
float MyMath::RadianNormalize(float rad) {
	float result = rad;
	if (result < 0.0f) {
		while (result < 0.0f) { result += DX_TWO_PI_F; }
	}
	else if (result > DX_TWO_PI_F) {
		while (result <= DX_TWO_PI_F) { result -= DX_TWO_PI_F; }
	}

	return result;
}
//ディグリー角をラジアン角へ変換
float MyMath::ChangeRadian(float Deg) {
	float result;
	result = Deg * DX_PI_F / 180.f;
	return result;
}
//ラジアン角をディグリー角へ変換
float MyMath::ChangeDegree(float Rad) {
	float result;
	result = Rad * 180.f / DX_PI_F;
	return result;
}
// 始点と終点からベクトルを作成
VECTOR MyMath::VecCreate(VECTOR vPosA, VECTOR vPosB){
	VECTOR result;
	result.x = vPosB.x - vPosA.x;
	result.y = vPosB.y - vPosA.y;
	result.z = vPosB.z - vPosA.z;
	return result;
}
//Y座標を0にしたベクトルを返す
VECTOR MyMath::GetYNoVec(VECTOR vec) {
	VECTOR result = vec;
	result.y = 0.f;
	return result;
}

// ベクトルの長さ
float MyMath::VecLong(VECTOR PosA, VECTOR PosB){
	float result;
	result = sqrtf((PosA.x - PosB.x) * (PosA.x - PosB.x) + (PosA.y - PosB.y) * (PosA.y - PosB.y) + (PosA.z - PosB.z) * (PosA.z - PosB.z));
	return result;
}
float MyMath::VecLong(VECTOR Pos) {
	float result;
	result = VecLong(Pos, VGet(0.f, 0.f, 0.f));
	return result;
}

//ベクトル＋ベクトル
VECTOR MyMath::VecAdd(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.x + vecB.x;
	result.y = vecA.y + vecB.y;
	result.z = vecA.z + vecB.z;

	return result;
}
//ベクトル－ベクトル
VECTOR MyMath::VecSub(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.x - vecB.x;
	result.y = vecA.y - vecB.y;
	result.z = vecA.z - vecB.z;

	return result;

}
//ベクトル÷スカラー値
VECTOR MyMath::VecDiv(VECTOR vec, float num) {
	VECTOR result = { 0 };
	result.x = vec.x / num;
	result.y = vec.y / num;
	result.z = vec.z / num;

	return result;
}
//ベクトル×スカラー倍
VECTOR MyMath::VecScale(VECTOR vec, float scale){
	VECTOR result;
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}
//ベクトルの内積
float MyMath::VecDot(VECTOR vecA, VECTOR vecB){
	float result;
	result = vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
	return result;
}
//ベクトルの外積
VECTOR MyMath::VecCross(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.y * vecB.z - vecA.z * vecB.y;
	result.y = vecA.z * vecB.x - vecA.x * vecB.z;
	result.z = vecA.x * vecB.y - vecA.y * vecB.x;
	return result;
}
//ベクトルの内積から角度を計算
float MyMath::VecDotRot(VECTOR origin, VECTOR vecA, VECTOR vecB) {
	//計算角度
	float result_rot;
	//原点からの座標に変更
	VECTOR vecA_a = VecSub(vecA, origin);
	VECTOR vecB_b = VecSub(vecB, origin);
	//各座標の長さを計算
	float vecA_long = VecLong(vecA_a);
	float vecB_long = VecLong(vecB_b);
	//内積を計算
	float dot = VecDot(vecA_a, vecB_b);
	//角度計算
	result_rot = dot / (vecA_long * vecB_long);
	result_rot = acosf(result_rot);

	return result_rot;
}

// ベクトルの向きをラジアン値で取得
float MyMath::VecDir(VECTOR vec){
	return atan2f(vec.y, vec.x);
}
//引数のベクトルの各角度を計算してベクトルで返す
VECTOR MyMath::GetVecRot(VECTOR vec) {
	VECTOR result;
	result.x = atan2f(vec.y, vec.z);
	result.y = atan2f(vec.x, vec.z);
	result.z = atan2f(vec.y, vec.x);

	return result;
}

//向きベクトルの取得（角度、移動量）
VECTOR MyMath::GetSpeed(float rot, float move_speed) {
	MATRIX yaw_mat = GetYawMatrix(rot);
	MATRIX move_mat = GetTranslateMatrix(move_speed, 0.f, 0.f);
	MATRIX result_mat = MatMult(yaw_mat, move_mat);
	VECTOR result = GetTranslateVector(result_mat);
	return result;
}
//ベクトルの正規化
VECTOR MyMath::VecNormalize(VECTOR vec){
	float size;
	VECTOR result;
	size = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	size = sqrtf(size);
	result.x = vec.x / size;
	result.y = vec.y / size;
	result.z = vec.z / size;
	return result;
}
//ベクトルを回転させる
VECTOR MyMath::VecRotation(VECTOR vec, VECTOR rotation) {
	MATRIX rotation_mat = GetRotationMatrix(rotation);

	VECTOR result = MyMath::MatTransform(rotation_mat, vec);

	return result;
}
//単位行列の取得
MATRIX MyMath::GetldentityMatrix(){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++)	{
		for(int j = 0; j < 4; j++){
			if(i == j){
				result.m[i][j] = 1;
			}
			else{
				result.m[i][j] = 0;
			}
		}
	}

	return result;
}

//MATRIXのVECTOR化
VECTOR MyMath::GetTranslateVector(MATRIX mat) {
	VECTOR result = { 0 };
	result.x = mat.m[0][3];
	result.y = mat.m[1][3];
	result.z = mat.m[2][3];
	return result;
}
//移動行列の取得
MATRIX MyMath::GetTranslateMatrix(float x, float y, float z)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][3] = x;
	result.m[1][3] = y;
	result.m[2][3] = z;

	return result;
}
MATRIX MyMath::GetTranslateMatrix(VECTOR trans){
	return GetTranslateMatrix(trans.x, trans.y, trans.z);
}
//拡縮行列の取得
MATRIX MyMath::GetScaleMatrix(float x, float y, float z){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = x;
	result.m[1][1] = y;
	result.m[2][2] = z;

	return result;
}
MATRIX MyMath::GetScaleMatrix(VECTOR trans){
	return GetScaleMatrix(trans.x, trans.y, trans.z);
}
//X軸回転行列の取得
MATRIX MyMath::GetPitchMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[1][1] = cosf(rot);
	result.m[1][2] = -sinf(rot);
	result.m[2][1] = sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}
//Y軸回転行列の取得
MATRIX MyMath::GetYawMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][2] = sinf(rot);
	result.m[2][0] = -sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}
//Z軸回転行列の取得
MATRIX MyMath::GetRollMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][1] = -sinf(rot);
	result.m[1][0] = sinf(rot);
	result.m[1][1] = cosf(rot);

	return result;
}
//回転行列を取得
MATRIX MyMath::GetRotationMatrix(VECTOR rotation) {
	MATRIX move_z = MyMath::GetRollMatrix(rotation.z);
	MATRIX move_y = MyMath::GetYawMatrix(rotation.y);
	MATRIX move_x = MyMath::GetPitchMatrix(rotation.x);
	
	MATRIX result = MyMath::MatMult(move_z, move_y);
	result = MyMath::MatMult(result, move_x);

	return result;
}
//Y軸回転の座標を半径と角度を渡して取得
VECTOR MyMath::GetYawPosition(float radius, float rot) {
	VECTOR result = { 0 };
	//移動行列を取得
	MATRIX result_mat_a = GetTranslateMatrix(radius, 0.f, 0.f);
	//Y軸座標の回転行列の取得
	MATRIX result_mat_b = GetYawMatrix(rot);
	//計算結果を行列で取得
	MATRIX result_mat = MatMult(result_mat_b, result_mat_a);
	//計算結果行列をヴェクトルに変換
	result = GetTranslateVector(result_mat);
	
	return result;
}

//行列＋行列
MATRIX MyMath::MatAdd(MATRIX matA, MATRIX matB){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = matA.m[i][j] + matB.m[i][j];
		}
	}

	return result;
}
//行列－行列
MATRIX MyMath::MatSub(MATRIX matA, MATRIX matB) {
	MATRIX result = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = matA.m[i][j] - matB.m[i][j];
		}
	}

	return result;
}

//行列×行列
MATRIX MyMath::MatMult(MATRIX matA, MATRIX matB){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				result.m[i][j] += (matA.m[i][k] * matB.m[k][j]);
			}
		}
	}

	return result;
}
//行列×スカラー値
MATRIX MyMath::MatScale(MATRIX mat, float scale){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = mat.m[i][j] * scale;
		}
	}

	return result;
}
//ベクトル×行列
VECTOR MyMath::MatTransform(MATRIX mat, VECTOR vec){
	float work[4] = { 0 };
	float result_buf[4] = { 0 };
	VECTOR result_vec = { 0 };
	work[0] = vec.x;
	work[1] = vec.y;
	work[2] = vec.z;
	work[3] = 1;
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			result_buf[i] += (mat.m[i][k] * work[k]);
		}
	}

	result_vec.x = result_buf[0];
	result_vec.y = result_buf[1];
	result_vec.z = result_buf[2];

	return result_vec;
}
//行列の転置
MATRIX MyMath::MatTranspose(MATRIX mat){
	MATRIX result = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = mat.m[i][j];
		}
	}

	return result;
}
//ポリゴンの法線ベクトル
VECTOR MyMath::GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	VECTOR vecABAC = VecCross(vecAB, vecAC);
	return VecNormalize(vecABAC);
}
//クオータニオン同士の掛け算
Quaternion MyMath::QuaternionMult(Quaternion quaA, Quaternion quaB) {
	float w1 = quaA.w, w2 = quaB.w;
	VECTOR v1 = { quaA.x,quaA.y ,quaA.z }, v2 = { quaB.x,quaB.y ,quaB.z };

	float result_w = w1 * w2 - VecDot(v1, v2);
	VECTOR result_v = VAdd(VAdd(VecScale(v2, w1), VecScale(v1, w2)), VecCross(v1, v2));

	Quaternion result;
	result.w = result_w;
	result.x = result_v.x;
	result.y = result_v.y;
	result.z = result_v.z;

	return result;
}
float MyMath::GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// 辺に沿ったベクトルABとACを計算
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// 面法線を計算
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// 平面の方程式から高さ（Y座標を計算）
	float z = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.y * (point.y - vertexA.y) + vecNorm.z * vertexA.z) / vecNorm.z;

	return z;
}

float MyMath::GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// 辺に沿ったベクトルABとACを計算
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// 面法線を計算
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// 平面の方程式から高さ（Y座標を計算）
	float y = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.z * (point.z - vertexA.z) + vecNorm.y * vertexA.y) / vecNorm.y;

	return y;
}

float MyMath::GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// 辺に沿ったベクトルABとACを計算
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// 面法線を計算
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// 平面の方程式から高さ（Y座標を計算）
	float x = (-vecNorm.y * (point.y - vertexA.y) - vecNorm.z * (point.z - vertexA.z) + vecNorm.x * vertexA.x) / vecNorm.x;

	return x;
}

float MyMath::Abs(float val)
{
	if (val < 0.0f) {
		return -val;
	}
	return val;
}

