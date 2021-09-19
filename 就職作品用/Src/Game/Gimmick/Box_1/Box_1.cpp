#include"Box_1.h"
#include"../../../Lib/math/Hit/Hit.h"
#include"../../Input/Input.h"
#include"../../Character/Player/Player.h"

static const char* BOX_PATH_S = { "Data/model/Box/Box.x" };

const VECTOR BOX_SCALE = { 0.01f, 0.01f, 0.01f };
const float BOX_RADIUS = 1.5f;
const float GRAVITY_SPEED = 0.00f;


//初期化
void CBox_1::Init()
{
	m_kind = BOX_GIMMICK;
	memset(&m_vRot, 0, sizeof(VECTOR));
	memset(&m_vGravity, 0, sizeof(VECTOR));
	m_vMove = VGet(0.0f, 0.0f, 0.0f);
	m_vScale = BOX_SCALE;
	m_fRadius = BOX_RADIUS;
	m_fGravity = GRAVITY_SPEED;
	m_isHave = false;
	Load();
}
//ロード処理
void CBox_1::Load()
{
	m_iHndl = MV1LoadModel(BOX_PATH_S);
}
//メイン処理
void CBox_1::Step()
{
	/*CPlayer* Player = CPlayer::GetInstance();

	if (CInputKey::IsPuch(KEY_INPUT_SPACE))
	{
		if (CHit::IsHitSphereToSphere(Player->GetHitPos(), Player->GetRadius(), m_vPos, m_fRadius))
		{
			
			if (Player->GetShove() == true)
			{
				m_isHave = false;
				Player->SetShove(false);
			}
			else if (Player->GetShove() == false)
			{
				m_isHave = true;
				Player->SetShove(true);
			}
			
		}
	}

		if (m_isHave == true)
		{
			VECTOR PlayerHand = VAdd(Player->GetHitPos(), VGet(0.0f, 2.0f, 0.0f));
			m_vPos = VAdd(PlayerHand, m_vMove);
		}
		else
		{
			m_vMove.z = 0.0f;
			m_vMove.z = 0.0f;
		}*/

}
//
void CBox_1::Update()
{
	if (m_isHave == false)
	{
		m_vGravity.y -= m_fGravity;
	}
	m_vPos = VAdd(m_vPos, m_vGravity);

	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);

}
//描画処理
void CBox_1::Draw()
{
	MV1DrawModel(m_iHndl);
}
//終了処理
void CBox_1::Fin()
{
	MV1DeleteModel(m_iHndl);
}
