//#include"NeedleManager.h"
//
//#include"../../../Lib/math/Hit/Hit.h"
//#include"../../Input/Input.h"
//
//#include"../../Field/StageManager.h"
//
//#include"../../Character/Player/Player.h"
//#include"../../Character/Golem/Golem.h"
//
//#include"../../Scene/ScenePlay/ScenePlay.h"
//#include"../../Scene/SceneManager.h"
//
//static const char* NEEDL_PATH_S = { "Data/model/Needle/Needle.x" };
//
//
////static const int NEEDLE_NUM[3] = { 24,23,0 };
////コンストラクタ
//CNeedleManager::CNeedleManager()
//{
//	for (int needle_index = 0; needle_index <NEEDLE_MAX; needle_index++)
//	{
//		m_Needle_vec.push_back(new CNeedle);
//	}
//}
////初期化
//void CNeedleManager::Init()
//{
//	CStageManager* m_Stage = CStageManager::GetInstance();
//	m_iStageType = m_Stage->GetStageNum();
//
//	for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		m_Needle_vec[needle_index]->Init();
//
//		VECTOR NeedlePos = m_Stage->GetManeBone(7,needle_index);
//		m_Needle_vec[needle_index]->SetPos(NeedlePos);
//		
//	}
//	
//}
////ロード処理
//void CNeedleManager::Load()
//{
//	int NeedleHndl = MV1LoadModel(NEEDL_PATH_S);
//
//	for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		m_Needle_vec[needle_index]->DuplicateModel(NeedleHndl);
//	}
//
//	/*for (auto& it : m_Needle_vec)
//	{
//		it->DuplicateModel(NeedleHndl);
//	}*/
//	
//}
////メイン処理
//void CNeedleManager::Step()
//{
//
//	for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		m_Needle_vec[needle_index]->Step();
//	}
//
//	//for (auto& it : m_Needle_vec)
//	//{
//	//	it->Step();
//	//}
//	
//}
////更新処理
//void CNeedleManager::Update()
//{
//	for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		m_Needle_vec[needle_index]->Update();
//	}
//	
//	/*for (auto& it : m_Needle_vec)
//	{
//		it->Update();
//	}*/
//}
////描画処理
//void CNeedleManager::Draw ()
//{
//	/*for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		m_Needle_vec[needle_index]->Draw();
//	}	*/
//
//	for (auto& it : m_Needle_vec)
//	{
//		it->Draw();
//	}
//}
////終了処理
//void CNeedleManager::Fin()
//{
//	for (int needle_index = 0; needle_index < NEEDLE_NUM[m_iStageType]; needle_index++)
//	{
//		
//		m_Needle_vec[needle_index]->Fin();
//		delete m_Needle_vec[needle_index];
//		
//	}
//	m_Needle_vec.clear();
//}
//
//
//
