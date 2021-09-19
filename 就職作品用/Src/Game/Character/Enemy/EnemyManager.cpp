//#include"EnemyManager.h"
//#include"../Player/Player.h"
//#include"../../Field/StageManager.h"
//#include"math.h"
//
//
//static const char* MODEL_PATH_S = { "Data/model/Player/Player.x" };
//
//
//static const int ENEMY_NUM[3] = { 0,2,0 };
//
//CEnemyManager::CEnemyManager()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_MAX; enemy_index++)
//	{
//		m_Enemy_vec.push_back(new CEnemy);
//	}
//}
//
//void CEnemyManager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_iStageType = Stage->GetStageNum();
//
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Init();
//		//初期セット
//		m_iRootID[enemy_index] = 1;
//		VECTOR targetPos = Stage->GetRootBone(enemy_index, 0);
//
//		m_Enemy_vec[enemy_index]->SetPos(targetPos);
//
//	}
//		
//	
//}
////データ関連のロード
//void CEnemyManager::Load()
//{
//	int Enemy_handle = MV1LoadModel(MODEL_PATH_S);
//
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->DuplicateModel(Enemy_handle);
//	}
//}
////メイン処理
//void CEnemyManager::Step()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Step();
//	}
//	Move();
//}
////更新処理
//void CEnemyManager::Update()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Update();
//	}
//}
////描画処理
//void CEnemyManager::Draw()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Draw();
//	}
//}
////終了処理
//void CEnemyManager::Fin()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Fin();
//
//		delete m_Enemy_vec[enemy_index];
//	}
//	m_Enemy_vec.clear();
//}
////敵の動き
//void CEnemyManager::Move()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	CPlayer* Player = CPlayer::GetInstance();
//
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		//エネミーの現在座標
//		VECTOR EnemyPos = m_Enemy_vec[enemy_index]->GetPos();
//		//
//		VECTOR TargetPos = Stage->GetRootBone(enemy_index, m_iRootID[enemy_index]);
//		
//		VECTOR PlayerPos = Player->GetPos();
//		//エネミーとルート座標の距離,長さを計る
//		VECTOR dir = VSub(TargetPos,EnemyPos);
//		float len = VSize(dir);
//
//
//		//プレイヤーとの距離
//		VECTOR dir2 = VSub(PlayerPos, EnemyPos);
//
//		dir2.y = 0.0f;
//		dir2 = VNorm(dir2);
//		dir2 = VScale(dir2, 0.5f);
//
//		
//
//		if (m_Enemy_vec[enemy_index]->GetChace() == true)
//		{
//			//追いかけてくる速度をセット
//			dir2 = VScale(dir2, 0.3f);
//
//			//座標をセットする
//			EnemyPos = VAdd(EnemyPos, dir2);
//			m_Enemy_vec[enemy_index]->SetPos(EnemyPos);
//
//			//角度を合わせる
//			float rot = atan2f(-dir2.x, -dir2.z);
//			m_Enemy_vec[enemy_index]->SetRot(VGet(0.0f, rot, 0.0f));
//		}
//		else if (m_Enemy_vec[enemy_index]->GetChace() == false)
//		{
//			//
//			float range = 0.5f;
//
//			if (len < range)
//			{
//				//目的地座標が近かったら次の目的座標に移動させる
//				m_Enemy_vec[enemy_index]->SetPos(TargetPos);
//				m_iRootID[enemy_index] = (m_iRootID[enemy_index] + 1) % Stage->GetRootNum(enemy_index);
//			}
//			else
//			{
//				//目的地座標に向かって移動
//				dir.y = 0.0f;
//				dir = VNorm(dir);
//				dir = VScale(dir, 0.1f);
//				EnemyPos = VAdd(EnemyPos, dir);
//				m_Enemy_vec[enemy_index]->SetPos(EnemyPos);
//			}
//			//角度をセット
//			float rot = atan2f(-dir.x, -dir.z);
//			m_Enemy_vec[enemy_index]->SetRot(VGet(0.0f, rot, 0.0f));
//
//		}
//
//	}
//
//}