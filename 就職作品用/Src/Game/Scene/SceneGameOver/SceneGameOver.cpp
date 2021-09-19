#include"SceneGameOver.h"
#include"../../Input/Input.h"

static const char* GAMEOVER_PATH_S = { "Data/model/Scene/gameover/gameover.png" };
//コンストラクタ
CSceneGameOver::CSceneGameOver()
{
	Init();
}
//デストラクタ
CSceneGameOver::~CSceneGameOver()
{
	Fin();
}
//初期化
void CSceneGameOver::Init()
{
	
	m_iHndle = new int[1];
	Load();
}
//ロード処理
void CSceneGameOver::Load()
{
	m_iHndle[0] = LoadGraph(GAMEOVER_PATH_S);
}
//メイン処理
int CSceneGameOver::Step()
{
	int ret = -1;
	if (CInputKey::IsPuch(KEY_INPUT_RETURN))
	{
		ret = SCENE_TITLE;
	}
	return ret;

}
//描画処理
void CSceneGameOver::Draw()
{

	DrawGraph(0, 0, m_iHndle[0], true);

}
//終了処理
void CSceneGameOver::Fin()
{
	delete[] m_iHndle;

}