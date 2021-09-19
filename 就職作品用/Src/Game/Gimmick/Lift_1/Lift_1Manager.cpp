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
////�E�H�[���̑���
//static const int LIFT_NUM[3] = { 2,2,0 };
////�R���X�g���N�^
//CLift_1Manager::CLift_1Manager()
//{
//
//	for (int liftindex = 0; liftindex < LIFT_MAX; liftindex++)
//	{
//		m_Lift_1_vec.push_back(new CLift_1);
//		m_Lever_1_vec.push_back(new CLever);
//	}
//}
////������
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
////���[�h����
//void CLift_1Manager::Load()
//{
//	//���t�g�̃R�s�[
//	int Wallhndl = MV1LoadModel(WALL_PATH_S);
//	int LeverHndl = MV1LoadModel(LEVER_PATH_S);
//	int SakuHndl = MV1LoadModel(SAKU_PATH_S);
//
//
//	//for���ŉ񂵂����R�s�[����
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
////���C������
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
//		//�v���C���[�ƃ��t�g�̓����蔻��
//		Player->ReflecCollision(collision->PlayerMoveObjectHitCheck(m_Lift_1_vec[lift_index]->GetHndl(), m_Lift_1_vec[lift_index]->GetMove()));
//		Golem->ReflecCollision(collision->GolemMoveObjectHitCheck(m_Lift_1_vec[lift_index]->GetHndl(), m_Lift_1_vec[lift_index]->GetMove()));
//	}
//	Move();
//}
////�X�V����
//void CLift_1Manager::Update()
//{
//	//�ǍX�V����
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
////�`�揈��
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
////�I������
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
////���t�g�ړ�����
//void CLift_1Manager::Move()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	for (int lift_root = 0; lift_root < LIFT_NUM[m_iStageType]; lift_root++)
//	{
//		//���t�g���W
//		VECTOR liftPos;
//		//���t�g�̃^�[�Q�b�g���W
//		VECTOR targetPos;
//		//���t�g�̂�����̃^�[�Q�b�g���W
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
//			//�����̃x�N�g�����W�擾
//		liftPos = m_Lift_1_vec[lift_root]->GetPos();
//			//�ړI�n�̍��W�x�N�g���擾
//			targetPos = Stage->GetManeBone(3, lift_root);
//
//			targetPos2 = Stage->GetManeBone(2, lift_root);
//
//
//			dir = VSub(targetPos, liftPos);
//
//
//			dir2 = VSub(targetPos2, liftPos);
//			//�����E����
//			len = VSize(dir);
//
//			len2 = VSize(dir2);
//		
//		
//
//		//�����E�H�[���t���O��true�̎��ǂ�ړI�n���W�ɃZ�b�g
//		if (m_Lift_1_vec[lift_root]->GetIsChange() == true)
//		{
//			dir = VNorm(dir);
//			dir = VScale(dir, 0.2f);
//			m_Lift_1_vec[lift_root]->SetMove(dir);
//			//������̋����ȓ��ł����
//			if (len <= 0.1f)
//			{
//
//				////�ړI�n
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
//		//false�Ȃ猳�̍��W�ɖ߂�
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
////���t�g���o�[�̍��W
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
////���t�g�̃n���h���擾
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