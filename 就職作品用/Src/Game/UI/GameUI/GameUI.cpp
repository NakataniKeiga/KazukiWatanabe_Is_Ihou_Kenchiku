#include"../UI.h"
#include"GameUI.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Golem/Golem.h"

static const char* Player_UI[] = { "Data/model/Player/Hitpoint/HitPoint.png" ,"Data/model/Player/Hitpoint/BreakHitPoint.png" ,"Data/model/Player/Key/Key_UI.png","Data/model/Player/Operation_2.png","Data/model/Player/Operation_.png" };

const int PLAYER_HP_MAX = 5;
//������
void  CGameUI::Init()
{
	m_iHandle = new int[3];

	m_iHp_y = 32;

	for (int index = 0; index < PLAYER_HP_MAX; index++)
	{
		if (index == 0)
		{
			m_iHp_x[index] = 32;
		}
		else
		{
			m_iHp_x[index] = m_iHp_x[index - 1] + 35;
		}
	}
}
//���[�h����
void CGameUI::Load()
{

	for (int UI_index = 0; UI_index < 5; UI_index++)
	{
		m_iHandle[UI_index] = LoadGraph(Player_UI[UI_index]);
	}

}
//�`�揈��
void CGameUI::Draw()
{

	//CPlayer* Player = CPlayer::GetInstance();
	//CGolem* Golem = CGolem::GetInstance();
	//
	//for (int index = 0; index < PLAYER_HP_MAX; index++)
	//{
	//	
	//	if (index >=Player->GetHitPoint())
	//	{	
	//		//�v�����[�̌��݂̍ő�HP��\������
	//		DrawGraph(m_iHp_x[index], m_iHp_y, m_iHandle[1], true);
	//	}
	//	else
	//	{
	//		//�v���C���[���������_���[�W����\������
	//		DrawGraph(m_iHp_x[index], m_iHp_y, m_iHandle[0], true);
	//	}
	//}
	////�v���C���[���J�M�������Ă������ԂȂ�
	//if (Player->GetHave() == true)
	//{
	//	DrawRotaGraph(50, 100, 0.2f, 0.005f, m_iHandle[2], true, false);
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "�S�[����ڎw����");
	//}
	//else if (Golem->GetIsAlive() == true)
	//{
	//	DrawGraph(0, 0, m_iHandle[3], true);
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "�����擾���悤");
	//
	//}
	//else if (Player->GetZenmaiHave() == true)
	//{
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "�S�[�����̌��ɍs���S�[�������N�������悤");
	//}	
	//else if (Player->GetZenmaiHave() == false)
	//{
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "�[���}�C�����擾���悤");
	//}
	//if(Golem->GetIsAlive()==false)
	//{
	//	DrawGraph(0, 0, m_iHandle[4], true);
	//}
	
}
//�I������
void CGameUI::Fin()
{
	delete[] m_iHandle;
	CUI::Fin();
}