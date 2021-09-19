#pragma once
#include "DxLib.h"

//角度
#define DX_PI_F_HALF (DX_PI_F / 2.f)
#define DX_PI_F_HALF_HALF (DX_PI_F / 4.f)

// Quaternion構造体
struct Quaternion {
	float w;
	float x;
	float y;
	float z;
};

//ベクトルや行列の計算処理をまとめたクラス
//授業でやった数学を関数化したもの
class MyMath{
public:
	//引数のベクトルのx,y,zの指定された座標以外を
	//0にして返す関数	X=0,Y=1,Z=2
	static VECTOR VecToZeros(VECTOR vec, int num);
	//ベクトルの要王がすべて0か返す（0の場合にtrue）
	static bool CheckVecAllZero(VECTOR vec);
	//2つのベクトルを比較して同じかどうかを返す
	static bool VecSame(VECTOR vec1, VECTOR vec2);
	//2点間の距離を返す
	static float GetDistance(float x1, float y1, float z1, float x2, float y2, float z2);
	static float GetDistance(VECTOR posA, VECTOR posB);
	//回転値を0～2πの値にする
	static float RadianNormalize(float rad);
	//ディグリー角をラジアン角へ変換
	static float ChangeRadian(float Deg);
	//ラジアン角をディグリー角へ変換
	static float ChangeDegree(float Rad);
	// 始点と終点からベクトルを作成
	static VECTOR VecCreate(VECTOR PosA, VECTOR PosB);
	//Y座標を0にしたベクトルを返す
	static VECTOR GetYNoVec(VECTOR vec);
	// ベクトルの長さ
	static float VecLong(VECTOR PosA, VECTOR PosB);
	static float VecLong(VECTOR Pos);	//片方のベクトルを原点としたときの長さ計算
	//ベクトル＋ベクトル
	static VECTOR VecAdd(VECTOR vecA, VECTOR vecB);
	//ベクトル－ベクトル
	static VECTOR VecSub(VECTOR vecA, VECTOR vecB);
	//ベクトル÷スカラー値
	static VECTOR VecDiv(VECTOR vec, float num);
	//ベクトル×スカラー倍
	static VECTOR VecScale(VECTOR vec, float scale);
	//ベクトルの内積
	static float VecDot(VECTOR vecA, VECTOR vecB);
	//ベクトルの外積
	static VECTOR VecCross(VECTOR vecA, VECTOR vecB);
	//ベクトルの内積から角度を計算
	//origin = 原点となる座標
	//vecA、vecB = 原点を介してできる角度の座標
	static float VecDotRot(VECTOR origin, VECTOR vecA, VECTOR vecB);
	// ベクトルの向きをラジアン値で取得
	static float VecDir(VECTOR vec);
	//引数のベクトルの各角度を計算してベクトルで返す
	static VECTOR GetVecRot(VECTOR vec);
	//向きベクトルの取得（Y軸角度、移動量）
	static VECTOR GetSpeed(float rot, float move_speed);
	//ベクトルの正規化
	static VECTOR VecNormalize(VECTOR vec);
	//ベクトルを回転させる
	static VECTOR VecRotation(VECTOR vec, VECTOR rotation);
	//単位行列の取得
	static MATRIX GetldentityMatrix();
	//MATRIX→VECTOR
	static VECTOR GetTranslateVector(MATRIX mat);
	//移動行列の取得
	static MATRIX GetTranslateMatrix(float x, float y, float z);
	static MATRIX GetTranslateMatrix(VECTOR trans);
	//拡縮行列の取得
	static MATRIX GetScaleMatrix(float x, float y, float z);
	static MATRIX GetScaleMatrix(VECTOR trans);
	//X軸回転行列の取得(ラジアン角)
	static MATRIX GetPitchMatrix(float rot);
	//Y軸回転行列の取得(ラジアン角)
	static MATRIX GetYawMatrix(float rot);
	//Z軸回転行列の取得(ラジアン角)
	static MATRIX GetRollMatrix(float rot);
	//回転行列を取得
	static MATRIX GetRotationMatrix(VECTOR rotation);
	//Y軸回転の座標を半径と角度を渡して取得
	static VECTOR GetYawPosition(float radius, float rot);
	//行列＋行列
	static MATRIX MatAdd(MATRIX matA, MATRIX matB);
	//行列－行列
	static MATRIX MatSub(MATRIX matA, MATRIX matB);
	//行列×行列
	static MATRIX MatMult(MATRIX matA, MATRIX matB);
	//行列×スカラー値
	static MATRIX MatScale(MATRIX mat, float scale);
	//ベクトル×行列
	static VECTOR MatTransform(MATRIX mat, VECTOR vec);
	//行列の転置
	static MATRIX MatTranspose(MATRIX mat);
	//ポリゴンの法線ベクトル
	static VECTOR GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float Abs(float val);
	//クオータニオン同士の掛け算
	static Quaternion QuaternionMult(Quaternion quaA, Quaternion quaB);
};
