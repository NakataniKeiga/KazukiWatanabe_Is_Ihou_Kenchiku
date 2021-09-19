#pragma once
#include"DxLib.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"../../Lib/Singleton.h"
#include"../Item/ItemBase.h"
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

	static VECTOR CollCheckGolemToStage(CGolem* golem);
	static VECTOR CollCheckGolemToGimmick(CGolem* golem);

	




	////ステージとオブジェクトの当たり判定
	//VECTOR CheckObjectHitStage(VECTOR vCenetr,float fRadius);
	////プレイヤーとオブジェクの当たり判定
	//VECTOR PlayerObjectHitCheck(int m_iHandle);
	////プレイヤーと動くオブジェクトの当たり判定
	//VECTOR PlayerMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove);
	////ゴーレムとオブジェクトの当たり判定
	//VECTOR GolemObjectHitCheck(int m_Handle);
	////ゴーレムと動くオブジェクトの当たり判定
	//VECTOR GolemMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove);
	////箱とオブジェクトの当たり判定
	//VECTOR BoxMoveObjectHitCheck(CBox_1* Box, int m_iHandle, VECTOR m_vMove);


};