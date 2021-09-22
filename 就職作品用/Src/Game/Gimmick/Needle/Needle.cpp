#include"Needle.h"
#include"../../Character/Player/Player.h"
#include"../../../Lib/math/Hit/Hit.h"
#include"../../Input/Input.h"


static const char* NEEDLE_PATH_S = { "Data/model/Needle/Needle.x" };
const VECTOR PLAYER_SCALE = { 0.05f, 0.05f, 0.05f };
const float NEEDLE_RADIUS = 2.5f;


//初期化
void CNeedle::Init()
{
	m_kind = NEEDLE_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	//m_state = UP_NEEDLE;
	m_fRadius = NEEDLE_RADIUS;
	/*m_iNeedletime = 0;*/
	m_isChange = false;
	
	m_vScale = PLAYER_SCALE;
	Load();

}
//モデルロード
void CNeedle::Load()
{
	m_iHndl = MV1LoadModel(NEEDLE_PATH_S);
	
}
//更新処理
void CNeedle::Step()
{
	//CPlayer* Player = CPlayer::GetInstance();

	////プレイヤーのノックバック処理
	//if (GetIsChange() == false)
	//{

	//	if (CHit::IsHitSphereToSphere(Player->GetPos(), Player->GetRadius(), m_vPos, m_fRadius))
	//	{

	//		VECTOR needlePos = GetCeneter();
	//		VECTOR PlayerPos = Player->GetCeneter();

	//		VECTOR vec = VSub(PlayerPos, needlePos);

	//		float len = VSize(vec);


	//		if (len < 10.0f)
	//		{
	//			Player->SetHitPoint((Player->GetHitPoint() - 1));
	//		}

	//	}
	//}


	//switch (m_state)
	//{
	//case 0:
	//{
	//	if(m_iNeedletime==0)
	//	/*	CAnimation::RequestEndLoop(0, 1.0);*/
	//	
	//	if (m_iNeedletime > 120) 
	//	{
	//		/*CAnimation::RequestEndLoop(2, 1.0);*/
	//			m_state = DOWN_NEEDLE;
	//			SetIsChange(false);
	//			m_iNeedletime = 0;
	//	}
	//	
	//}
	//break;
	//case 2:
	//{
	//	if (m_iNeedletime == 0)
	//	/*	CAnimation::RequestLoop(2, 1.0);*/

	//	if (m_iNeedletime > 120) 
	//	{
	//	/*	CAnimation::RequestEndLoop(0, 1.0);*/
	//			m_state = UP_NEEDLE;	
	//			SetIsChange(true);
	//			m_iNeedletime = 0;
	//	}
	//	
	//}
	//break;
	//}
	//m_iNeedletime++;

}
//更新処理
void CNeedle::Update()
{
	/*CAnimation::UpdateAnim();*/
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}
//描画処理
void CNeedle::Draw()
{
	MV1DrawModel(m_iHndl);
}
//終了処理
void CNeedle::Fin()
{
	MV1DeleteModel(m_iHndl);
}

VECTOR CNeedle::GetCeneter()
{
	VECTOR vCenter = MV1GetPosition(m_iHndl);
	vCenter.y += 1.0f;
	return vCenter;
}

void CNeedle::PlayerHit(CPlayer* player)
{


}

void CNeedle::PlayerHitPosHit(CPlayer* player)
{

}

void CNeedle::GolemHit(CGolem* golem)
{

}

void CNeedle::GolemHitPosHit(CGolem* golem)
{

}