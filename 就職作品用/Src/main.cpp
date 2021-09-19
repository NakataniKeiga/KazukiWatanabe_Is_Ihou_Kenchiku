
#include "DxLib.h"
#include <crtdbg.h>
#include <list>
#include"Game/Scene/SceneManager.h"
#include"Lib/Frame.h"
#include "../Src/Game/Input/Input.h"

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//ウィンドウの状態を設定する	
	ChangeWindowMode(true);
	SetGraphMode(1280, 720, 32);
	//メモリリークを確認する
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	//描画するスクリーンを設定
	SetDrawScreen(DX_SCREEN_BACK);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// 点を打つ

	//シーンマネージャーを確保する
	CSceneManager cSceneManager;
	/*CSceneManager* cSceneManager = CSceneManager::GetInstance();*/
	//初期化
	//cSceneManager->Init();

	while (ProcessMessage() != -1)
	{

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		ClearDrawScreen();
		//メイン・描画処理
		cSceneManager.Loop();
		cSceneManager.Draw();
		/*cSceneManager->Step();
		cSceneManager->Draw();*/
		ScreenFlip();
	}

	//終了
	/*cSceneManager->Fin();*/
	//削除
	//delete cSceneManager;

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
