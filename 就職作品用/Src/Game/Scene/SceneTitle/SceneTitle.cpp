#include"SceneTitle.h"
#include"../../Input/Input.h"

static const char* TITLE_PATH_S[] = { "Data/model/Scene/title/Title.png","Data/model/Scene/title/ENTER.png" };

//コンストラクタ
CSceneTitle::CSceneTitle()
{
	Init();
}

//デストラクタ
CSceneTitle::~CSceneTitle() {
	Fin();
}

//初期値
void CSceneTitle::Init()
{
	m_iHndle = new int[GRAPHICS_NUM];
	m_iSelectNumber = 0;
	m_iDrawNumber = 0;
	
	for (int title_path_Index = 0; title_path_Index < GRAPHICS_NUM; title_path_Index++)
	{
		m_iHndle[title_path_Index] = LoadGraph(TITLE_PATH_S[title_path_Index]);
	}

}
//描画
void CSceneTitle::Draw()
{
	DrawGraph(0, 0, m_iHndle[0], true);
	DrawGraph(400, 400, m_iHndle[1], true);
}
//メイン処理
int CSceneTitle::Step()
{
	int ret = -1;
		if (CInputKey::IsPuch(KEY_INPUT_RETURN))
		{
			ret = SCENE_PLAY;
		}
		return ret;
			
}
//後処理
void CSceneTitle::Fin()
{
	delete[] m_iHndle;
}