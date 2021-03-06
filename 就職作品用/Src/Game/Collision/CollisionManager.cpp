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
		// 当たったポリゴンの数だけ繰返す
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
				VECTOR temp = VSub(player->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//押し出す計算処理
				length = player->GetRadius() - length;
				// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// 当たり判定結果を破棄する
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
		// 当たったポリゴンの数だけ繰返す
		for (int i = 0; i < ret.HitNum; i++) {

			if (ret.Dim[i].HitFlag == 1) {
				//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
				VECTOR temp = VSub(golem->GetCeneter(), ret.Dim[i].HitPosition);
				float length = VSize(temp);
				//押し出す計算処理
				length = golem->GetRadius() - length;
				// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
				temp = VScale(ret.Dim[i].Normal, length);
				vOut = VAdd(vOut, temp);

				/*	player->SetJump(true);*/
			}
		}
	}
	// 当たり判定結果を破棄する
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

			MV1_COLL_RESULT_POLY_DIM ret;//当たり判定結果格納構造体
			ret = MV1CollCheck_Sphere(GimmickHandle, -1, PlayerCenter, PlayerRadius);//当たり判定結果格
			if (ret.HitNum != 0)
			{

			
				// 当たったポリゴンの数だけ繰返す
				for (int i = 0; i < ret.HitNum; i++) {

					if (ret.Dim[i].HitFlag == 1) {

						
						//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
 						VECTOR temp = VSub(PlayerCenter, ret.Dim[i].HitPosition);
						float length = VSize(temp);
						//押し出す計算処理
						length = PlayerRadius - length;
						// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
						temp = VScale(ret.Dim[i].Normal, length);
						vOut = VAdd(vOut, temp);

						/*gimmick->PlayerHit(player);*/
					}
				}
				// 当たり判定結果を破棄する
				MV1CollResultPolyDimTerminate(ret);

			}
		
	}
	
	return vOut;

}

void CCollisionManager::CollCheckPlayerHitPosToGimmick(CPlayer* player)
{
	VECTOR PlayerHitPos = player->GetHitPos();
	float PlayerRadius = player->GetRadius();


	CGimmickManager* gimmick = CGimmickManager::GetInstance();
	std::list<CGimmickBase*>gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	for (auto gimmick : gimmick_pool)
	{
		VECTOR GimmickPos = gimmick->GetPos();
		float GimmickRadius = gimmick->GetRadius();

		if (CHit::IsHitSphereToSphere(PlayerHitPos, PlayerRadius, GimmickPos, GimmickRadius))
		{
			gimmick->PlayerHitPosHit(player);
		}

	}

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

		

		MV1_COLL_RESULT_POLY_DIM ret;//当たり判定結果格納構造体
		ret = MV1CollCheck_Sphere(GimmickHandle, -1, GolemCenter, GolemRadius);//当たり判定結果格納

		if (ret.HitNum != 0)
		{
			// 当たったポリゴンの数だけ繰返す
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
					VECTOR temp = VSub(GolemCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//押し出す計算処理
					length = GolemRadius - length;
					// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);

					gimmick->GolemHit(golem);
				}
			}
			// 当たり判定結果を破棄する
			MV1CollResultPolyDimTerminate(ret);
		}
		

	}

	return vOut;
}

void CCollisionManager::CollCheckGolemToHitPosGimmick(CGolem* golem)
{
	VECTOR GolemCenter = golem->GetCeneter();
	float GolemRadius = golem->GetRadius();

	CGimmickManager* gimmick = CGimmickManager::GetInstance();
	std::list<CGimmickBase*>gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	for (auto gimmick : gimmick_pool)
	{
		VECTOR GimmickPos = gimmick->GetPos();
		float GimmickRadius = gimmick->GetRadius();

		if (CHit::IsHitSphereToSphere(GolemCenter, GolemRadius, GimmickPos, GimmickRadius))
		{
			gimmick->GolemHitPosHit(golem);
		}
	}
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


		MV1_COLL_RESULT_POLY_DIM ret;//当たり判定結果格納構造体
		ret = MV1CollCheck_Sphere(GimmickHandle, -1,BoxCenter,BoxRadius);//当たり判定結果格納

		if (ret.HitNum != 0)
		{
			// 当たったポリゴンの数だけ繰返す
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
					VECTOR temp = VSub(BoxCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//押し出す計算処理
					length = BoxRadius - length;
					// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);
				}
			}
			// 当たり判定結果を破棄する
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

	CGimmickManager* gimmick = CGimmickManager::GetInstance();

	std::list<CGimmickBase*> gimmick_pool = gimmick->GetUsePool();

	VECTOR	vOut = { 0.0f, 0.0f, 0.0f };

	for (auto& gimmick : gimmick_pool)
	{

		VECTOR GimmickCenter = gimmick->GetCenter();
		float GimmickRadius = gimmick->GetRadius();


		MV1_COLL_RESULT_POLY_DIM ret;//当たり判定結果格納構造体
		ret = MV1CollCheck_Sphere(Stage_handle, -1, GimmickCenter, GimmickRadius);//当たり判定結果格納

		if (ret.HitNum != 0)
		{
			// 当たったポリゴンの数だけ繰返す
			for (int i = 0; i < ret.HitNum; i++) {

				if (ret.Dim[i].HitFlag == 1) {
					//	ヒットしたポリゴンとヒットした物体のめり込んだ距離を求める
					VECTOR temp = VSub(GimmickCenter, ret.Dim[i].HitPosition);
					float length = VSize(temp);
					//押し出す計算処理
					length = GimmickRadius - length;
					// めり込んだ距離分だけ外に押し出す　押し出す方向は法線の方向
					temp = VScale(ret.Dim[i].Normal, length);
					vOut = VAdd(vOut, temp);
				}
			}
			// 当たり判定結果を破棄する
			MV1CollResultPolyDimTerminate(ret);
		}


	}
	return vOut;

}
