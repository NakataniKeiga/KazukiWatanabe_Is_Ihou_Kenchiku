//#include"ExitManager.h"
//
//#include"../Field/StageManager.h"
//
//#include"../Character/Player/Player.h"
//
//#include"../../Lib/math/Hit/Hit.h"
//
//#include"../Collision/CollisionManager.h"
////�R���X�g���N�^
//CExitManager::CExitManager()
//{
//	m_Exit = nullptr;
//	m_Exit = new CExit;
//
//	Init();
//}
////������
//void CExitManager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_Exit->Init();
//	//�X�e�[�W����o���̍��W���擾
//	VECTOR ExitPos = Stage->GetManeBone(5, 0);
//	m_Exit->SetPos(ExitPos);
//}
////���[�h����
//void CExitManager::Load()
//{
//	m_Exit->Load();
//}
////���C������
//void CExitManager::Step()
//{
//	CPlayer* Player = CPlayer::GetInstance();
//	CStageManager* Stage = CStageManager::GetInstance();
//	m_Exit->Step();
//	//���������Ă����Ԃ�true�Ȃ�
//	if (Player->GetHave() == true)
//	{
//		if (CHit::IsHitSphereToSphere(Player->GetPos(), Player->GetRadius(), m_Exit->GetPos(), m_Exit->GetRadius()))
//		{
//			m_Exit->SetIscene(true);
//		}
//		if (m_Exit->GetIscene() == true)
//		{
//			//�X�e�[�W�N���A�t���O��ON�ɂ����̃X�e�[�W�w
//			Stage->SetStageClearFlg(true);
//		}
//	}
//}
////�X�V����
//void CExitManager::Update()
//{
//
//	m_Exit->Update();
//
//}
////�`�揈��
//void CExitManager::Draw()
//{
//	m_Exit->Draw();
//}
////�I������
//void CExitManager::Fin()
//{
//	if (m_Exit != nullptr)
//	{
//		m_Exit->Fin();
//		delete m_Exit;
//		m_Exit = nullptr;
//	}
//}