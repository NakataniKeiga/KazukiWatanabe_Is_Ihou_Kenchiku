#pragma once
#include"DxLib.h"
#include"../../Field/StageManager.h"
#include"../../../Lib/Singleton.h"
#include"../StageBase.h"

//���W�̑���
const int ROOT_NUM_2 = 4;		// ���[�g�̌�
const int LEVER_POS_2 = 2;	//���[�o�[
const int WALL_POS_2 = 2;		//��
const int WALL_MOVE_POS_2 = 2;//��(�ړI�n)
const int ITEM_POS_2 = 1;		//�A�C�e��
const int EXIT_POS_2 = 1;		//�o��
const int BOX_POS_1_2 = 2;		//��
const int NEEDLE_POS_2 = 23;

const int WALL_2_POS_2 = 1;
const int WALL_2_ROOT_POS_2 = 1;//�ړI�n
const int LEVER_2_POS_2 = 1;

const int DOOR_POS_2 = 1;
const int ZENMAI_POS_2 = 1;

const int GOLEM_POS_2 = 1;

class CField_2 :public CStageBase
{

public:
	//�e�M�~�b�N�̃{�[��
	enum tagHandeleKind
	{
		HANDLE_ROOT,
		HANDLE_REVER,
		HANDLE_LIFT,
		HANDLE_LIFT_MOVE,
		HANDLE_ITEM,
		HANDLE_EXIT,
		HANDLE_BOX_1,
		HANDLE_NEEDLE,
		
		HANDLE_LIFT_2,
		HANDLE_LIFT_MOVE_2,
		HANDLE_LEVER_2,

		HANDLE_DOOR,
		HANDLE_ZENMAI,

		HANDLE_GOLEMU_2,

		HANDLE_NUM,

	};
	//�G�̌o�H
	enum rootHandleKind
	{
		ROOT_1,
		ROOT_2,

		ROOT_NUM,

	};
private:

	//�X�e�[�W�ɐݒu���ꂽ�{�[���擾
	VECTOR m_vBonePos[HANDLE_NUM][100];
	//�X�e�[�W�ɐݒu���ꂽ�G�̌o�H�{�[���擾
	VECTOR m_vRootPos[ROOT_NUM][50];
	//���[�g�̔ԍ�
	int m_fRoot[10];
	
public:

//�R���X�g���N�^�E�f�X�g���N�^
	CField_2() { Init(), Load(); };
	~CField_2();

	//������
	void Init();
	//�ǂݍ���
	void Load();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();
	//�X�e�[�W�̃M�~�b�N�{�[���̒l��Ԃ�*/
	VECTOR GetBone(int NUM,int num) { return m_vBonePos[NUM][num]; }
	//�X�e�[�W�̓G�̌o�H�{�[���̒l��Ԃ�
	VECTOR GetRoot(int NUM, int num) { return m_vRootPos[NUM][num]; }
	//�o�H�̌����擾
	int GetRootNum(int NUM) { return m_fRoot[NUM]; }
	//�N���A�t���O�擾
	bool GetIsClear() { return m_isClearFlg; }
	//�N���A�t���O�Z�b�g
	void SetIsClear(bool flg) { m_isClearFlg = flg; }
};