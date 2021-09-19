//#include"Lift_1Manager.h"
//
//
//#include"../../Field/StageManager.h"
//
//#include"../../Input/Input.h"
//
//#include"../../Collision/CollisionManager.h"
//
//
//static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };
//static const char* LEVER_PATH_S = { "Data/model/Lever/Lever.x" };
//static const char* SAKU_PATH_S = { "Data/model/Wall/saku.x" };
//
//
////ウォールの総数
//static const int LIFT_NUM[3] = { 2,2,0 };
////コンストラクタ
//CLift_1Manager::CLift_1Manager()
//{
//
//	for (int liftindex = 0; liftindex < LIFT_MAX; liftindex++)
//	{
//		m_Lift_1_vec.push_back(new CLift_1);
//		m_Lever_1_vec.push_back(new CLever);
//	}
//}
////初期化
//void CLift_1Manager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_iStageType = Stage->GetStageNum();
//
//	//for (auto& it : m_Lever_1_vec)
//	//{
//	//	it->Init();
//
//	//}
//
//	for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_1_vec[lift_index]->Init();
//		m_Lever_1_vec[lift_index]->Init();
//
// 		VECTOR LiftPos = Stage->GetManeBone(2, lift_index);
//		VECTOR LeverPos = Stage->GetManeBone(1, lift_index);
//
//		if (m_iStageType == 0)
//		{
//			m_Lift_1_vec[lift_index]->Stage_1SetScale(lift_index);
//		}
//		else if (m_iStageType == 1)
//		{
//			m_Lift_1_vec[lift_index]->Stage_2SetScale(lift_index);
//		}
//
//		m_Lift_1_vec[lift_index]->SetPos(LiftPos);
//		m_Lever_1_vec[lift_index]->SetPos(LeverPos);
//	}
//
//}
////ロード処理
//void CLift_1Manager::Load()
//{
//	//リフトのコピー
//	int Wallhndl = MV1LoadModel(WALL_PATH_S);
//	int LeverHndl = MV1LoadModel(LEVER_PATH_S);
//	int SakuHndl = MV1LoadModel(SAKU_PATH_S);
//
//
//	//for文で回した分コピーする
//	for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	{
//		if (lift_index < 1)
//		{
//			m_Lift_1_vec[lift_index]->DuplicateModel(SakuHndl);
//		}
//		else
//		{
//			m_Lift_1_vec[lift_index]->DuplicateModel(Wallhndl);
//		}
//		m_Lever_1_vec[lift_index]->DuplicateModel(LeverHndl);
//
//	}
//
//}
////メイン処理
//void CLift_1Manager::Step()
//{
//	CPlayer* Player = CPlayer::GetInstance();
//	CGolem* Golem = CGolem::GetInstance();
//	CCollisionManager* collision = CCollisionManager::GetInstance();
//	//for (auto& it : m_Lever_1_vec)
//	//{
//	//	it->Step();
//	//	if (it->GetIsChange() == true)
//	//	{
//	//		it->SetIsChange(true);
//	//	}
//	//	else if (it->GetIsChange() == false)
// //		{
//	//		it->SetIsChange(false);
//	//	}
//	//}
//
//	//for (auto& it : m_Lift_1_vec)
//	//{
//	//	it->Draw();
//	//}
//
//	for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lever_1_vec[lift_index]->Step();
//
//		if (m_Lever_1_vec[lift_index]->GetIsChange() == true)
//		{
//			m_Lift_1_vec[lift_index]->SetIsChange(true);
//			/*DrawSphere3D(leverPos, leverRadius, 200, GetColor(255, 255, 0), GetColor(255, 255, 0), 0);*/
//		}
//
//		else if (m_Lever_1_vec[lift_index]->GetIsChange() == false)
//		{
//			m_Lift_1_vec[lift_index]->SetIsChange(false);
//		/*	DrawSphere3D(leverPos, leverRadius, 200, GetColor(255, 255, 0), GetColor(255, 255, 0), 0);*/
//		}
//		//プレイヤーとリフトの当たり判定
//		Player->ReflecCollision(collision->PlayerMoveObjectHitCheck(m_Lift_1_vec[lift_index]->GetHndl(), m_Lift_1_vec[lift_index]->GetMove()));
//		Golem->ReflecCollision(collision->GolemMoveObjectHitCheck(m_Lift_1_vec[lift_index]->GetHndl(), m_Lift_1_vec[lift_index]->GetMove()));
//	}
//	Move();
//}
////更新処理
//void CLift_1Manager::Update()
//{
//	//壁更新処理
//	//for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	//{
//	//	m_Lift_1_vec[lift_index]->Update();
//	//	m_Lever_1_vec[lift_index]->Update();
//	//}
//
//	for (auto& it : m_Lever_1_vec)
//	{
//		it->Update();
//	}
//
//	for (auto& it : m_Lift_1_vec)
//	{
//		it->Update();
//	}
//}
////描画処理
//void CLift_1Manager::Draw()
//{
//	for (auto& it : m_Lever_1_vec)
//	{
//		it->Draw();
//	}
//
//	for (auto& it : m_Lift_1_vec)
//	{
//		it->Draw();
//	}
//
//	/*for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_1_vec[lift_index]->Draw();
//		m_Lever_1_vec[lift_index]->Draw();
//	}*/
//
//}
////終了処理
//void CLift_1Manager::Fin()
//{
//
//	for (int lift_index = 0; lift_index < LIFT_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_1_vec[lift_index]->Fin();
//		delete m_Lift_1_vec[lift_index];
//
//		m_Lever_1_vec[lift_index]->Fin();
//		delete m_Lever_1_vec[lift_index];
//	}
//
//	m_Lift_1_vec.clear();
//	m_Lever_1_vec.clear();
//	
//}
////リフト移動処理
//void CLift_1Manager::Move()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	for (int lift_root = 0; lift_root < LIFT_NUM[m_iStageType]; lift_root++)
//	{
//		//リフト座標
//		VECTOR liftPos;
//		//リフトのターゲット座標
//		VECTOR targetPos;
//		//リフトのもう一つのターゲット座標
//		VECTOR targetPos2;
//
//		VECTOR dir;
//
//		VECTOR dir2;
//
//		float len;
//
//		float len2;
//
//			//自分のベクトル座標取得
//		liftPos = m_Lift_1_vec[lift_root]->GetPos();
//			//目的地の座標ベクトル取得
//			targetPos = Stage->GetManeBone(3, lift_root);
//
//			targetPos2 = Stage->GetManeBone(2, lift_root);
//
//
//			dir = VSub(targetPos, liftPos);
//
//
//			dir2 = VSub(targetPos2, liftPos);
//			//長さ・距離
//			len = VSize(dir);
//
//			len2 = VSize(dir2);
//		
//		
//
//		//もしウォールフラグがtrueの時壁を目的地座標にセット
//		if (m_Lift_1_vec[lift_root]->GetIsChange() == true)
//		{
//			dir = VNorm(dir);
//			dir = VScale(dir, 0.2f);
//			m_Lift_1_vec[lift_root]->SetMove(dir);
//			//ある一定の距離以内であれば
//			if (len <= 0.1f)
//			{
//
//				////目的地
//				dir = VGet(0.0f, 0.0f, 0.0f);
//			/*	wallPos =VAdd(wallPos,dir);*/
//				m_Lift_1_vec[lift_root]->SetMove(dir);
//			}
//			else
//			{
//
//				liftPos = VAdd(liftPos, dir);
//
//			}
//			m_Lift_1_vec[lift_root]->SetPos(liftPos);
//
//		}
//		//falseなら元の座標に戻す
//		else if (m_Lift_1_vec[lift_root]->GetIsChange() == false)
//		{
//			dir2 = VNorm(dir2);
//			dir2 = VScale(dir2, 0.2f);
//			m_Lift_1_vec[lift_root]->SetMove(dir2);
//
//			if (len2 <= 0.1f)
//			{
//				dir2 = VGet(0.0f, 0.0f, 0.0f);
//				/*wallPos =VAdd(wallPos,dir);*/
//				m_Lift_1_vec[lift_root]->SetMove(dir2);
//			}
//			else
//			{
//				liftPos = VAdd(liftPos, dir2);
//			}
//			m_Lift_1_vec[lift_root]->SetPos(liftPos);
//		}
//	}
//
//}
//
////リフトレバーの座標
//VECTOR CLift_1Manager::GetLeverPos(int num) 
//{
//
//	if (m_Lever_1_vec[num] != nullptr)
//	{
//		return m_Lever_1_vec[num]->GetPos();
//	}
//	else
//	{
//		return VGet(0.0f, 0.0f, 0.0f);
//	}
//}
////リフトのハンドル取得
//int CLift_1Manager::GetLiftHandle(int num)
//{
//	if (m_Lift_1_vec[num] != nullptr)
//	{
//		return m_Lift_1_vec[num]->GetHndl();
//	}
//	else
//	{
//		return 0;
//	}
//}