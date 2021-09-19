#include"SceneClear.h"
#include"../../Input/Input.h"
#include"../../Common.h"

CSceneClear::~CSceneClear()
{
	Fin();
}
//初期値
void CSceneClear::Init()
{
	m_iHndle = -1;
}
//描画
void CSceneClear::Draw()
{
	
		DrawFormatString(100, 100, GetColor(255, 255, 255), "クリア Enterでタイトル");
	
}
//メイン処理
int CSceneClear::Step()
{

	int ret = -1;
	if (CInputKey::IsPuch(KEY_INPUT_RETURN))
	{
		ret = SCENE_TITLE;
	}
	return ret;
}
//終了処理
void CSceneClear::Fin()
{

	if (m_iHndle != 1)
	{
		m_iHndle = -1;
	}
}