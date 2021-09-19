#include"Lift_2.h"

static const char* WALL_PATH_S = { "Data/model/Wall/Wall.x" };
const VECTOR LIFT_SCALE = { 0.06f, 0.06f, 0.06f };

void CLift_2::Init()
{
	m_kind = LIFT_2_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_isMove = true;
	m_isChange = false;
	m_vScale = LIFT_SCALE;
	Load();
}

void CLift_2::Load()
{
	m_iHndl = MV1LoadModel(WALL_PATH_S);
}

void CLift_2::Step()
{

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

void CLift_2::Stage_1SetScale(int number)
{
	VECTOR scale[] = { LIFT_SCALE,VGet(0.09f,0.7f,0.07f) };

	m_vScale = scale[number];
}