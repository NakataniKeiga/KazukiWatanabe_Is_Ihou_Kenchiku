//#include"Box_1Manager.h"
//
//#include"../../Input/Input.h"
//
//#include"../../Field/StageManager.h"
//
//#include"../../Collision/CollisionManager.h"
//
//#include "../../Character/Player/Player.h"
//#include"../../Character/Golem/Golem.h"
//
//static const char* BOX_PATH_S = { "Data/model/Box/Box.x" };
//
//
////コンストラクタ
//CBox_1Manager::CBox_1Manager()
//{
//	m_Box = nullptr;
//	m_Box = new CBox_1[BOX_MAX];
//}
////初期化
//void CBox_1Manager::Init()
//{
//
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_iStageType = Stage->GetStageNum();
//
//	//箱初期化
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Init();
//		//ステージから箱座標を取得
//		VECTOR boxPos = Stage->GetManeBone(6, box_index);
//		m_Box[box_index].SetPos(boxPos);
//
//	}
//
//}
////ロード処理
//void CBox_1Manager::Load()
//{
//	//箱のコピー
//	int Boxhndl = MV1LoadModel(BOX_PATH_S);
//	//for文で回した分コピーする
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].DuplicateModel(Boxhndl);
//	}
//}
////メイン処理
//void CBox_1Manager::Step()
//{
//	CCollisionManager* Collision = CCollisionManager::GetInstance();
//	CPlayer* Player = CPlayer::GetInstance();
//	CGolem* Golem = CGolem::GetInstance();
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Step();
//		if (Player->GetShove() == false)
//		{
//			Player->ReflecCollision(Collision->PlayerObjectHitCheck(m_Box[box_index].GetHndl()));
//		}
//		Golem->ReflecCollision(Collision->GolemObjectHitCheck(m_Box[box_index].GetHndl()));
//
//
//		m_Box[box_index].ReflecCollision(Collision->CheckObjectHitStage(m_Box[box_index].GetPos(), m_Box[box_index].GetRadius()));
//
//		float BoxPosY = m_Box[box_index].GetPosY();
//
//		if (BoxPosY <= -10.0f)
//		{
//			VECTOR boxPos = Stage->GetManeBone(6, box_index);
//			m_Box[box_index].SetPos(boxPos);
//		}
//	}
//}
////更新処理
//void CBox_1Manager::Update()
//{
//	//箱更新処理
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Update();
//	}
//}
////描画処理
//void CBox_1Manager::Draw()
//{
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Draw();
//	}
//}
////終了処理
//void CBox_1Manager::Fin()
//{
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Fin();
//	}
//
//	delete[] m_Box;
//	m_Box = nullptr;
//}
