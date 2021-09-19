#include"DxLib.h"

static const int FRAME_RATE = 60;								// 1秒辺りのフレーム数
static const int FRAME_RATE_MILLI_SECOND = 1000 / FRAME_RATE;	// 何ミリ秒で1フレームか

// フレームレート管理用構造体
typedef struct {
	double m_frameRate;			// フレームレート(画面表示用)
	int m_count;				// フレーム数カウント(画面表示用)
	int m_updateFrameRateTime;	// フレームレート更新時間(画面表示用)
	int m_currentTime;			// 現在のPC時間
	int m_lastTime;				// 1フレーム前のPC時間
}FrameData;

// グローバル変数として管理
static FrameData g_frame = { 0.0 };



//-------------------------------
//		フレームレート初期化
//-------------------------------
void InitFrameRate()
{
	// データを全て初期化しておく
	g_frame.m_count = 0;
	g_frame.m_frameRate = 0.0;
	g_frame.m_currentTime = GetNowCount();
	g_frame.m_lastTime = g_frame.m_currentTime;	// とりあえず同じ値を格納
	g_frame.m_updateFrameRateTime = g_frame.m_currentTime;
}


//-------------------------------
//		フレームを進めていいか判断
//-------------------------------
bool CheckFrameRate()
{
	// 現在の時間を取得する
	g_frame.m_currentTime = GetNowCount();
	// 前回の時間から今回までの差分を計算
	int difTime = g_frame.m_currentTime - g_frame.m_lastTime;

	// 前回の時間から指定したフレーム分経過しているかチェック
	if (difTime >= FRAME_RATE_MILLI_SECOND) return true;
	else return false;
}


//-------------------------------
//		フレームレート計算
//-------------------------------
void CalcFrameRate()
{
	// 前回時間を更新
	g_frame.m_lastTime = g_frame.m_currentTime;
}


//-------------------------------
//		FPS表示
//-------------------------------
void PrintFps()
{
	// 1フレーム進んだと判断
	g_frame.m_count++;
	// 前回の表示時間から今回までの差分を計算
	int difTime = g_frame.m_currentTime - g_frame.m_updateFrameRateTime;

	// 1秒が経過するまで経過はこれ以降実行しない
	if (difTime >= 1000)
	{
		float frameCnt = (float)(g_frame.m_count * 1000);
		// フレームレートを計算
		g_frame.m_frameRate = frameCnt / difTime;
		// カウント初期化
		g_frame.m_count = 0;
		// フレームレート更新時間を最新に
		g_frame.m_updateFrameRateTime = g_frame.m_currentTime;
	}

	// FPSは常に表示を続ける
	DrawFormatString(16, 16, GetColor(255, 255, 255),
		"FPS:%.2lf", g_frame.m_frameRate);
}