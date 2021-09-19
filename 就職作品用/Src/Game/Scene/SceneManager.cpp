#include"SceneManager.h"
#include"ScenePlay/ScenePlay.h"
#include"SceneTitle/SceneTitle.h"
#include"SceneClear/SceneClear.h"
#include"SceneGameOver/SceneGameOver.h"
#include"../Character/Player/Player.h"
#include"../Input/Input.h"

//コンストラクタ
CSceneManager::CSceneManager():m_Base(nullptr),	m_iState(STATEID_INIT), m_iNextstate(SCENE_TITLE)
	{
	m_iScene[STATEID_INIT] = &CSceneManager::Init;
	m_iScene[STATEID_STEP] = &CSceneManager::Step;
	m_iScene[STATEID_FIN] = &CSceneManager::Fin;
	CInputKey::Init();
	CreateScene();

}
//デストラクタ
CSceneManager::~CSceneManager()
{
	if (m_Base != nullptr)
	{
		delete m_Base;
	}
}
//ループ処理
int CSceneManager::Loop()
{
	int ret = -1;

	CInputKey::Update();

	(this->*m_iScene[m_iState])();


	return ret;

}

//描画処理
void CSceneManager::Draw()
{
	m_Base->Draw();
}
//初期化
void CSceneManager::Init()
{
	m_Base->Init();
	m_iState = STATEID_STEP;

}

//メイン処理
void CSceneManager::Step()
{
	
	m_iNextstate = m_Base->Step();
	if (m_iNextstate != -1)
	{
		m_iState = STATEID_FIN;
	}

}

//終了処理
void CSceneManager::Fin()
{
	m_Base->Fin();
	CreateScene();
	m_iState = STATEID_INIT;
}
//各シーンを作る
void CSceneManager::CreateScene()
{
	if (m_Base != nullptr)
	{
		delete m_Base;
	}

	switch (m_iNextstate)
	{
	case SCENE_TITLE:
	{
		m_Base = new CSceneTitle;
	}
	break;
	case SCENE_PLAY:
	{
		m_Base = new CScenePlay;
	}
	break;
	case  SCENE_CLEAR:
	{
		m_Base = new CSceneClear;
	}
	break;
	case SCENE_GAMEOVER:
	{
		m_Base = new CSceneGameOver;
	}
	break;
	}

	m_iNextstate = -1;
}
