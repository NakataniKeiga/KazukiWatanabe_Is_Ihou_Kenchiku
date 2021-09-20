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
		// “–‚½‚Á‚½ƒ|ƒŠƒSƒ“‚Ì”‚¾‚¯ŒJ•Ô‚·
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	ƒqƒbƒg‚µ‚½ƒ|ƒŠƒSƒ“‚Æƒqƒbƒg‚µ‚½•¨‘Ì‚Ì‚ß‚è‚ñ‚¾‹——£‚ğ‹‚ß‚é
				VECTOR temp = VSub(player->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//‰Ÿ‚µo‚·ŒvZˆ—
				length = player->GetRadius() - length;
				// ‚ß‚è‚ñ‚¾‹——£•ª‚¾‚¯ŠO‚É‰Ÿ‚µo‚·@‰Ÿ‚µo‚·•ûŒü‚Í–@ü‚Ì•ûŒü
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// “–‚½‚è”»’èŒ‹‰Ê‚ğ”jŠü‚·‚é
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
		// “–‚½‚Á‚½ƒ|ƒŠƒSƒ“‚Ì”‚¾‚¯ŒJ•Ô‚·
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	ƒqƒbƒg‚µ‚½ƒ|ƒŠƒSƒ“‚Æƒqƒbƒg‚µ‚½•¨‘Ì‚Ì‚ß‚è‚ñ‚¾‹——£‚ğ‹‚ß‚é
				VECTOR temp = VSub(golem->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//‰Ÿ‚µo‚·ŒvZˆ—
				length = golem->GetRadius() - length;
				// ‚ß‚è‚ñ‚¾‹——£•ª‚¾‚¯ŠO‚É‰Ÿ‚µo‚·@‰Ÿ‚µo‚·•ûŒü‚Í–@ü‚Ì•ûŒü
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// “–‚½‚è”»’èŒ‹‰Ê‚ğ”jŠü‚·‚é
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
	
			MV1_COLL_RESULT_POLY_DIM ret;//“–‚½‚è”»’èŒ‹‰ÊŠi”[\‘¢‘Ì
			ret = MV1CollCheck_Sphere(GimmickHandle, -1, PlayerCenter, PlayerRadius);//“–‚½‚è”»’èŒ‹‰ÊŠi”[

			if (gimmick->GetKind() == BOX_GIMMICK)
			{
				gimmick->PlayerHit(player);
			}

			if (ret.HitNum != 0)
			{

			
				// “–‚½‚Á‚½ƒ|ƒŠƒSƒ“‚Ì”‚¾‚¯ŒJ•Ô‚·
				for (int i = 0; i < ret.HitNum; i++) {

					if (ret.Dim[i].HitFlag == 1) {

					
						gimmick->PlayerHit(player);

						//	ƒqƒbƒg‚µ‚½ƒ|ƒŠƒSƒ“‚Æƒqƒbƒg‚µ‚½•¨‘Ì‚Ì‚ß‚è‚ñ‚¾‹——£‚ğ‹‚ß‚é
						VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
						float length = VSize(temp);
						//‰Ÿ‚µo‚·ŒvZˆ—
						length = PlayerRadius - length;
						// ‚ß‚è‚ñ‚¾‹——£•ª‚¾‚¯ŠO‚É‰Ÿ‚µo‚·@‰Ÿ‚µo‚·•ûŒü‚Í–@ü‚Ì•ûŒü
						temp = VScale(ret.Dim[i].Normal, length);
						vOut = VAdd(vOut, temp);
					}
				}
				// “–‚½‚è”»’èŒ‹‰Ê‚ğ”jŠü‚·‚é
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

		

		MV1_COLL_RESULT_POLY_DIM ret;//“–‚½‚è”»’èŒ‹‰ÊŠi”[\‘¢‘Ì
		ret = MV1CollCheck_Sphere(GimmickHandle, -1, GolemCenter, GolemRadius);//“–‚½‚è”»’èŒ‹‰ÊŠi”[

		if (ret.HitNum != 0)
		{
			// “–‚½‚Á‚½ƒ|ƒŠƒSƒ“‚Ì”‚¾‚¯ŒJ•Ô‚·
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	ƒqƒbƒg‚µ‚½ƒ|ƒŠƒSƒ“‚Æƒqƒbƒg‚µ‚½•¨‘Ì‚Ì‚ß‚è‚ñ‚¾‹——£‚ğ‹‚ß‚é
					VECTOR temp = VSub(GolemCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//‰Ÿ‚µo‚·ŒvZˆ—
					length = GolemRadius - length;
					// ‚ß‚è‚ñ‚¾‹——£•ª‚¾‚¯ŠO‚É‰Ÿ‚µo‚·@‰Ÿ‚µo‚·•ûŒü‚Í–@ü‚Ì•ûŒü
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);
				}
			}
			// “–‚½‚è”»’èŒ‹‰Ê‚ğ”jŠü‚·‚é
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


		MV1_COLL_RESULT_POLY_DIM ret;//“–‚½‚è”»’èŒ‹‰ÊŠi”[\‘¢‘Ì
		ret = MV1CollCheck_Sphere(GimmickHandle, -1,BoxCenter,BoxRadius);//“–‚½‚è”»’èŒ‹‰ÊŠi”[

		if (ret.HitNum != 0)
		{
			// “–‚½‚Á‚½ƒ|ƒŠƒSƒ“‚Ì”‚¾‚¯ŒJ•Ô‚·
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	ƒqƒbƒg‚µ‚½ƒ|ƒŠƒSƒ“‚Æƒqƒbƒg‚µ‚½•¨‘Ì‚Ì‚ß‚è‚ñ‚¾‹——£‚ğ‹‚ß‚é
					VECTOR temp = VSub(BoxCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//‰Ÿ‚µo‚·ŒvZˆ—
					length = BoxRadius - length;
					// ‚ß‚è‚ñ‚¾‹——£•ª‚¾‚¯ŠO‚É‰Ÿ‚µo‚·@‰Ÿ‚µo‚·•ûŒü‚Í–@ü‚Ì•ûŒü
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);
				}
			}
			// “–‚½‚è”»’èŒ‹‰Ê‚ğ”jŠü‚·‚é
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
