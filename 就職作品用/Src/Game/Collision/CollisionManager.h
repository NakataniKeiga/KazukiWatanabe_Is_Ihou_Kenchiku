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

	




	////�X�e�[�W�ƃI�u�W�F�N�g�̓����蔻��
	//VECTOR CheckObjectHitStage(VECTOR vCenetr,float fRadius);
	////�v���C���[�ƃI�u�W�F�N�̓����蔻��
	//VECTOR PlayerObjectHitCheck(int m_iHandle);
	////�v���C���[�Ɠ����I�u�W�F�N�g�̓����蔻��
	//VECTOR PlayerMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove);
	////�S�[�����ƃI�u�W�F�N�g�̓����蔻��
	//VECTOR GolemObjectHitCheck(int m_Handle);
	////�S�[�����Ɠ����I�u�W�F�N�g�̓����蔻��
	//VECTOR GolemMoveObjectHitCheck(int m_iHandle, VECTOR m_vMove);
	////���ƃI�u�W�F�N�g�̓����蔻��
	//VECTOR BoxMoveObjectHitCheck(CBox_1* Box, int m_iHandle, VECTOR m_vMove);


};