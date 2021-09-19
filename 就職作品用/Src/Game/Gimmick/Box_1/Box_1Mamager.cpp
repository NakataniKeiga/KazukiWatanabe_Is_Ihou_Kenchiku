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
////�R���X�g���N�^
//CBox_1Manager::CBox_1Manager()
//{
//	m_Box = nullptr;
//	m_Box = new CBox_1[BOX_MAX];
//}
////������
//void CBox_1Manager::Init()
//{
//
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_iStageType = Stage->GetStageNum();
//
//	//��������
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Init();
//		//�X�e�[�W���甠���W���擾
//		VECTOR boxPos = Stage->GetManeBone(6, box_index);
//		m_Box[box_index].SetPos(boxPos);
//
//	}
//
//}
////���[�h����
//void CBox_1Manager::Load()
//{
//	//���̃R�s�[
//	int Boxhndl = MV1LoadModel(BOX_PATH_S);
//	//for���ŉ񂵂����R�s�[����
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].DuplicateModel(Boxhndl);
//	}
//}
////���C������
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
////�X�V����
//void CBox_1Manager::Update()
//{
//	//���X�V����
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Update();
//	}
//}
////�`�揈��
//void CBox_1Manager::Draw()
//{
//	for (int box_index = 0; box_index < BOX_NUM[m_iStageType]; box_index++)
//	{
//		m_Box[box_index].Draw();
//	}
//}
////�I������
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
