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
//		//�����Z�b�g
//		m_iRootID[enemy_index] = 1;
//		VECTOR targetPos = Stage->GetRootBone(enemy_index, 0);
//
//		m_Enemy_vec[enemy_index]->SetPos(targetPos);
//
//	}
//		
//	
//}
////�f�[�^�֘A�̃��[�h
//void CEnemyManager::Load()
//{
//	int Enemy_handle = MV1LoadModel(MODEL_PATH_S);
//
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->DuplicateModel(Enemy_handle);
//	}
//}
////���C������
//void CEnemyManager::Step()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Step();
//	}
//	Move();
//}
////�X�V����
//void CEnemyManager::Update()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Update();
//	}
//}
////�`�揈��
//void CEnemyManager::Draw()
//{
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		m_Enemy_vec[enemy_index]->Draw();
//	}
//}
////�I������
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
////�G�̓���
//void CEnemyManager::Move()
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	CPlayer* Player = CPlayer::GetInstance();
//
//	for (int enemy_index = 0; enemy_index < ENEMY_NUM[m_iStageType]; enemy_index++)
//	{
//		//�G�l�~�[�̌��ݍ��W
//		VECTOR EnemyPos = m_Enemy_vec[enemy_index]->GetPos();
//		//
//		VECTOR TargetPos = Stage->GetRootBone(enemy_index, m_iRootID[enemy_index]);
//		
//		VECTOR PlayerPos = Player->GetPos();
//		//�G�l�~�[�ƃ��[�g���W�̋���,�������v��
//		VECTOR dir = VSub(TargetPos,EnemyPos);
//		float len = VSize(dir);
//
//
//		//�v���C���[�Ƃ̋���
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
//			//�ǂ������Ă��鑬�x���Z�b�g
//			dir2 = VScale(dir2, 0.3f);
//
//			//���W���Z�b�g����
//			EnemyPos = VAdd(EnemyPos, dir2);
//			m_Enemy_vec[enemy_index]->SetPos(EnemyPos);
//
//			//�p�x�����킹��
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
//				//�ړI�n���W���߂������玟�̖ړI���W�Ɉړ�������
//				m_Enemy_vec[enemy_index]->SetPos(TargetPos);
//				m_iRootID[enemy_index] = (m_iRootID[enemy_index] + 1) % Stage->GetRootNum(enemy_index);
//			}
//			else
//			{
//				//�ړI�n���W�Ɍ������Ĉړ�
//				dir.y = 0.0f;
//				dir = VNorm(dir);
//				dir = VScale(dir, 0.1f);
//				EnemyPos = VAdd(EnemyPos, dir);
//				m_Enemy_vec[enemy_index]->SetPos(EnemyPos);
//			}
//			//�p�x���Z�b�g
//			float rot = atan2f(-dir.x, -dir.z);
//			m_Enemy_vec[enemy_index]->SetRot(VGet(0.0f, rot, 0.0f));
//
//		}
//
//	}
//
//}