#include"../UI.h"
#include"GameUI.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Golem/Golem.h"

static const char* Player_UI[] = { "Data/model/Player/Hitpoint/HitPoint.png" ,"Data/model/Player/Hitpoint/BreakHitPoint.png" ,"Data/model/Player/Key/Key_UI.png","Data/model/Player/Operation_2.png","Data/model/Player/Operation_.png" };

const int PLAYER_HP_MAX = 5;
//初期化
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
//ロード処理
void CGameUI::Load()
{

	for (int UI_index = 0; UI_index < 5; UI_index++)
	{
		m_iHandle[UI_index] = LoadGraph(Player_UI[UI_index]);
	}

}
//描画処理
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
	//		//プレヤーの現在の最大HPを表示する
	//		DrawGraph(m_iHp_x[index], m_iHp_y, m_iHandle[1], true);
	//	}
	//	else
	//	{
	//		//プレイヤーがうけたダメージ分を表示する
	//		DrawGraph(m_iHp_x[index], m_iHp_y, m_iHandle[0], true);
	//	}
	//}
	////プレイヤーがカギを持っていいる状態なら
	//if (Player->GetHave() == true)
	//{
	//	DrawRotaGraph(50, 100, 0.2f, 0.005f, m_iHandle[2], true, false);
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "ゴールを目指そう");
	//}
	//else if (Golem->GetIsAlive() == true)
	//{
	//	DrawGraph(0, 0, m_iHandle[3], true);
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "鍵を取得しよう");
	//
	//}
	//else if (Player->GetZenmaiHave() == true)
	//{
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "ゴーレムの後ろに行きゴーレムを起動させよう");
	//}	
	//else if (Player->GetZenmaiHave() == false)
	//{
	//	DrawFormatString(100, 100, GetColor(255, 255, 255), "ゼンマイ鍵を取得しよう");
	//}
	//if(Golem->GetIsAlive()==false)
	//{
	//	DrawGraph(0, 0, m_iHandle[4], true);
	//}
	
}
//終了処理
void CGameUI::Fin()
{
	delete[] m_iHandle;
	CUI::Fin();
}