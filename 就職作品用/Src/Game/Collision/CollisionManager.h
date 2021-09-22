#pragma once
#include"DxLib.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"../../Lib/Singleton.h"
#include"../Item/ItemBase.h"
#include"../Gimmick/Box_1/Box_1.h"
#include"../Gimmick/GimmickBase.h"

class CBox_1;

class CCollisionManager
{
private:

	CCollisionManager() {};
	~CCollisionManager() {};

public:

	static VECTOR CollCheckPlayerToStage(CPlayer* player);
	static VECTOR CollCheckPlayerToItem(CPlayer* player);
	static VECTOR CollCheckPlayerToGimmick(CPlayer* player);
	static void CollCheckPlayerHitPosToGimmick(CPlayer* player);

	static VECTOR CollCheckGolemToStage(CGolem* golem);
	static VECTOR CollCheckGolemToGimmick(CGolem* golem);
	static void CollCheckGolemToHitPosGimmick(CGolem* golem);

	static VECTOR CollCchekBoxToGimmick(CBox_1* box);
	static VECTOR CollCheckGimmicekToStage();


};