#include"Lever.h"
#include"../../../Character/Golem/Golem.h"
#include"../../../Character/Player/Player.h"
#include"../../../Field/Field_1/Field_1.h"
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
	/*CPlayer* Player = CPlayer::GetInstance();
	CGolem* Golem = CGolem::GetInstance();

	VECTOR CharacterPos[] = { Player->GetPos(),Golem->GetPos()};
	float CharacterRad[] = { Player->GetRadius(),Golem->GetRadius() };

	for (int chara_index = 0; chara_index < SWITCH_NUM; chara_index++)
	{
		if (CHit::IsHitSphereToSphere(CharacterPos[chara_index], CharacterRad[chara_index], m_vPos, m_fRadius))
		{
			Player->SetLever(true);

			if (CInputKey::IsPuch(KEY_INPUT_SPACE))
			{
				m_iState =(m_iState + 1) % SWITCH_NUM;
				m_Anime.RequestEndLoop(m_iHndl,m_iState, ANIM_SPD);
				SetIsState(m_iState);
			}

		}

	}
	if (m_iState == SWITCH_OFF)
	{
		m_isChange = false;
	}
	else if (m_iState == SWITCH_ON)
	{
		m_isChange = true;
	}*/
	
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