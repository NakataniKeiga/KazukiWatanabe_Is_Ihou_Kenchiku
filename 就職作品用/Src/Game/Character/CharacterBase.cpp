#include"CharacterBase.h"

//������
void CCharacterBase::Init()
{
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vRot, 0, sizeof(VECTOR));
	memset(&m_vMove, 0, sizeof(VECTOR));
	memset(&m_vGravity, 0, sizeof(VECTOR));
	m_iHandle = -1;
}
//�Z�b�g
void CCharacterBase::Step()
{

}
//�X�V����
void CCharacterBase::Update()
{
	MV1SetPosition(m_iHandle, m_vPos);
	MV1SetRotationXYZ(m_iHandle, m_vRot);
	MV1SetScale(m_iHandle, m_vScale);
}
//�`��
void CCharacterBase::Draw()
{
	MV1DrawModel(m_iHandle);
}
//���f���̍폜
void CCharacterBase::DeleteModl()
{
	if (m_iHandle == -1)return;
	MV1DeleteModel(m_iHandle);
	m_iHandle = -1;
}
//�I������
void CCharacterBase::Fin()
{
	if (m_iHandle == -1) return;

	MV1DeleteModel(m_iHandle);
	m_iHandle = -1;
}
//���f���̃��[�h
bool CCharacterBase::LoadModel(const char* pFileName)
{
	if (m_iHandle != -1)return false;
	m_iHandle = MV1LoadModel(pFileName);
	if (m_iHandle == -1)return false;
	return true;
}
//���f���̃R�s�[
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

//		���݈ʒu�ɍ��W���Z
//------------------------------
void CCharacterBase::ReflecCollision(VECTOR vAddVec)
{
	// �I�[���[����Ȃ��Ȃ牽�����Ȃ�
	if (vAddVec.x == 0.0f && vAddVec.y == 0.0f && vAddVec.z == 0.0f)return;
	VECTOR pos = CCharacterBase::GetPos();
	pos = VAdd(pos, vAddVec);

	// �Ƃ肠�������̂ɂԂ�������d�͂�0��
	m_vGravity.y = 0.0f;
	CCharacterBase::SetPos(pos);
}