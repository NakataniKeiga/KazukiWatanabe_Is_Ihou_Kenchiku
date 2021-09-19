#include"Field_2.h"
#include"../../Exit/Exit.h"


//�t�B�[���h�̃n���h��
static const char* field_two_handl("Data/model/Field/Field/StageTwo/2stage.x");

//�{�[���̍��W	
static const char* root_handl2_1("Data/model/ModelPos/Enemy/Field_2/enemy_root1_2.x");//���[�g�̃{�[�����W
static const char* root_handl2_2("Data/model/ModelPos/Enemy/Field_2/enemy_root2_2.x");

static const char* root_handl2("Data/model/ModelPos/Enemy/root.x");//���[�g�̃{�[�����W
static const char* lever_handl2("Data/model/ModelPos/Lift_lever/stage_two/2stageleverPos.x");//���o�[�ݒu���W
static const char* wall_handl2("Data/model/ModelPos/Lift_wall/stage_two/wallPosition/2stagewallpos.x");//�ǐݒu���W
static const char* wall_move_handl2("Data/model/ModelPos/Lift_wall/stage_two/wallMove/2stagewallpos_root.x");//��(�ړI�n�ړ�)�ݒu���W
static const char* item_handl2("Data/model/ModelPos/Item/stage_two/Key.x");//�A�C�e���ݒu���W
static const char* exit_handl2("Data/model/ModelPos/Exit/stage_two/ExitPos.x");//�S�[���ݒu���W
static const char* box_handl2("Data/model/ModelPos/Box/stage_two/2stageBoxPos.x");//���̃{�[�����W
static const char* transparentwall_handl2("Data/model/Field/TransparentWall/TransparentWall.x");//�����ȕǂ̃{�[�����W
static const char* needle_handl("Data/model/ModelPos/Needle/Stage_two/2stageNeedlePos.x");

static const char* box_twohandl2("Data/model/Field/Box_two/2stageBox_twoPos.x");//��2�̃{�[�����W
static const char* switch_handl2("Data/model/ModelPos/Switch/Switch_born.x");//�X�C�b�`�̃{�[�����W
static const char* wall_two_handl2("Data/model/ModelPos/Lift_wall_two/stage_two/wallPosition/2stage_born.x");//
static const char* wall_two_root_handl("Data/model/ModelPos/Lift_wall_two/stage_two/wallMove/2stageLift_root.x");//��(�ړI�n)2�̍��W
static const char* lever_two_handl2("Data/model/ModelPos/Lift_lever_two/stage_two/lever_two_born.x");//���o�[2

static const char* door_handdl("Data/model/ModelPos/Door/stage_two/Door.x");

static const char* zenmai_handl_2("Data/model/ModelPos/Item/stage_two/Zenmai_2.x");

static const char* golem_handl_2("Data/model/ModelPos/Golem/Golem_2.x");//�S�[����






static const char* root_path_[] =
{
	root_handl2_1,
	root_handl2_2,

};
static const char* handel_path[] =
{
	root_handl2,//0
	lever_handl2,//1
	wall_handl2,//2
	wall_move_handl2,//3
	item_handl2,//4
	exit_handl2,//5
	box_handl2,//6

needle_handl,//7

	wall_two_handl2,//8
	wall_two_root_handl,//9
	lever_two_handl2,//10
	door_handdl,//11
	zenmai_handl_2,//12
	golem_handl_2,//13

};
const int id_root_path[2][5]
{
	{1,2,3,4,5},
	{1,2,3,4,5},

};
const int id_path[16][27] =
{
	{ 1, 2, 3, 4 },
	{ 1,2, },//���o�[
	{ 1,2, },//���t�g
	{ 1,2, },//�ړI
	{ 1 },//�J�M
	{ 1 },//�S�[��
	{ 1,2 },//��
	{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27},//�j�[�h��

	{1},//���t�g2
	{1},//���t�g2�ړI�n
	{1},//���o�[2
	{1},
	{1},//����܂�
	{1},//�S�[����
};
const int object_num[] =
{
	ROOT_NUM_2,
	LEVER_POS_2,
	WALL_POS_2,
	WALL_MOVE_POS_2,
	ITEM_POS_2,
	EXIT_POS_2,
	BOX_POS_1_2,

	NEEDLE_POS_2,

	WALL_2_POS_2,
	WALL_2_ROOT_POS_2,
	LEVER_2_POS_2,
	DOOR_POS_2,
	ZENMAI_POS_2,
	GOLEM_POS_2,
};
const int root_num[] =
{
	4,
	4,
};
//�f�X�g���N�^
CField_2::~CField_2()
{
	Fin();
}
//������
void CField_2::Init()
{
	CStageBase::Init();

	m_iHandle = new int[HANDLE_NUM];

	m_iRootHandle = new int[ROOT_NUM];
}
//���[�h
void CField_2::Load()
{

	VECTOR scale = { 0.1f,0.1f,0.1f };

	VECTOR pos = { 0.0f,0.0f,0.0f };

	//�M�~�b�N�̃{�[�����W���擾
	for (int model_index = 0; handel_path[model_index] != nullptr; model_index++)
	{
		//���[�h�����{�[�����n���h���ɓ����
		m_iHandle[model_index] = MV1LoadModel(handel_path[model_index]);
		//�X�e�[�W�Ƀ{�[���̑傫�������킹��
		MV1SetPosition(m_iHandle[model_index], pos);
		MV1SetScale(m_iHandle[model_index], scale);

		for (int bone_index = 0; bone_index < object_num[model_index]; bone_index++)
		{
			m_vBonePos[model_index][bone_index] = MV1GetFramePosition(m_iHandle[model_index], id_path[model_index][bone_index]);
		}
	}


	//�G�̌o�H�{�[�����W���擾
	for (int root_index = 0; root_index < ROOT_NUM; root_index++)
	{
		//���[�h�����{�[�����n���h���ɓ����
		m_iRootHandle[root_index] = MV1LoadModel(root_path_[root_index]);
		//�X�e�[�W�Ƀ{�[���̑傫�������킹��
		MV1SetPosition(m_iRootHandle[root_index], pos);
		MV1SetScale(m_iRootHandle[root_index], scale);

		for (int bone_index = 0; bone_index < root_num[root_index]; bone_index++)
		{
			m_vRootPos[root_index][bone_index] = MV1GetFramePosition(m_iRootHandle[root_index], id_root_path[root_index][bone_index]);
		}
	}

	//���[�g�̌o�H�ԍ�������
	for (int bone_index = 0; bone_index < ROOT_NUM; bone_index++)
	{
		m_fRoot[bone_index] = root_num[bone_index];
	}
	//�t�B�[���h�̃n���h��
	f_Handl = MV1LoadModel(field_two_handl);

	//�X�P�[���Z�b�g
	MV1SetScale(f_Handl, scale);	//�t�B�[���h

	MV1SetupCollInfo(f_Handl, -1, 1, 1, 1);
}

//�`�揈��
void CField_2::Draw()
{

	MV1DrawModel(f_Handl);

}
//�I������
void CField_2::Fin()
{
	MV1DeleteModel(f_Handl);

	for (int index = 0; index < HANDLE_NUM; index++)
	{
		MV1DeleteModel(m_iHandle[index]);

	}
	delete[] m_iHandle;

	for (int index = 0; index < ROOT_NUM; index++)
	{
		MV1DeleteModel(m_iRootHandle[index]);
	}
	delete[] m_iRootHandle;
}
