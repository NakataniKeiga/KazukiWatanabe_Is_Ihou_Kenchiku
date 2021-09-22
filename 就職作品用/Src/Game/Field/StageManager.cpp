#include"StageManager.h"
#include"StageBase.h"
#include <DxLib.h>
#include"Field_1/Field_1.h"
#include"Field_2/Field_2.h"
#include"../Scene/SceneManager.h"
#include"../Scene/ScenePlay/ScenePlay.h"
#include"../Character/Player/Player.h"
#include"../Common.h"


static const int STAGE_MAX_NUM = 2;
//�R���X�g���N�^
CStageManager::CStageManager()
{
	m_StageData = nullptr;
	m_StageNum = 1;
	m_Clearflag = false;
	Init();
}


//������
void CStageManager::Init()
{
	if (m_StageNum == 0)
	{
		m_StageData = new CField_1;

	}
	if (m_StageNum == 1) 
	{
		m_StageData = new CField_2;
	}
	m_StageData->Init();
	m_StageData->Load();

}
//�`�揈��
void CStageManager::Draw()
{
	m_StageData->Draw();
}
//�I������
void CStageManager::Fin()
{
	m_StageData->Fin();

	delete m_StageData;
	m_StageData = nullptr;
}
//�X�e�[�W�؂�ւ�
void CStageManager::ChengeStage()
{
	m_StageNum++;
	//CPlayer* Player = CPlayer::GetInstance();

	//if (Player->GetIsAlive() == true)
	//{
	//	if (m_StageNum == STAGE_MAX_NUM)
	//	{
	//		m_Clearflag = true;
	//		m_StageNum = 0;
	//	}
	//}
}

//�X�e�[�W����e�M�~�b�N�̍��W���擾
VECTOR CStageManager::GetManeBone(int handle_num, int num)
{
	return 	m_StageData->GetBone(handle_num, num);
}
//�X�e�[�W�̃G�l�~�[�̈ړ��{�[�����擾
VECTOR CStageManager::GetRootBone(int root_num,int num)
{
	return m_StageData->GetRoot(root_num, num);
}
//�G�l�~�[�̃{�[���̑������擾
int CStageManager::GetRootNum(int root_num)
{
	return m_StageData->GetRootNum(root_num);
}
//�X�e�[�W�n���h���擾
int CStageManager::GetHandle()
{
	return m_StageData->GetStageHandle();
}
//�t���O�擾
bool CStageManager::GetStageClearFlg()
{
	return m_StageData->GetIsClear();
}
//�t���O�Z�b�g
void CStageManager::SetStageClearFlg(bool flg)
{
	return m_StageData->SetIsClear(flg);
}
