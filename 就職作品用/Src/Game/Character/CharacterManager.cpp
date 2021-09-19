#include"CharacterManager.h"

CCharacterManager::CCharacterManager()
{
	m_Player = nullptr;
	m_Golem = nullptr;

	m_Player = new CPlayer;
	m_Golem = new CGolem;


	m_Camera = CCameraManager::GetInstance();

	/*m_player = CPlayer::GetInstance();
	m_Golem = CGolem::GetInstance();*/

}


void CCharacterManager::Init()
{	
	m_Camera->Init();
	m_Player->Init();
	m_Golem->Init();

}

void CCharacterManager::Load()
{
	m_Player->Load();
	m_Golem->Load();
}

void CCharacterManager::Step()
{
	m_Player->IsChange(m_Golem);
	m_Player->Step(m_Golem);
	m_Golem->Step(m_Player);
	m_Camera->Step(m_Player,m_Golem);
	
}


void CCharacterManager::Draw()
{
	m_Player->Draw();
	m_Golem->Draw();
	m_Camera->Draw();
}

void CCharacterManager::Fin()
{
	m_Player->Fin();
	m_Golem->Fin();
	m_Camera->Fin();
}

bool CCharacterManager::PlayerGetFlg()
{
	
}