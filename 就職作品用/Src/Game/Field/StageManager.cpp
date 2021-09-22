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
//コンストラクタ
CStageManager::CStageManager()
{
	m_StageData = nullptr;
	m_StageNum = 1;
	m_Clearflag = false;
	Init();
}


//初期化
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
//描画処理
void CStageManager::Draw()
{
	m_StageData->Draw();
}
//終了処理
void CStageManager::Fin()
{
	m_StageData->Fin();

	delete m_StageData;
	m_StageData = nullptr;
}
//ステージ切り替え
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

//ステージから各ギミックの座標を取得
VECTOR CStageManager::GetManeBone(int handle_num, int num)
{
	return 	m_StageData->GetBone(handle_num, num);
}
//ステージのエネミーの移動ボーンを取得
VECTOR CStageManager::GetRootBone(int root_num,int num)
{
	return m_StageData->GetRoot(root_num, num);
}
//エネミーのボーンの総数を取得
int CStageManager::GetRootNum(int root_num)
{
	return m_StageData->GetRootNum(root_num);
}
//ステージハンドル取得
int CStageManager::GetHandle()
{
	return m_StageData->GetStageHandle();
}
//フラグ取得
bool CStageManager::GetStageClearFlg()
{
	return m_StageData->GetIsClear();
}
//フラグセット
void CStageManager::SetStageClearFlg(bool flg)
{
	return m_StageData->SetIsClear(flg);
}
