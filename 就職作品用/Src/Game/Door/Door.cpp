#include"Door.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"

#include"../Collision/CollisionManager.h"

#include"../Input/Input.h"
#include"../../Lib/math/Hit/Hit.h"

static const char* DOOR_PATH_S = { "Data/model/Door/Door.x" };
static const float ANIM_SPD = 0.1f;

//初期化
void CDoor::Init()
{
	m_kind = DOOR_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_vRot.y = DX_PI_F;
	m_fRadius = 2.5f;
	m_vScale = VGet(0.1f, 0.1f, 0.1f);
	m_isOpen = true;
	Load();
}
//ロード処理
void CDoor::Load()
{
	m_iHndl = MV1LoadModel(DOOR_PATH_S);
}
//メイン処理
void CDoor::Step()
{
	//CPlayer* Player = CPlayer::GetInstance();
	//CGolem* Golem = CGolem::GetInstance();


	//if (Player->GetHave() == true)
	//{
	//	if (CHit::IsHitSphereToSphere(Player->GetPos(), Player->GetRadius(), m_vPos, m_fRadius))
	//	{
	//		if (CInputKey::IsPuch(KEY_INPUT_SPACE))
	//		{
	//			if (m_isOpen == true)
	//			{
	//				/*CAnimation::RequestEndLoop(1, ANIM_SPD);*/
	//				m_isOpen = false;
	//			}
	//		}
	//	}
	//}
}
//更新処理
void CDoor::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
	/*CAnimation::UpdateAnim();*/
}
//描画処理
void CDoor::Draw()
{
	MV1DrawModel(m_iHndl);
}
//終了処理
void CDoor::Fin()
{
	MV1DeleteModel(m_iHndl);
}

void CDoor::PlayerHit(CPlayer* player)
{



}