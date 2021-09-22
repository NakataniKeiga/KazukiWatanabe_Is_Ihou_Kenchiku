#include"Lift_1.h"
#include"../../../Character/Player/Player.h"
#include"../../../Input/Input.h"
#include"../../../Field/StageManager.h"
#include"../../GimmickManager.h"
//#include"../../../Gimmick/GimmickManager.h"


static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };

void CLift_1::Init()
{
	

	m_kind = LIFT_1_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_vMove = VGet(0.0f, 0.0f, 0.0f);
	m_vScale = VGet(0.013f, 0.013f, 0.013f);
	m_isChange = true;



	CStageManager* Stage = CStageManager::GetInstance();
	CGimmickManager* Lift_1_num = CGimmickManager::GetInstance();

	int liftnum = Lift_1_num->GetLift_1_num();
	m_vLiftPos = Stage->GetManeBone(2, liftnum);
	m_vLiftMovePos = Stage->GetManeBone(3, liftnum);

	Load();
}

void CLift_1::Load()
{
	m_iHndl = MV1LoadModel(WALL_PATH_S);
	MV1SetupCollInfo(m_iHndl);
}         

void CLift_1::Step()
{
	//VECTOR lift_Pos = m_vPos;
	//VECTOR 

	VECTOR dir1 = VSub(m_vLiftPos, m_vPos);

	VECTOR dir2 = VSub(m_vLiftMovePos, m_vPos);

	float len = VSize(dir1);
	float len2 = VSize(dir2);

	if (m_isChange == true)
	{
		dir1 = VNorm(dir1);
		dir1 = VScale(dir1, 0.2f);

		SetMove(dir1);

		if (len < 0.1f)
		{
			dir1 = VGet(0.0f, 0.0f, 0.0f);
			SetMove(dir1);
		}
		else
		{
			m_vPos = VAdd(m_vPos, dir1);
		}

		SetPos(m_vPos);
	}
	else if (m_isChange == false)
	{
		dir2 = VNorm(dir2);
		dir2 = VScale(dir2, 0.2f);
		SetMove(dir2);

		if (len2 <= 0.1f)
		{
			dir2 = VGet(0.0f, 0.0f, 0.0f);
			
			SetMove(dir2);
		}
		else
		{
			m_vPos = VAdd(m_vPos, dir2);
		}
		SetPos(m_vPos);
	}

}

void CLift_1::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
	MV1RefreshCollInfo(m_iHndl);
}

void CLift_1::Draw()
{
	MV1DrawModel(m_iHndl);
}

void CLift_1::Fin()
{
	MV1DeleteModel(m_iHndl);

}

void CLift_1::Stage_1SetScale(int number)
{
	VECTOR scale[] = { VGet(0.13f, 0.13f, 0.13f),VGet(0.03f, 0.03f, 0.03f),
	};

	m_vScale = scale[number];
}

void CLift_1::Stage_2SetScale(int number)
{
	VECTOR scale[] = { VGet(0.13f, 0.13f, 0.13f),VGet(0.03f, 0.03f, 0.03f), };

	m_vScale = scale[number];
}

void CLift_1::PlayerHit(CPlayer* player)
{
	VECTOR PlayerPos = player->GetPos();
	PlayerPos = VAdd(PlayerPos, m_vMove);

	player->SetPos(PlayerPos);

}

void CLift_1::PlayerHitPosHit(CPlayer* player)
{

	if (player->GetLever() == true)
	{
		m_isChange = true;
	}
	else
	{
		m_isChange = false;
	}
}

void CLift_1::GolemHit(CGolem* golem)
{
	VECTOR GolemPos = golem->GetPos();
	GolemPos = VAdd(GolemPos, m_vMove);

	golem->SetPos(GolemPos);

}

void CLift_1::GolemHitPosHit(CGolem* golem)
{
	/*if (golem->GetLever() == true)
	{
		m_isChange = true;
	}
	else
	{
		m_isChange = false;
	}*/

}

