//#include"DoorManager.h"
//#include"../Field/StageManager.h"
//#include"../../Lib/math/Hit/Hit.h"
////�R���X�g���N�^
//CDoorManager::CDoorManager()
//{
//	m_Door = nullptr;
//
//	m_Door = new CDoor;
//
//	Init();
//}
////������
//void CDoorManager::Init()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	m_Door->Init();
//	//�X�e�[�W������̍��W���擾
//	VECTOR DoorPos = Stage->GetManeBone(11, 0);
//
//
//	m_Door->SetPos(DoorPos);	
//	
//}
////���[�h����
//void CDoorManager::Load()
//{
//	m_Door->Load();
//}
////���C������
//void CDoorManager::Step()
//{
//	m_Door->Step();
//
//}
////�X�V����
//void CDoorManager::Update()
//{
//	m_Door->Update();
//
//}
//
////�`�揈��
//void CDoorManager::Draw()
//{
//	m_Door->Draw();
//}
////�I������
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