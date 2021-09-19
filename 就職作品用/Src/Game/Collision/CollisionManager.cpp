#include"DxLib.h"
#include"../../Lib/math/Hit/Hit.h"
#include"CollisionManager.h"
#include"../Item/ItemManager.h"
#include"../Gimmick/GimmickManager.h"
#include"../Gimmick/Box_1/Box_1.h"
#include"../Field/StageManager.h"


VECTOR CCollisionManager::CollCheckPlayerToStage(CPlayer* player)
{
	CStageManager* Stage = CStageManager::GetInstance();

	int stage_handle = Stage->GetHandle();

	VECTOR vOut = { 0.0f,0.0f,0.0f };

	MV1_COLL_RESULT_POLY_DIM ret;
	ret = MV1CollCheck_Sphere(stage_handle, -1, player->GetCeneter(), player->GetRadius());

	if (ret.HitNum != 0)
	{
		// ���������|���S���̐������J�Ԃ�
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
				VECTOR temp = VSub(player->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//�����o���v�Z����
				length = player->GetRadius() - length;
				// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// �����蔻�茋�ʂ�j������
	MV1CollResultPolyDimTerminate(ret);

	return vOut;
	

}

VECTOR CCollisionManager::CollCheckGolemToStage(CGolem* golem)
{
	CStageManager* Stage = CStageManager::GetInstance();

	int stage_handle = Stage->GetHandle();

	VECTOR vOut = { 0.0f,0.0f,0.0f };

	MV1_COLL_RESULT_POLY_DIM ret;
	ret = MV1CollCheck_Sphere(stage_handle, -1, golem->GetCeneter(), golem->GetRadius());

	if (ret.HitNum != 0)
	{
		// ���������|���S���̐������J�Ԃ�
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
				VECTOR temp = VSub(golem->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//�����o���v�Z����
				length = golem->GetRadius() - length;
				// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// �����蔻�茋�ʂ�j������
	MV1CollResultPolyDimTerminate(ret);

	return vOut;

}

VECTOR CCollisionManager::CollCheckPlayerToItem(CPlayer* player)
{
	VECTOR PlayerPos = player->GetPos();
	float PlayerRadius = player->GetRadius();

	VECTOR vOut = { 0.0f,0.0f,0.0f };

	CItemManager* Item = CItemManager::GetInstance();

	std::list<CItemBase*> item_pool = Item->GetUsePool();

	for (auto item : item_pool)
	{
		VECTOR ItemPos = item->GetPos();

		float ItemRadius = item->GetRadius();

		if (CHit::IsHitSphereToSphere(PlayerPos, PlayerRadius, ItemPos, ItemRadius))
		{
			item->SetIsAlive(false);

		}

	}

	return vOut;

}

VECTOR CCollisionManager::CollCheckPlayerToGimmick(CPlayer* player)
{
	VECTOR PlayerPos = player->GetPos();
	VECTOR PlayerCenter = player->GetCeneter();
	float PlayerRadius = player->GetRadius();
	
	CGimmickManager* gimmick = CGimmickManager::GetInstance();

	std::list<CGimmickBase*> gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	

	for (auto gimmick : gimmick_pool)
	{
	
		int GimmickHandle = gimmick->GetHandle();
		

		MV1_COLL_RESULT_POLY_DIM ret;//�����蔻�茋�ʊi�[�\����
		ret = MV1CollCheck_Sphere(GimmickHandle, -1, PlayerCenter, PlayerRadius);//�����蔻�茋�ʊi�[

		if (ret.HitNum != 0)
		{
			// ���������|���S���̐������J�Ԃ�
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
					VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//�����o���v�Z����
					length = PlayerRadius - length;
					// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);

					/*	player->SetJump(true);*/
				}
			}
		}
		// �����蔻�茋�ʂ�j������
		MV1CollResultPolyDimTerminate(ret);

		return vOut;
	}
	return vOut;

}

VECTOR CCollisionManager::CollCheckGolemToGimmick(CGolem* golem)
{

	VECTOR GolemCenter = golem->GetCeneter();
	float GolemRadius = golem->GetRadius();


	CGimmickManager* gimmick = CGimmickManager::GetInstance();

	std::list<CGimmickBase*> gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	for (auto gimmick : gimmick_pool)
	{
		int GimmickHandle = gimmick->GetHandle();

		

		MV1_COLL_RESULT_POLY_DIM ret;//�����蔻�茋�ʊi�[�\����
		ret = MV1CollCheck_Sphere(GimmickHandle, -1, GolemCenter, GolemRadius);//�����蔻�茋�ʊi�[

		if (ret.HitNum != 0)
		{
			// ���������|���S���̐������J�Ԃ�
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
					VECTOR temp = VSub(GolemCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//�����o���v�Z����
					length = GolemRadius - length;
					// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);

					/*	player->SetJump(true);*/
				}
			}
		}
		// �����蔻�茋�ʂ�j������
		MV1CollResultPolyDimTerminate(ret);

		return vOut;
	}

	return vOut;
}



////�X�e�[�W�ƃI�u�W�F�N�g�̓����蔻��
//VECTOR CCollisionManager::CheckObjectHitStage(VECTOR vCenetr, float fRadius)
//{
//	CStageManager* Stage = CStageManager::GetInstance();
//
//	int StageHandle = Stage->GetHandle();
//
//	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };	//�@���̂��w�i�ɂ߂荞�񂾋���
//	bool m_isHitFlag = false;
//
//
//	/*MV1RefreshCollInfo();*/
//
//	MV1_COLL_RESULT_POLY_DIM ret;//�����蔻�茋�ʊi�[�\����
//	ret = MV1CollCheck_Sphere(StageHandle, -1, vCenetr, fRadius);//�����蔻�茋�ʊi�[
//
//	if (ret.HitNum != 0)
//	{
//		// ���������|���S���̐������J�Ԃ�
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//				//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
//				VECTOR temp = VSub(vCenetr, ret.Dim[i].HitPosition);
//				float length = VSize(temp);
//				//�����o���v�Z����
//				length = fRadius - length;
//				// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
//				temp = VScale(ret.Dim[i].Normal, length);
//				vOut = VAdd(vOut, temp);
//
//				/*	player->SetJump(true);*/
//			}
//		}
//	}
//	// �����蔻�茋�ʂ�j������
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}
////�v���C���[�ƃI�u�W�F�N�̓����蔻��
//VECTOR CCollisionManager::PlayerObjectHitCheck(int m_iHandle)
//{
//	VECTOR vOut = { 0.0f,0.0f,0.0f };
//	bool m_isHitFlg = false;
//
//	CPlayer* Player = CPlayer::GetInstance();
//
//	VECTOR PlayerCenter = Player->GetCeneter();
//	float PlayerRadius = Player->GetRadius();
//
//	MV1RefreshCollInfo(m_iHandle, -1);
//
//	MV1_COLL_RESULT_POLY_DIM ret;
//	ret = MV1CollCheck_Sphere(m_iHandle, -1, PlayerCenter, PlayerRadius);
//
//	if (ret.HitNum != 0)
//	{
//
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//
//				VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
//
//				float length = VSize(temp);
//
//				length = PlayerRadius - length;
//
//				temp = VScale(ret.Dim[i].Normal, length);
//
//				vOut = VAdd(vOut, temp);
//
//			}
//		}
//	}
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}
////�v���C���[�Ɠ����I�u�W�F�N�g�̓����蔻��
//VECTOR CCollisionManager::PlayerMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove)
//{
//	VECTOR vOut = { 0.0f,0.0f,0.0f };
//	bool m_isHitFlg = false;
//
//	CPlayer* Player = CPlayer::GetInstance();
//
//	VECTOR PlayerCenter = Player->GetCeneter();
//	float PlayerRadius = Player->GetRadius();
//
//	MV1RefreshCollInfo(m_iHandle, -1);
//
//	MV1_COLL_RESULT_POLY_DIM ret;
//	ret = MV1CollCheck_Sphere(m_iHandle, -1, PlayerCenter, PlayerRadius);
//
//	if (ret.HitNum != 0)
//	{
//
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//
//				VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
//
//				VECTOR PlayerPos = Player->GetPos();
//
//				VECTOR wallMove = m_vMove;
//
//				PlayerPos = VAdd(PlayerPos, wallMove);
//
//				Player->SetPos(PlayerPos);
//
//				float length = VSize(temp);
//
//				length = PlayerRadius - length;
//
//				temp = VScale(ret.Dim[i].Normal, length);
//
//				vOut = VAdd(vOut, temp);
//
//			}
//		}
//	}
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}
////�S�[�����ƃI�u�W�F�N�̓����蔻��
//VECTOR CCollisionManager::GolemObjectHitCheck(int m_iHandle)
//{
//	VECTOR vOut = { 0.0f,0.0f,0.0f };
//	bool m_isHitFlg = false;
//
//	CGolem* Golem = CGolem::GetInstance();
//
//	VECTOR GolemCenter = Golem->GetCeneter();
//	float GolemRadius = Golem->GetRadius();
//
//	MV1RefreshCollInfo(m_iHandle, -1);
//
//	MV1_COLL_RESULT_POLY_DIM ret;
//	ret = MV1CollCheck_Sphere(m_iHandle, -1, GolemCenter, GolemRadius);
//
//	if (ret.HitNum != 0)
//	{
//
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//
//				VECTOR temp = VSub(GolemCenter, ret.Dim[i].HitPosition);
//
//				float length = VSize(temp);
//
//				length = GolemRadius - length;
//
//				temp = VScale(ret.Dim[i].Normal, length);
//
//				vOut = VAdd(vOut, temp);
//
//			}
//		}
//	}
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}
////�S�[�����Ɠ����I�u�W�F�N�g�̓����蔻��
//VECTOR CCollisionManager::GolemMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove)
//{
//	VECTOR vOut = { 0.0f,0.0f,0.0f };
//	bool m_isHitFlg = false;
//
//	CGolem* Golem = CGolem::GetInstance();
//
//	VECTOR GolemCenter = Golem->GetCeneter();
//	float GolemRadius = Golem->GetRadius();
//
//	MV1RefreshCollInfo(m_iHandle, -1);
//
//	MV1_COLL_RESULT_POLY_DIM ret;
//	ret = MV1CollCheck_Sphere(m_iHandle, -1, GolemCenter, GolemRadius);
//
//	if (ret.HitNum != 0)
//	{
//
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//
//				VECTOR temp = VSub(GolemCenter, ret.Dim[i].HitPosition);
//
//				VECTOR GolemPos = Golem->GetPos();
//
//				VECTOR wallMove = m_vMove;
//
//				GolemPos = VAdd(GolemPos, wallMove);
//
//				Golem->SetPos(GolemPos);
//
//				float length = VSize(temp);
//
//				length = GolemRadius - length;
//
//				temp = VScale(ret.Dim[i].Normal, length);
//
//				vOut = VAdd(vOut, temp);
//
//			}
//		}
//	}
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}
////
//VECTOR CCollisionManager::BoxMoveObjectHitCheck(CBox_1* Box, int m_iHandle, VECTOR m_vMove)
//{
//	VECTOR vOut = { 0.0f,0.0f,0.0f };
//	bool m_isHitFlg = false;
//
//	VECTOR BoxPos = Box->GetPos();
//	float BoxRadius = Box->GetRadius();
//
//	MV1RefreshCollInfo(m_iHandle, -1);
//
//	MV1_COLL_RESULT_POLY_DIM ret;
//	ret = MV1CollCheck_Sphere(m_iHandle, -1, BoxPos, BoxRadius);
//
//	if (ret.HitNum != 0)
//	{
//
//		for (int i = 0; i < ret.HitNum; i++) {
//
//			if (ret.Dim[i].HitFlag == 1) {
//
//				VECTOR temp = VSub(BoxPos,ret.Dim[i].HitPosition);
//
//				VECTOR wallMove = m_vMove;
//
//				BoxPos = VAdd(BoxPos, wallMove);
//
//				Box->SetPos(BoxPos);
//
//				float length = VSize(temp);
//
//				length = BoxRadius - length;
//
//				temp = VScale(ret.Dim[i].Normal, length);
//
//				vOut = VAdd(vOut, temp);
//
//			}
//		}
//	}
//	MV1CollResultPolyDimTerminate(ret);
//
//	return vOut;
//}