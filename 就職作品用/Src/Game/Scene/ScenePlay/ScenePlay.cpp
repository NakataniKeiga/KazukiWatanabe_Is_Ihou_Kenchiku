#include"ScenePlay.h"
#include"../../Camera/CamaraManager.h"
//=============================================
#include"../../Gimmick/ObjectManager.h"
#include"../../Collision/CollisionManager.h"

//=============================================

CScenePlay::CScenePlay()
{
	/*Player = CPlayer::GetInstance();
	Golem = CGolem::GetInstance();*/
	m_Stage = CStageManager::GetInstance();
	m_CharacterManager = CCharacterManager::GetInstance();
	/*m_EnemyManager = CEnemyManager::GetInstance();*/
	/*m_Camera = CCameraManager::GetInstance();*/
	m_ObjectMnager = CObjectManager::GetInstance();
}

//初期化
void CScenePlay::Init()
{
	m_Stage->Init();
	m_ObjectMnager->Init();
	
	/*m_EnemyManager->Init();*/
	/*m_Camera->Init();*/
	/*Player->Init();*/
	m_CharacterManager->Init();
	/*Golem->Init();*/
	m_UI.Init();
	Menu.Init();

}
//メイン処理
int CScenePlay::Step()
{
	int ret = -1;

	if (Menu.Getflg() == false)
	{
		m_ObjectMnager->Step();
		
	/*	m_EnemyManager->Step();*/
		/*m_Camera->Step();*/
		m_CharacterManager->Step();
		/*Player->Step(Golem);
		Golem->Step(Player);*/
		m_UI.Step();

		//ステージの当たり判定

		if (m_Stage->GetStageClearFlg() == true)
		{
			m_Stage->ChengeStage();

			if (m_Stage->GetGameClearFlg() == true)
			{
				ret = SCENE_CLEAR;
			}
			else
			{
				Init();
			}
		}
		/*else if (m_CharacterManager->PlayerGetFlg() == false)
		{
			ret = SCENE_GAMEOVER;
		}*/

		if (CInputKey::IsPuch(KEY_INPUT_H))
		{
			//ここ変える
			Menu.Setflg(true);
		}
	}


	if (Menu.Getflg() == true)
	{
		Menu.Step();
	}

	return ret;

}
//描画処理
void CScenePlay::Draw()
{
	if (Menu.Getflg() == true)
	{
		Menu.Draw();
	}
	else
	{
		m_Stage->Draw();
		m_ObjectMnager->Draw();
		m_CharacterManager->Draw();
		/*m_EnemyManager->Draw();*/
		/*m_Camera->Draw();*/
		m_UI.Draw();
		/*Player->Draw();
		Golem->Draw();*/
	}

}
//終了
void CScenePlay::Fin()
{
	m_Stage->Fin();
	m_CharacterManager->Fin();
	/*m_EnemyManager->Fin();*/
	m_Camera->Fin();
	m_ObjectMnager->Fin();
	m_UI.Fin();

	m_Stage->DeleteInstance();
	m_CharacterManager->DeleteInstance();
	/*m_EnemyManager->DeleteInstance();*/
	m_Camera->DeleteInstance();
	m_ObjectMnager->DeleteInstance();

};

