#include"Lever.h"
#include"../../../Character/Golem/Golem.h"
#include"../../../Character/Player/Player.h"
#include"../../GimmickManager.h"
#include"../../../Field/StageManager.h"
#include"../../../../Lib/math/Hit/Hit.h"
#include"../../../Input/Input.h"

static const char* LEVER_PATH_S = { "Data/model/Lever/Lever.x" };
const VECTOR LEVER_SCALE = { 0.0007f, 0.0007f, 0.0007f };
const float LEVER_RADIUS = 5.0f;
static const float ANIM_SPD = 1.0f;

//‰Šú‰»
void CLever::Init()
{
	m_kind = LEVER_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_vScale = LEVER_SCALE;
	m_iState = SWITCH_OFF;
	m_isChange = false;
	m_fRadius = LEVER_RADIUS;

	CStageManager* Stage = CStageManager::GetInstance();
	CGimmickManager* Lift_num = CGimmickManager::GetInstance();

	int levernum = Lift_num->GetLift_1_num();
	m_vLeverPos = Stage->GetManeBone(2, levernum);
	

	Load();
}
//ƒ[ƒhˆ—
void CLever::Load()
{
	m_iHndl = MV1LoadModel(LEVER_PATH_S);
}
//ƒƒCƒ“ˆ—
void CLever::Step()
{
	
}

void CLever::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
	m_Anime.UpdateAnim(m_iHndl);
}

void CLever::Draw()
{
	MV1DrawModel(m_iHndl);
}

void CLever::Fin()
{
	MV1DeleteModel(m_iHndl);
}

void CLever::PlayerHit(CPlayer* player)
{



}

void CLever::PlayerHitPosHit(CPlayer* player)
{

	if (CInputKey::IsPuch(KEY_INPUT_SPACE))
	{
 	m_iState = (m_iState + 1) % SWITCH_NUM;
	m_Anime.RequestEndLoop(m_iHndl, m_iState, ANIM_SPD);
	SetIsState(m_iState);
	}

	
	if (m_iState == SWITCH_OFF)
	{
 		m_isChange = false;
		player->SetLever(false);

	}
	else if (m_iState == SWITCH_ON)
	{
		m_isChange = true;
		player->SetLever(true);
	}
}

void CLever::GolemHit(CGolem* golem)
{

}

void CLever::GolemHitPosHit(CGolem* golem)
{
	/*if (CInputKey::IsPuch(KEY_INPUT_SPACE))
	{
		m_iState = (m_iState + 1) % SWITCH_NUM;
		m_Anime.RequestEndLoop(m_iHndl, m_iState, ANIM_SPD);
		SetIsState(m_iState);
	}


	if (m_iState == SWITCH_OFF)
	{
		m_isChange = false;
		golem->SetLever(false);

	}
	else if (m_iState == SWITCH_ON)
	{
		m_isChange = true;
		golem->SetLever(true);
	}*/
}