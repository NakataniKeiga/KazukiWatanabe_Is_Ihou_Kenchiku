#include"Exit.h"
#include"../Character/Player/Player.h"
#include"../Field/StageManager.h"
#include"../../Lib/math/Hit/Hit.h"

static const char*EXIT_PATH_S = { "Data/model/Exit/Exit.x" };

void CExit::Init()
{
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_fRadius = 2.5f;
	m_vScale = VGet(0.2f, 0.2f, 0.2f);
	m_isScene = false;
	Load();
}

void CExit::Load()
{
	m_iHndl = MV1LoadModel(EXIT_PATH_S);
}

void CExit::Step()
{
	//CPlayer* Player = CPlayer::GetInstance();
	//CStageManager* Stage = CStageManager::GetInstance();
	////���������Ă����Ԃ�true�Ȃ�
	//if (Player->GetHave() == true)
	//{
	//if (CHit::IsHitSphereToSphere(Player->GetPos(), Player->GetRadius(), m_vPos,m_fRadius))
	//{
	//	m_isScene = true;
	//}
	//if (m_isScene== true)
	//{
	//	//�X�e�[�W�N���A�t���O��ON�ɂ����̃X�e�[�W�w
	//	Stage->SetStageClearFlg(true);
	//}
	//}

}

void CExit::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}

void CExit::Draw()
{
	MV1DrawModel(m_iHndl);
}

void CExit::Fin()
{
	MV1DeleteModel(m_iHndl);
}

