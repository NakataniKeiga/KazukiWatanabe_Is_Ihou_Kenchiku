#include"GimmickManager.h"
#include"../Field/StageManager.h"

#include"Box_1/Box_1.h"
#include"../Door/Door.h"
#include"Lift_1/Lift_1/Lift_1.h"
#include"Lift_1/Lift_Lever/Lever.h"
#include"Lift_2/Lift_2/Lift_2.h"
#include"Lift_2/Lift_switch/Lift_switch.h"
#include"Needle/Needle.h"



namespace
{
	const int LIFT_NUM[2] = { 2,2 };
	const int LEVER_NUM[2] = { 2,2 };

	const int LIFT_2_NUM[2] = { 2,1};
	const int SWITCH_NUM[2] = { 2,1 };

	const int NEDDLE_NUM[2] = { 24,23 };

	const int BOX_NUM[2] = { 3,1};

};


//初期値
void CGimmickManager::Init()
{
	for (auto& gimmick : m_PoolGimmick)
	{
		gimmick->Init();

		if (gimmick->GetKind() == LIFT_1_GIMMICK)
		{
			m_Lift_1_num++;
		}
		if (gimmick->GetKind() == LIFT_2_GIMMICK)
		{
			m_Lift_2_num++;
		}

	}
}
//モデルロード
void CGimmickManager::Load()
{
	
}


//ギミックの動き
void CGimmickManager::Step()
{
	
	/*CStageManager* m_Stage = CStageManager::GetInstance();*/

	/*m_Box_1Mnager.Step();
	m_Lift_1Manager.Step();
	m_NeedleManager.Step();
	m_Lift_2Manager.Step(m_Box_1Mnager.GetBoxData(),m_Box_1Mnager.GetBoxNum(m_Stage->GetStageNum()));*/

	for (auto& gimmick : m_UseGimmick)
	{
		gimmick->Step();
	}

}

//更新処理
void CGimmickManager::Update()
{	
	for (auto& gimmick : m_UseGimmick)
	{
		gimmick->Update();
	}
}
//描画処理
void CGimmickManager::Draw()
{
		for (auto& gimmick : m_UseGimmick)
		{
			gimmick->Draw();
		}
}
//終了処理
void CGimmickManager::Fin()
{
	for (auto& gimmick : m_UseGimmick)
	{
		gimmick->Fin();
	}

	m_PoolGimmick.clear();
}

void CGimmickManager::Reqest(taggimmick kind)
{
	CStageManager* Stage = CStageManager::GetInstance();

	VECTOR GIMMICK_POS;

	int StageType = Stage->GetStageNum();
	

	if (kind == 0)
	{
		for (int box_index = 0; box_index < BOX_NUM[StageType]; ++box_index)
		{
			GIMMICK_POS = Stage->GetManeBone(6, box_index);
			Create(kind, GIMMICK_POS);
		}
	}
	else if (kind == 1)
	{
		
			GIMMICK_POS = Stage->GetManeBone(11,0);
			Create(kind, GIMMICK_POS);
		
	}
	else if (kind == 2)
	{
		for (int lift_index = 0; lift_index < LIFT_NUM[StageType]; ++lift_index)
		{
			GIMMICK_POS = Stage->GetManeBone(2, lift_index);
			Create(kind, GIMMICK_POS);
		}
	}
	else if (kind == 3)
	{
		for (int lift_index = 0; lift_index < LIFT_2_NUM[StageType]; ++lift_index)
		{
			GIMMICK_POS = Stage->GetManeBone(8, lift_index);
			Create(kind, GIMMICK_POS);
		}
	}
	else if (kind == 4)
	{
		for (int lever_index = 0; lever_index < LEVER_NUM[StageType]; ++lever_index)
		{
			GIMMICK_POS = Stage->GetManeBone(1, lever_index);
			Create(kind, GIMMICK_POS);
		}
	}
	else if (kind == 5)
	{
		for (int switch_index = 0; switch_index < SWITCH_NUM[StageType]; ++switch_index)
		{
			GIMMICK_POS = Stage->GetManeBone(10,switch_index);
			Create(kind, GIMMICK_POS);
		}
	}
	else if (kind == 6)
	{
		for (int needle_index = 0; needle_index < NEDDLE_NUM[StageType]; ++needle_index)
		{
			GIMMICK_POS = Stage->GetManeBone(7, needle_index);
			Create(kind, GIMMICK_POS);
		}
	}

	/*Create(kind, GIMMICK_POS);*/
}

void CGimmickManager::Create(taggimmick kind, VECTOR pos)
{
	/*CGimmickBase* gimmick;

	gimmick = new CGimmickBase;
	
	gimmick->SetPos(pos);
	gimmick->SetKind(kind);

	m_PoolGimmick.push_back(gimmick);*/

	switch (kind)
	{
	case BOX_GIMMICK:
	{
		CBox_1* box;
		box = new CBox_1;

		

		box->SetPos(pos);
		box->SetKind(kind);

		m_PoolGimmick.push_back(box);
		m_UseGimmick.push_back(box);
	}
	break;
	case DOOR_GIMMICK:
	{
		CDoor* door;
		door = new CDoor;

		door->SetPos(pos);
		door->SetKind(kind);

		m_PoolGimmick.push_back(door);
		m_UseGimmick.push_back(door);
	}
	break;
	case LIFT_1_GIMMICK:
	{
		CLift_1* lift_1;
		lift_1 = new CLift_1;

		lift_1->SetPos(pos);
		lift_1->SetKind(kind);

		m_PoolGimmick.push_back(lift_1);
		m_UseGimmick.push_back(lift_1);
	}
	break;
	case LIFT_2_GIMMICK:
	{
		CLift_2* lift_2;
		lift_2 = new CLift_2;

		lift_2->SetPos(pos);
		lift_2->SetKind(kind);

		m_PoolGimmick.push_back(lift_2);
		m_UseGimmick.push_back(lift_2);
	}
	break;
	case LEVER_GIMMICK:
	{
		CLever* lever;
		lever = new CLever;

		lever->SetPos(pos);
		lever->SetKind(kind);

		m_PoolGimmick.push_back(lever);
		m_UseGimmick.push_back(lever);
	}
	break;
	case SWITCH_GIMMICK:
	{
		CLift_Switch* leverswitch;
		leverswitch = new CLift_Switch;

		leverswitch->SetPos(pos);
		leverswitch->SetKind(kind);

		m_PoolGimmick.push_back(leverswitch);
		m_UseGimmick.push_back(leverswitch);
	}
	break;
	case NEEDLE_GIMMICK:
	{
		CNeedle* needle;
		needle = new CNeedle;

		needle->SetPos(pos);
		needle->SetKind(kind);

		m_PoolGimmick.push_back(needle);
		m_UseGimmick.push_back(needle);
	}
	break;
	}


}