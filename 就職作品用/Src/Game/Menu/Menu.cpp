#include"Menu.h"
#include"../Input/Input.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"../Field/StageManager.h"
#include"../../Lib/math/Hit/Hit.h"

static const char* MAP_PATH_S[]{ "Data/model/UI/MapUI1.png","Data/model/UI/player.png","Data/model/UI/gorem.png", "Data/model/UI/MAPUI_2.png" ,
								 "Data/model/UI/MapSelect.png","Data/model/UI/MapSelect2.png","Data/model/UI/MapSelect3.png" ,"Data/model/UI/SelectWaku.png" ,
								 "Data/model/UI/Operation.png" };

//初期化
void CMenu::Init()
{
	m_isMenuflg = false;
	m_iHandle = new int[9];
	m_MenuType = 0;
	Load();
}
//ロード処理
void CMenu::Load()
{
	for (int menu_index = 0; menu_index < 9; menu_index++)
	{
		m_iHandle[menu_index] = LoadGraph(MAP_PATH_S[menu_index]);
	}
}
//描画処理
void CMenu::Draw()
{
	CStageManager* Stage = CStageManager::GetInstance();
	m_iStageType = Stage->GetStageNum();

	DrawGraph(0, 0, m_iHandle[4], true);
	DrawGraph(0, 475, m_iHandle[5], true);
	DrawGraph(0, 240, m_iHandle[6], true);


	switch (m_MenuType)
	{
	case TYEP_MAP://マップ
		DrawGraph(0, 0, m_iHandle[7], true);
		if (m_iStageType == 0)
		{
			DrawGraph(200, 0, m_iHandle[0], true);
			DrawRotaGraph(static_cast<int>(DrawPlayerPos.x), static_cast<int>(DrawPlayerPos.z), 0.05f, 1.0f, m_iHandle[1], true, false);
			DrawRotaGraph(static_cast<int>(DrawGolemPos.x), static_cast<int>(DrawGolemPos.z), 0.05f, 1.0f, m_iHandle[2], true, false);
		}
		if (m_iStageType == 1)
		{
			DrawGraph(200, 0, m_iHandle[3], true);
			DrawRotaGraph(static_cast<int>(DrawPlayerPos.x), static_cast<int>(DrawPlayerPos.z), 0.05f, 1.0f, m_iHandle[1], true, false);
			DrawRotaGraph(static_cast<int>(DrawGolemPos.x), static_cast<int>(DrawGolemPos.z), 0.05f, 1.0f, m_iHandle[2], true, false);
		}
		break;
	case TYPE_OPERATUON://操作説明用

		DrawGraph(0, 240, m_iHandle[7], true);
		DrawGraph(200, 0, m_iHandle[8], true);
		break;
	case TYPE_BACK:
		DrawGraph(0, 475, m_iHandle[7], true);
		break;
	}

}
//メイン処理
void CMenu::Step()
{
	CStageManager* Stage = CStageManager::GetInstance();
	//CPlayer* Player = CPlayer::GetInstance();
	//CGolem* Golem = CGolem::GetInstance();

	//VECTOR PlayerPos = Player->GetPos();
	//VECTOR GolemPos = Golem->GetPos();

	//m_iStageType = Stage->GetStageNum();

	//if (m_iStageType == 0)
	//{
	//	DrawPlayerPos = VGet(960.0f + (PlayerPos.x * 2.1f), 0.0f, 695.0f + (-PlayerPos.z * 2.0f));
	//	DrawGolemPos = VGet(955.0f + (GolemPos.x * 2.1f), 0.0f, 695.0f + (-GolemPos.z * 2.0f));
	//}
	//else if (m_iStageType == 1)
	//{
	//	DrawPlayerPos = VGet(970.0f + (PlayerPos.x * 2.1f), 0.0f, 645.0f + (-PlayerPos.z * 2.0f));
	//	DrawGolemPos = VGet(970.0f + (GolemPos.x * 2.1f), 0.0f, 645.0f + (-GolemPos.z * 2.0f));
	//}

	//if (m_MenuType > 0 || m_MenuType < 2)
	//{

	//	if (CInputKey::IsPuch(KEY_INPUT_UP))
	//	{
	//		if (m_MenuType > 0)
	//		{
	//			m_MenuType--;
	//		}
	//	}
	//	if (CInputKey::IsPuch(KEY_INPUT_DOWN))
	//	{
	//		if (m_MenuType < 2)
	//		{
	//			m_MenuType++;
	//		}
	//	}
	//}
	//if (m_MenuType == 2)
	//{
	//	if (CInputKey::IsPuch(KEY_INPUT_RETURN))
	//	{
	//		m_isMenuflg = false;
	//		m_MenuType = 0;
	//		
	//	}
	//}
}
//終了
void CMenu::Fin()
{
	delete[] m_iHandle;

}