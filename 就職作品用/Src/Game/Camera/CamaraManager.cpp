#include"CamaraManager.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"../Input/Input.h"


#define _DEBUG_

//�R���X�g���N�^
CCameraManager::CCameraManager()
{
	m_state = GAME_PLAYER;
}
//�f�X�g���N�^
CCameraManager::~CCameraManager()
{

}
//������
void CCameraManager::Init()
{
	m_Playcamera.Init();
	m_Playcamera.SetNearFar(1.0f, 5500.0f);
	m_Golemcamera.Init();
	m_Golemcamera.SetNeartFar(1.0f, 5500.0f);
}
//���[�h
void CCameraManager::Load()
{

}
//�X�V����
void CCameraManager::Step(CPlayer* player, CGolem* golem)
{
	/*CPlayer* Player = CPlayer::GetInstance();
	CGolem* Golem = CGolem::GetInstance();*/

	//���X�g�̒���
	VECTOR vFocus_p = VAdd(player->GetPos(),VGet(0.0f,3.0f,0.0f));
	//���X�g�̒���
	VECTOR vFocus_g = VAdd(golem->GetPos(), VGet(0.0f, 3.0f, 0.0f));

	switch (m_state) {
	case GAME_PLAYER:	//�v���C���[�J����
		m_Playcamera.Step(vFocus_p);
		m_Playcamera.Update();
		if (m_state == GAME_PLAYER)
		{
			if (CInputKey::IsPuch(KEY_INPUT_G))
			{
				m_state = GAME_GOLEM;
			}
		}
		break;

	case GAME_GOLEM:	//�S�[�����J����
		m_Golemcamera.Step(vFocus_g);
		m_Golemcamera.Update();
		if (m_state == GAME_GOLEM)
		{
			if (CInputKey::IsPuch(KEY_INPUT_G))
			{
				m_state = GAME_PLAYER;
			}
		}
		break;
	}
}
//�`��
void CCameraManager::Draw()
{

}
//�I��
void CCameraManager::Fin()
{

}
