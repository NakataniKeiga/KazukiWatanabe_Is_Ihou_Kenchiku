#include"CamaraManager.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"../Input/Input.h"


#define _DEBUG_

//コンストラクタ
CCameraManager::CCameraManager()
{
	m_state = GAME_PLAYER;
}
//デストラクタ
CCameraManager::~CCameraManager()
{

}
//初期化
void CCameraManager::Init()
{
	m_Playcamera.Init();
	m_Playcamera.SetNearFar(1.0f, 5500.0f);
	m_Golemcamera.Init();
	m_Golemcamera.SetNeartFar(1.0f, 5500.0f);
}
//ロード
void CCameraManager::Load()
{

}
//更新処理
void CCameraManager::Step(CPlayer* player, CGolem* golem)
{
	/*CPlayer* Player = CPlayer::GetInstance();
	CGolem* Golem = CGolem::GetInstance();*/

	//リストの中に
	VECTOR vFocus_p = VAdd(player->GetPos(),VGet(0.0f,3.0f,0.0f));
	//リストの中に
	VECTOR vFocus_g = VAdd(golem->GetPos(), VGet(0.0f, 3.0f, 0.0f));

	switch (m_state) {
	case GAME_PLAYER:	//プレイヤーカメラ
		m_Playcamera.Step(vFocus_p);
		m_Playcamera.Update();
		if (m_state == GAME_PLAYER)
		{
			if (CInputKey::IsPuch(KEY_INPUT_G))
			{
				m_state = GAME_GOLEM;
			}
		}
		break;

	case GAME_GOLEM:	//ゴーレムカメラ
		m_Golemcamera.Step(vFocus_g);
		m_Golemcamera.Update();
		if (m_state == GAME_GOLEM)
		{
			if (CInputKey::IsPuch(KEY_INPUT_G))
			{
				m_state = GAME_PLAYER;
			}
		}
		break;
	}
}
//描画
void CCameraManager::Draw()
{

}
//終了
void CCameraManager::Fin()
{

}
