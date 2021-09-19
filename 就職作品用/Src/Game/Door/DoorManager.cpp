//#include"DoorManager.h"
//#include"../Field/StageManager.h"
//#include"../../Lib/math/Hit/Hit.h"
////コンストラクタ
//CDoorManager::CDoorManager()
//{
//	m_Door = nullptr;
//
//	m_Door = new CDoor;
//
//	Init();
//}
////初期化
//void CDoorManager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	m_Door->Init();
//	//ステージから扉の座標を取得
//	VECTOR DoorPos = Stage->GetManeBone(11, 0);
//
//
//	m_Door->SetPos(DoorPos);	
//	
//}
////ロード処理
//void CDoorManager::Load()
//{
//	m_Door->Load();
//}
////メイン処理
//void CDoorManager::Step()
//{
//	m_Door->Step();
//
//}
////更新処理
//void CDoorManager::Update()
//{
//	m_Door->Update();
//
//}
//
////描画処理
//void CDoorManager::Draw()
//{
//	m_Door->Draw();
//}
////終了処理
//void CDoorManager::Fin()
//{
//	if (m_Door != nullptr)
//	{
//		m_Door->Fin();
//		delete m_Door;
//
//		m_Door = nullptr;
//	}
//
//}