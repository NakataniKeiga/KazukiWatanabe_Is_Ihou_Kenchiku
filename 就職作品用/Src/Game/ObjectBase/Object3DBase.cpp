//#include"Object3DBase.h"
//
////������
//void CObjectBase::Init()
//{
//	memset(&m_vPos, 0, sizeof(VECTOR));
//	memset(&m_vRot, 0, sizeof(VECTOR));
//	memset(&m_vGravity, 0, sizeof(VECTOR));
//	memset(&m_vOldPos, 0, sizeof(VECTOR));
//	m_iHndl = -1;
//}
////�Z�b�g
//void CObjectBase::Step()
//{
//
//}
//
////�X�V����
//void CObjectBase::Update()
//{
//	MV1SetPosition(m_iHndl, m_vPos);
//	MV1SetRotationXYZ(m_iHndl, m_vRot);
//	MV1SetScale(m_iHndl, m_vScale);
//}
////�`��
//void CObjectBase::Draw()
//{
//	MV1DrawModel(m_iHndl);
//}
////���f���̍폜
//void CObjectBase::DeleteModl()
//{
//	if (m_iHndl == -1)return;
//	MV1DeleteModel(m_iHndl);
//	m_iHndl = -1;
//}
////�I������
//void CObjectBase::Fin()
//{
//	if (m_iHndl == -1) return;
//
//	MV1DeleteModel(m_iHndl);
//	m_iHndl = -1;
//}
////���f���̃��[�h
//bool CObjectBase::LoadModel(const char* pFileName)
//{
//	if (m_iHndl != -1)return false;
//	m_iHndl = MV1LoadModel(pFileName);
//	if (m_iHndl == -1)return false;
//	return true;
//}
////���f���̃R�s�[
//bool CObjectBase::DuplicateModel(int iSrcHndl)
//{
//	if (m_iHndl != -1)return false;
//	m_iHndl = MV1DuplicateModel(iSrcHndl);
//	if (m_iHndl != -1)return false;
//	return true;
//}
//
//VECTOR CObjectBase::GetCeneter()
//{
//	VECTOR vCenter = MV1GetPosition(m_iHndl);
//	vCenter.y += PL_RADIUS;
//	return vCenter;
//}
//
////		���݈ʒu�ɍ��W���Z
////------------------------------
//void CObjectBase::ReflecCollision(VECTOR vAddVec)
//{
//	// �I�[���[����Ȃ��Ȃ牽�����Ȃ�
//	//if (vAddVec.x != 0.0f || vAddVec.y != 0.0f || vAddVec.z != 0.0f) 
//	if (vAddVec.x == 0.0f && vAddVec.y == 0.0f && vAddVec.z == 0.0f)return;
//	VECTOR pos = CObjectBase::GetPos();
//	pos = VAdd(pos, vAddVec);
//		/*m_vPos = VAdd(m_vPos, vAddVec);*/
//	/*MV1SetPosition(m_iHndl, m_vPos);*/
//
//	/*m_vMove.y = 0.0f;*/	// �Ƃ肠�������̂ɂԂ�������d�͂�0��
//	m_vGravity.y = 0.0f;
//	CObjectBase::SetPos(pos);
//}