//#include"ExitManager.h"
//
//#include"../Field/StageManager.h"
//
//#include"../Character/Player/Player.h"
//
//#include"../../Lib/math/Hit/Hit.h"
//
//#include"../Collision/CollisionManager.h"
////コンストラクタ
//CExitManager::CExitManager()
//{
//	m_Exit = nullptr;
//	m_Exit = new CExit;
//
//	Init();
//}
////初期化
//void CExitManager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_Exit->Init();
//	//ステージから出口の座標を取得
//	VECTOR ExitPos = Stage->GetManeBone(5, 0);
//	m_Exit->SetPos(ExitPos);
//}
////ロード処理
//void CExitManager::Load()
//{
//	m_Exit->Load();
//}
////メイン処理
//void CExitManager::Step()
//{
//	CPlayer* Player = CPlayer::GetInstance();
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_Exit->Step();
//	//鍵を持っている状態でtrueなら
//	if (Player->GetHave() == true)
//	{
//		if (CHit::IsHitSphereToSphere(Player->GetPos(), Player->GetRadius(), m_Exit->GetPos(), m_Exit->GetRadius()))
//		{
//			m_Exit->SetIscene(true);
//		}
//		if (m_Exit->GetIscene() == true)
//		{
//			//ステージクリアフラグをONにし次のステージヘ
//			Stage->SetStageClearFlg(true);
//		}
//	}
//}
////更新処理
//void CExitManager::Update()
//{
//
//	m_Exit->Update();
//
//}
////描画処理
//void CExitManager::Draw()
//{
//	m_Exit->Draw();
//}
////終了処理
//void CExitManager::Fin()
//{
//	if (m_Exit != nullptr)
//	{
//		m_Exit->Fin();
//		delete m_Exit;
//		m_Exit = nullptr;
//	}
//}