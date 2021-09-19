#include"CharacterBase.h"

//初期化
void CCharacterBase::Init()
{
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vRot, 0, sizeof(VECTOR));
	memset(&m_vMove, 0, sizeof(VECTOR));
	memset(&m_vGravity, 0, sizeof(VECTOR));
	m_iHandle = -1;
}
//セット
void CCharacterBase::Step()
{

}
//更新処理
void CCharacterBase::Update()
{
	MV1SetPosition(m_iHandle, m_vPos);
	MV1SetRotationXYZ(m_iHandle, m_vRot);
	MV1SetScale(m_iHandle, m_vScale);
}
//描画
void CCharacterBase::Draw()
{
	MV1DrawModel(m_iHandle);
}
//モデルの削除
void CCharacterBase::DeleteModl()
{
	if (m_iHandle == -1)return;
	MV1DeleteModel(m_iHandle);
	m_iHandle = -1;
}
//終了処理
void CCharacterBase::Fin()
{
	if (m_iHandle == -1) return;

	MV1DeleteModel(m_iHandle);
	m_iHandle = -1;
}
//モデルのロード
bool CCharacterBase::LoadModel(const char* pFileName)
{
	if (m_iHandle != -1)return false;
	m_iHandle = MV1LoadModel(pFileName);
	if (m_iHandle == -1)return false;
	return true;
}
//モデルのコピー
bool CCharacterBase::DuplicateModel(int iSrcHndl)
{
	if (m_iHandle != -1)return false;
	m_iHandle = MV1DuplicateModel(iSrcHndl);
	if (m_iHandle != -1)return false;
	return true;
}

VECTOR CCharacterBase::GetCeneter()
{
	VECTOR vCenter = MV1GetPosition(m_iHandle);
	vCenter.y += PL_RADIUS;
	return vCenter;
}

//		現在位置に座標加算
//------------------------------
void CCharacterBase::ReflecCollision(VECTOR vAddVec)
{
	// オールゼじゃないなら何もしない
	if (vAddVec.x == 0.0f && vAddVec.y == 0.0f && vAddVec.z == 0.0f)return;
	VECTOR pos = CCharacterBase::GetPos();
	pos = VAdd(pos, vAddVec);

	// とりあえず物体にぶつかったら重力を0に
	m_vGravity.y = 0.0f;
	CCharacterBase::SetPos(pos);
}