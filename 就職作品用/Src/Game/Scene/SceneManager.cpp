#include"SceneManager.h"
#include"ScenePlay/ScenePlay.h"
#include"SceneTitle/SceneTitle.h"
#include"SceneClear/SceneClear.h"
#include"SceneGameOver/SceneGameOver.h"
#include"../Character/Player/Player.h"
#include"../Input/Input.h"

//�R���X�g���N�^
CSceneManager::CSceneManager():m_Base(nullptr),	m_iState(STATEID_INIT), m_iNextstate(SCENE_TITLE)
	{
	m_iScene[STATEID_INIT] = &CSceneManager::Init;
	m_iScene[STATEID_STEP] = &CSceneManager::Step;
	m_iScene[STATEID_FIN] = &CSceneManager::Fin;
	CInputKey::Init();
	CreateScene();

}
//�f�X�g���N�^
CSceneManager::~CSceneManager()
{
	if (m_Base != nullptr)
	{
		delete m_Base;
	}
}
//���[�v����
int CSceneManager::Loop()
{
	int ret = -1;

	CInputKey::Update();

	(this->*m_iScene[m_iState])();


	return ret;

}

//�`�揈��
void CSceneManager::Draw()
{
	m_Base->Draw();
}
//������
void CSceneManager::Init()
{
	m_Base->Init();
	m_iState = STATEID_STEP;

}

//���C������
void CSceneManager::Step()
{
	
	m_iNextstate = m_Base->Step();
	if (m_iNextstate != -1)
	{
		m_iState = STATEID_FIN;
	}

}

//�I������
void CSceneManager::Fin()
{
	m_Base->Fin();
	CreateScene();
	m_iState = STATEID_INIT;
}
//�e�V�[�������
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
