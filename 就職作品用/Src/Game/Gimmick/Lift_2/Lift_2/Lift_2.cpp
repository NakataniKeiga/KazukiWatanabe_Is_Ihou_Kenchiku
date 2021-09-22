#include"Lift_2.h"
#include"../../../Field/StageManager.h"
#include"../../GimmickManager.h"

static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };
const VECTOR LIFT_SCALE = { 0.06f, 0.06f, 0.06f };

void CLift_2::Init()
{
	m_kind = LIFT_2_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_isMove = true;
	m_isChange = false;
	m_vScale = LIFT_SCALE;

	CStageManager* Stage = CStageManager::GetInstance();
	CGimmickManager* Lift_2_num = CGimmickManager::GetInstance();

	int lift_2_num = Lift_2_num->GetLift_2_num();
	m_vLift_2_Pos = Stage->GetManeBone(8, lift_2_num);
	m_vLift_2_MOVE = Stage->GetManeBone(9, lift_2_num);
	Load();
}

void CLift_2::Load()
{
	m_iHndl = MV1LoadModel(WALL_PATH_S);
}

void CLift_2::Step()
{

VECTOR dir1 = VSub(m_vLift_2_Pos, m_vPos);
VECTOR dir2 = VSub(m_vLift_2_MOVE, m_vPos);

float len = VSize(dir1);
float len2 = VSize(dir2);

	if (m_isChange == false)
	{
		if (m_isMove == true)
		{
			dir1 = VNorm(dir1);
			dir1 = VScale(dir1, 0.1f);

			SetMove(dir1);
			if (len <= 1.0f)
			{
				SetIsMove(false);
			}
			else
			{
				m_vPos = VAdd(m_vPos, dir1);
			}

			SetPos(m_vPos);

		}
		else if (m_isMove == false)
		{
			dir2 = VNorm(dir2);
			dir2 = VScale(dir2, 0.1f);

			SetMove(dir2);

			if (len2 <= 1.0f)
			{
				SetIsMove(true);
			}
			else
			{
				m_vPos = VAdd(m_vPos, dir2);
			}
			SetPos(m_vPos);
		}
	}
	else if (m_isChange == true)
	{
		SetPos(m_vPos);
		SetMove(VGet(0.0f, 0.0f, 0.0f));
	}


}

void CLift_2::Update()
{

	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}

void CLift_2::Draw()
{
	MV1DrawModel(m_iHndl);
}

void CLift_2::Fin()
{
	MV1DeleteModel(m_iHndl);
}

void CLift_2::PlayerHit(CPlayer* player)
{
	if (player->GetSwitch() == true)
	{
		m_isChange = true;
	}
	else if (player->GetSwitch() == false)
	{
		m_isChange = false;
	}


}

void CLift_2::Stage_1SetScale(int number)
{
	VECTOR scale[] = { LIFT_SCALE,VGet(0.09f,0.7f,0.07f) };

	m_vScale = scale[number];
}

void CLift_2::PlayerHitPosHit(CPlayer* player)
{

}

void CLift_2::GolemHit(CGolem* golem)
{

}

void CLift_2::GolemHitPosHit(CGolem* golem)
{

}