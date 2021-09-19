#include "Field_1.h"


//フィールドのハンドル
static const char* field_handl("Data/model/Field/Field/StageOne/new Stage.x");

//ボーンの座標	

static const char* root_handl("Data/model/ModelPos/Enemy/root.x");//ルートのボーン座標
static const char* lever_handl("Data/model/ModelPos/Lift_lever/stage_one/lever_born_.x");//レバー(縦移動)設置座標
static const char* wall_handl("Data/model/ModelPos/Lift_wall/stage_one/wallPosition/wallpos_.x");//壁設置座標
static const char* wall_move_handl("Data/model/ModelPos/Lift_wall/stage_one/wallMove/wallposMove_.x");//壁(目的地移動)設置座標
static const char* item_handl("Data/model/ModelPos/Item/stage_one/Key.x");//アイテム設置座標
static const char* exit_handl("Data/model/ModelPos/Exit/stage_one/ExitPos.x");//ゴール設置座標
static const char* box_handl("Data/model/ModelPos/Box/stage_one/Box_born.x");//箱のボーン座標

static const char* transparentwall_handl("Data/model/ModelPos/TransparentWall/TransparentWall.x");//透明な壁のボーン座標
static const char* needle_handl("Data/model/ModelPos/Needle/stage_one/NeedlePos.x");

static const char* box_twohandl("Data/model/Field/Box_two/2stageBox_twoPos.x");//箱2のボーン座標
static const char* switch_handl("Data/model/Field/Switch/Switch_born.x");//スイッチのボーン座標
static const char* wall_two_handl("Data/model/ModelPos/Lift_wall_two/stage_one/wallPosition/wallposPos_.x");//
static const char* wall_two_root_handl("Data/model/ModelPos/Lift_wall_two/stage_one/wallMove/wallposMove.x");//壁(目的地)2の座標
static const char* lever_two_handl("Data/model/ModelPos/Lift_lever_two/stage_one/lever_two_born.x");//レバー2

static const char* door_handdl("Data/model/ModelPos/Door/stage_one/Door.x");

static const char* zenmai_handl("Data/model/ModelPos/Item/stage_one/Zenmai.x");


static const char* golem_handl("Data/model/ModelPos/Golem/Golem.x");//ゴーレム

//各ボーン座標をハンドに入れる
static const char* handle_path[] =
{
	root_handl,
	lever_handl,
	wall_handl,
	wall_move_handl,
	item_handl,
	exit_handl,
	box_handl,
	needle_handl,
	wall_two_handl,//8
	wall_two_root_handl,//9
	lever_two_handl,//10

	door_handdl,//11
	zenmai_handl,//12

	golem_handl//13
};

const int object_num[] =
{
	ROOT_NUM,
	LEVER_POS,
	WALL_POS,
	WALL_MOVE_POS,
	ITEM_POS,
	EXIT_POS,
	BOX_POS,
	NEEDLE_POS,

	WALL_2_POS,
	WALL_2_ROOT_POS,
	LEVER_2_POS,

	DOOR_POS,
	ZENMAI_POS,

	GOLEM_POS,

};

int id_path[16][33] =
{
	{ 1, 2, 3, 4 },//敵
	{ 1,2,},//レバー
	{ 1,2,},//リフト
	{ 1,2,},//リフト目的地
	{ 1 },//カギ
	{1},//ゴール
	{ 1,2,3 },//箱
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24},//ニードル


	 { 1,2},//リフト2
	 { 1,2,},//リフト2目的地
	 { 1,2, },//レバー2

	{1},
	{1},
	{1},
};

//デストラクタ
CField_1::~CField_1()
{
	Fin();
}
//初期化
void CField_1::Init()
{
	CStageBase::Init();

	m_iHandle = new int[HANDLE_NUM];

}
//ロード
void CField_1::Load()
{
	VECTOR scale = { 0.1f,0.1f,0.1f };

	VECTOR pos = { 0.0f,0.0f,0.0f };

	for (int model_index = 0; handle_path[model_index] != nullptr; model_index++)
	{
		m_iHandle[model_index] = MV1LoadModel(handle_path[model_index]);

		MV1SetPosition(m_iHandle[model_index], pos);

		MV1SetScale(m_iHandle[model_index], scale);

		for (int bone_index = 0; bone_index < object_num[model_index]; bone_index++)
		{
			m_vBonePos[model_index][bone_index] = MV1GetFramePosition(m_iHandle[model_index], id_path[model_index][bone_index]);
		}
	}

	f_Handl = MV1LoadModel(field_handl);

	//スケールセット
	MV1SetScale(f_Handl, scale);	//フィールド

	MV1SetupCollInfo(f_Handl, -1, 1, 1, 1);
	//	//座標ハンドル
}

//描画処理
void CField_1::Draw()
{
	CStageBase::Draw();
}
//終了処理
void CField_1::Fin()
{
	CStageBase::Fin();

	for (int index = 0; index < HANDLE_NUM; index++)
	{
		MV1DeleteModel(m_iHandle[index]);

	}
	delete[] m_iHandle;

}

