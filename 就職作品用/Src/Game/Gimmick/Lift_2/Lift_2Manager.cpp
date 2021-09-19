//#include"Lift_2Manager.h"
//
//#include"../../../Lib/math/Hit/Hit.h"
//
//#include"../../Field/StageManager.h"
//#include "../../Character/Golem/Golem.h"
//#include"../../Character/Player/Player.h"
//#include"../../Collision/CollisionManager.h"
//
//
//static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };
//static const char* LEVER_PATH_S = { "Data/model/Lever/Floorswitch.x" };
//
//
//static const int LIFT_2_NUM[3] = { 2,1,0 };
////�R���X�g���N�^
//CLift_2Manager::CLift_2Manager()
//{
//	for (int lift_index = 0; lift_index < LIFT_2_MAX; lift_index++)
//	{
//		m_Lift_2_vec.push_back(new CLift_2);
//		m_Lever_Switch_vec.push_back(new CLift_Switch);
//	}
//}
//
////������
//void CLift_2Manager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//
//	m_iStageType = Stage->GetStageNum();
//
//	for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_2_vec[lift_index]->Init();
//		m_Lever_Switch_vec[lift_index]->Init();
//
//		VECTOR LiftPos = Stage->GetManeBone(8, lift_index);
//		VECTOR SwitchPos = Stage->GetManeBone(10,lift_index);
//
//		if (m_iStageType == 0)
//		{
//			m_Lift_2_vec[lift_index]->Stage_1SetScale(lift_index);
//		}
//
//		m_Lift_2_vec[lift_index]->SetPos(LiftPos);
//		m_Lever_Switch_vec[lift_index]->SetPos(SwitchPos);
//
//	}
//	
//	//for (auto& it : m_Lift_2_vec)
//	//{
//	//	it->Init();
//	//	VECTOR LiftPos = Stage->GetManeBone(8,);
//	//	
//	//	if (m_iStageType == 0)
//	//	{
//	//		it->Stage_1SetScale();
//	//	}
//
//	//}
//
//}
////���[�h����
//void CLift_2Manager::Load()
//{
//	//���t�g�̃R�s�[
//	int Wall_twohndl = MV1LoadModel(WALL_PATH_S);
//	int Lever_twohndl = MV1LoadModel(LEVER_PATH_S);
//	for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_2_vec[lift_index]->DuplicateModel(Wall_twohndl);
//		m_Lever_Switch_vec[lift_index]->DuplicateModel(Lever_twohndl);
//	}
//
//}
////���C������
//void CLift_2Manager::Step(CBox_1* Box,int BoxNum)
//{
//	CPlayer* Player = CPlayer::GetInstance();
//	CGolem* Golem = CGolem::GetInstance();
//	CCollisionManager* Collision = CCollisionManager::GetInstance();
//
//	for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		//�����Ń��t�g�Ɣ��������������̏���
//		bool IsHit = false;
//		for (int box_index = 0; box_index < BoxNum; box_index++)
//		{
//			VECTOR BoxPos = Box[box_index].GetPos();
//			float BoxRadius = Box[box_index].GetRadius();
//
//			m_Lever_Switch_vec[lift_index]->Step();
//
//			if (CHit::IsHitSphereToSphere(BoxPos, BoxRadius, m_Lever_Switch_vec[lift_index]->GetPos(), m_Lever_Switch_vec[lift_index]->GetRadius()))
//			{
//				IsHit = true;
//			}
//
//			Box[box_index].ReflecCollision(Collision->BoxMoveObjectHitCheck(Box, m_Lift_2_vec[lift_index]->GetHndl(), m_Lift_2_vec[lift_index]->GetMove()));
//		}
//		//�v���C���[�ƃ��t�g�̓����蔻��
//		Player->ReflecCollision(Collision->PlayerMoveObjectHitCheck(m_Lift_2_vec[lift_index]->GetHndl(), m_Lift_2_vec[lift_index]->GetMove()));
//		//�S�[�����ƃ��t�g�̓����蔻��
//		Golem->ReflecCollision(Collision->GolemMoveObjectHitCheck(m_Lift_2_vec[lift_index]->GetHndl(), m_Lift_2_vec[lift_index]->GetMove()));
//
//		bool IsChage = m_Lever_Switch_vec[lift_index]->GetIsChange();
//
//		if (IsChage == false && IsHit == true)
//		{
//			m_Lever_Switch_vec[lift_index]->SetChange(IsHit);
//		}
//
//	}
//	Move();
//}
////�X�V����
//void CLift_2Manager::Update()
//{
//	/*for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lever_Switch_vec[lift_index]->Update();
//		m_Lift_2_vec[lift_index]->Update();
//	}*/
//
//	for (auto& it : m_Lift_2_vec)
//	{
//		it->Update();
//	}
//	for (auto& it : m_Lever_Switch_vec)
//	{
//		it->Update();
//	}
//
//}
////�`�揈��
//void CLift_2Manager::Draw()
//{
//	/*for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lever_Switch_vec[lift_index]->Draw();
//		m_Lift_2_vec[lift_index]->Draw();
//	}*/
//
//	for (auto& it : m_Lift_2_vec)
//	{
//		it->Draw();
//	}
//	for (auto& it : m_Lever_Switch_vec)
//	{
//		it->Draw();
//	}
//}
////�I������
//void CLift_2Manager::Fin()
//{
//	for (int lift_index = 0; lift_index < LIFT_2_NUM[m_iStageType]; lift_index++)
//	{
//		m_Lift_2_vec[lift_index]->Fin();
//		m_Lever_Switch_vec[lift_index]->Fin();
//
//		delete m_Lift_2_vec[lift_index];
//		delete m_Lever_Switch_vec[lift_index];
//	}
//
//	m_Lift_2_vec.clear();
//	m_Lever_Switch_vec.clear();
//
//}
////���t�g�̈ړ�����
//void CLift_2Manager::Move()
//{
//	CStageManager* m_Stage = CStageManager::GetInstance();
//
//	for (int wall_two_root = 0; wall_two_root < LIFT_2_NUM[m_iStageType]; wall_two_root++)
//	{
//		//�E�H�[���̍��W�擾
//		VECTOR wall_twoPos = m_Lift_2_vec[wall_two_root]->GetPos();
//		//�E�H�[���̈ړ����W
//		VECTOR targetPos = m_Stage->GetManeBone(9,wall_two_root);
//		//�E�H�[���̏������W
//		VECTOR targetPos2 = m_Stage->GetManeBone(8,wall_two_root);
//
//		//���t�g�̈ړ������̒���
//		VECTOR dir = VSub(targetPos, wall_twoPos);
//		//���t�g�̏������W
//		VECTOR dir2 = VSub(targetPos2, wall_twoPos);
//		//�E�H�[���̒���.����
//		float len = VSize(dir);
//		//�E�H�[���̒���.����
//		float len2 = VSize(dir2);
//
//
//		//�t���O��true�Ȃ�
//		if (m_Lever_Switch_vec[wall_two_root]->GetIsChange() == true)
//		{
//			
//			//true�Ȃ烊�t�g��ړI�n���W�ɓ�����
//			if (m_Lift_2_vec[wall_two_root]->GetIsMove() == true)
//			{
//			//���K��
//			dir = VNorm(dir);
//			dir = VScale(dir, 0.1f);
//			//�ړ���
//			m_Lift_2_vec[wall_two_root]->SetMove(dir);
//				if (len <= 1.0f)
//				{
//					m_Lift_2_vec[wall_two_root]->SetIsMove(false);
//				}
//				else
//				{
//					wall_twoPos = VAdd(wall_twoPos, dir);
//				}
//
//				m_Lift_2_vec[wall_two_root]->SetPos(wall_twoPos);
//			}
//
//
//			//false�Ȃ猳�̈ʒu�ɖ߂�
//			else if (m_Lift_2_vec[wall_two_root]->GetIsMove() == false)
//			{
//				//���K��
//				dir2 = VNorm(dir2);
//				dir2 = VScale(dir2, 0.1f);
//				//�ړ���
//				m_Lift_2_vec[wall_two_root]->SetMove(dir2);
//
//				if (len2 <= 1.0f)
//				{
//					m_Lift_2_vec[wall_two_root]->SetIsMove(true);
//				}
//				else
//				{
//					wall_twoPos = VAdd(wall_twoPos, dir2);
//
//				}
//				m_Lift_2_vec[wall_two_root]->SetPos(wall_twoPos);
//			}
//		}
//
//		else if (m_Lever_Switch_vec[wall_two_root]->GetIsChange() == false)
//		{
//			m_Lift_2_vec[wall_two_root]->SetPos(wall_twoPos);
//
//			m_Lift_2_vec[wall_two_root]->SetMove(VGet(0.0f, 0.0f, 0.0f));
//
//		}
//
//	}
//
//}
////���o�[���W���擾
//VECTOR CLift_2Manager::GetLeverPos(int num)
//{
//
//	if (m_Lever_Switch_vec[num] != nullptr)
//	{
//		return m_Lever_Switch_vec[num]->GetPos();
//	}
//	else
//	{
//		return VGet(0.0f, 0.0f, 0.0f);
//	}
//}
//
