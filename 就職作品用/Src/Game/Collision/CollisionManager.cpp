#include"DxLib.h"
#include"../../Lib/math/Hit/Hit.h"
#include"CollisionManager.h"
#include"../Item/ItemManager.h"
#include"../Gimmick/GimmickManager.h"
#include"../Gimmick/GimmickCommon.h"
#include"../Field/StageManager.h"
#include<list>


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
			item->PlayerHit(player);
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

	for (auto& gimmick : gimmick_pool)
	{
	
		int GimmickHandle = gimmick->GetHandle();
	
			MV1_COLL_RESULT_POLY_DIM ret;//�����蔻�茋�ʊi�[�\����
			ret = MV1CollCheck_Sphere(GimmickHandle, -1, PlayerCenter, PlayerRadius);//�����蔻�茋�ʊi�[

			if (gimmick->GetKind() == BOX_GIMMICK)
			{
				gimmick->PlayerHit(player);
			}

			if (ret.HitNum != 0)
			{

			
				// ���������|���S���̐������J�Ԃ�
				for (int i = 0; i < ret.HitNum; i++) {

					if (ret.Dim[i].HitFlag == 1) {

					
						gimmick->PlayerHit(player);

						//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
						VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
						float length = VSize(temp);
						//�����o���v�Z����
						length = PlayerRadius - length;
						// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
						temp = VScale(ret.Dim[i].Normal, length);
						vOut = VAdd(vOut, temp);
					}
				}
				// �����蔻�茋�ʂ�j������
				MV1CollResultPolyDimTerminate(ret);

			}
		
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
				}
			}
			// �����蔻�茋�ʂ�j������
			MV1CollResultPolyDimTerminate(ret);
		}
		

	}

	return vOut;
}

VECTOR CCollisionManager::CollCchekBoxToGimmick(CBox_1* box)
{
	VECTOR BoxCenter = box->GetCenter();
	float BoxRadius = box->GetRadius();

	CGimmickManager* gimmick = CGimmickManager::GetInstance();

	std::list<CGimmickBase*> gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	for (auto& gimmick : gimmick_pool)
	{

		int GimmickHandle = gimmick->GetHandle();


		MV1_COLL_RESULT_POLY_DIM ret;//�����蔻�茋�ʊi�[�\����
		ret = MV1CollCheck_Sphere(GimmickHandle, -1,BoxCenter,BoxRadius);//�����蔻�茋�ʊi�[

		if (ret.HitNum != 0)
		{
			// ���������|���S���̐������J�Ԃ�
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	�q�b�g�����|���S���ƃq�b�g�������̂̂߂荞�񂾋��������߂�
					VECTOR temp = VSub(BoxCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//�����o���v�Z����
					length = BoxRadius - length;
					// �߂荞�񂾋����������O�ɉ����o���@�����o�������͖@���̕���
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);
				}
			}
			// �����蔻�茋�ʂ�j������
			MV1CollResultPolyDimTerminate(ret);
		}



	/*for (auto& gimmick2 : gimmick_pool)
		{
			if (gimmick == gimmick2)
				continue;



		}*/
	}

	return vOut;

}

VECTOR CCollisionManager::CollCheckGimmicekToStage()
{
	CStageManager* Stage = CStageManager::GetInstance();

	int Stage_handle = Stage->GetHandle();






}
