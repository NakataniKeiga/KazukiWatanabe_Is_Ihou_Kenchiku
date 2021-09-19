#include"StageBase.h"

void CStageBase::Init()
{
	m_isClearFlg = false;
}


void CStageBase::Load()
{

	VECTOR scale = { 0.1f,0.1f,0.1f };

	//スケールセット
	MV1SetScale(f_Handl, scale);	//フィールド

	MV1SetupCollInfo(f_Handl, -1, 1, 1, 1);
}

void CStageBase::Draw()
{
	MV1DrawModel(f_Handl);
}

void CStageBase::Fin()
{
	if (f_Handl == -1)return;
	MV1DeleteModel(f_Handl);
	f_Handl = -1;
}

bool CStageBase::LoadStageModel(const char*pFileName)
{
	if (f_Handl != -1)return false;
	f_Handl = MV1LoadModel(pFileName);
	if (f_Handl == -1)return false;
	return true;
}

