#include"Lift_switch.h"
#include"../../../Character/Player/Player.h"
#include"../../../Character/Golem/Golem.h"
#include"../../../../Lib/math/Hit/Hit.h"
#include"../../../Input/Input.h"

static const char* LEVER_PATH_S = { "Data/model/Lever/Floorswitch.x" };
const VECTOR SWITCH_SCALE = { 0.03f, 0.03f, 0.03f };
const float SWITCH_RADIUS = 2.5f;


//‰Šú‰»
void CLift_Switch::Init()
{
	m_kind = SWITCH_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_fRadius = SWITCH_RADIUS;
	m_vScale = SWITCH_SCALE;
	m_State = SWITCH_OFF;
	Load();
}
//ƒ[ƒhˆ—
void CLift_Switch::Load()
{
	m_iHndl = MV1LoadModel(LEVER_PATH_S);
}

//ƒƒCƒ“ˆ—
void CLift_Switch::Step()
{
	/*CPlayer* Player = CPlayer::GetInstance();

	VECTOR PlayerPos = Player->GetPos();
	float PlayerRadius = Player->GetRadius();



	for (int chara_index = 0; chara_index < SWITCH_NUM; chara_index++)
	{
		if (CHit::IsHitSphereToSphere(PlayerPos, PlayerRadius, m_vPos, m_fRadius))
		{
			m_State = SWITCH_ON;
		}
		else
		{
			m_State = SWITCH_OFF;
		}
	}

	if (m_State == SWITCH_OFF)
	{
		IsChange = false;
	}
	if (m_State == SWITCH_ON)
	{
		IsChange = true;
	}*/

	
}

void CLift_Switch::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}

void CLift_Switch::Draw()
{
	MV1DrawModel(m_iHndl);
}

void CLift_Switch::Fin()
{
	MV1DeleteModel(m_iHndl);
}