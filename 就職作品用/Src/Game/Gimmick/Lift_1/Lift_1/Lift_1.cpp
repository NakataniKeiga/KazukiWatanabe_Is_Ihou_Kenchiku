#include"Lift_1.h"
#include"../../../Character/Player/Player.h"
#include"../../../Field/Field_1/Field_1.h"
#include"../../../Input/Input.h"
//#include"../../../Gimmick/GimmickManager.h"


static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };

void CLift_1::Init()
{
	m_kind = LIFT_1_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_vMove = VGet(0.0f, 0.0f, 0.0f);
	m_vScale = VGet(0.13f, 0.13f, 0.13f);
	m_isChange = false;
	Load();
}

void CLift_1::Load()
{
	m_iHndl = MV1LoadModel(WALL_PATH_S);
}         

void CLift_1::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
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

