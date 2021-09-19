#include"Zenmai.h"
#include"../../Character/Player/Player.h"
#include"../../Field/StageManager.h"
#include"../../Character/Golem/Golem.h"
#include"../../Input/Input.h"
#include"../../../Lib/math/Hit/Hit.h"


static const char* ZENMAI_PATH_S = { "Data/model/zennmai/zennmai.x" };

//初期化
void CZenmai::Init()
{

	m_kind = ZENMAI_ITEM;
	m_vRot = VGet(-1.5f, 1.0f, 0.0f);
	m_vScale = VGet(0.1f, 0.1f, 0.1f);
	m_fRadius = 1.0f;
	m_isAlive = true;


	Load();
}
//ロード処理
void CZenmai::Load()
{
	m_iHndl = MV1LoadModel(ZENMAI_PATH_S);
}
//メイン処理
void CZenmai::Step()
{
	/*CPlayer* m_Player = CPlayer::GetInstance();
	CGolem* m_Golem = CGolem::GetInstance();

	if (CHit::IsHitSphereToSphere(m_Player->GetPos(), m_Player->GetRadius(), m_vPos, m_fRadius))
	{
		m_Player->SetZenmaiHave(true);
		m_isAlive = false;
		
	}*/
}
//更新処理
void CZenmai::Update()
{
	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
}
//描画処理
void CZenmai::Draw()
{
	if (m_isAlive == true)
	{
		MV1DrawModel(m_iHndl);
	}
}
//終了処理
void CZenmai::Fin()
{
	MV1DeleteModel(m_iHndl);
}