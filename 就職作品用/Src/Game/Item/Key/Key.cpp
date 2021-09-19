#include"Key.h"
#include"../../Character/Player/Player.h"
#include"../../../Lib/math/Hit/Hit.h"

static const char* KEY_PATH_S = { "Data/model/Key/key.x" };

//初期化
void CKey::Init()
{
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_kind = KEY_ITEM;
	m_vScale = VGet(0.05f, 0.05f, 0.05f);
	m_fRadius = 1.0f;
	m_isAlive = true;
	Load();
}
//ロード処理
void CKey::Load()
{
	m_iHndl = MV1LoadModel(KEY_PATH_S);
}
//メイン処理
void CKey::Step()
{


}
//更新処理
void CKey::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}
//描画処理
void CKey::Draw()
{
	if(m_isAlive == true)
	{
		MV1DrawModel(m_iHndl);
	}
}
//終了処理
void CKey::Fin()
{
	MV1DeleteModel(m_iHndl);
}

//void CKey::HitPlayer(CPlayer* player)
//{
//	if (CHit::IsHitSphereToSphere(player->GetPos(), player->GetRadius(), m_vPos, m_fRadius))
//	{
//		player->SetHave(true);
//		m_isAlive = false;
//	}
//}