#pragma once
#include"DxLib.h"
#include"../StageBase.h"

//���W�̑���
const int ROOT_NUM = 4;		// ���[�g�̌�
const int LEVER_POS = 2/*12*/;	//���[�o�[
const int WALL_POS = 2;		//��
const int WALL_MOVE_POS = 2;//��(�ړI�n)
const int ITEM_POS = 1;		//�A�C�e��
const int EXIT_POS = 1;		//�o��
const int BOX_POS = 3;		//��
const int NEEDLE_POS = 24;

const int WALL_2_POS = 2;
const int WALL_2_ROOT_POS = 2;//�ړI�n
const int LEVER_2_POS = 2;

const int DOOR_POS = 1;
const int ZENMAI_POS = 1;

const int GOLEM_POS = 1;


class CField_1 :public CStageBase
{
	public:
		enum tagHandleKind
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

			HANDLE_GOLEMU,//�X�e�[�W1�ł����g��Ȃ�

			HANDLE_NUM,
		};
		
private:


	//�X�e�[�W�ɐݒu���ꂽ�{�[���擾
	VECTOR m_vBonePos[HANDLE_NUM][100];

	VECTOR m_vRootPos[HANDLE_NUM][100];

	int m_fRoot[100];
public:
//�R���X�g���N�^�E�f�X�g���N�^
	CField_1() { Init(), Load(); };
	~CField_1();
	//������
	void Init();
	//�ǂݍ���
	void Load();
	//���C������
	void Step();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();
	//�X�e�[�W�̊e�I�u�W�F�N�g�̃{�[���̒l��Ԃ�
	VECTOR GetBone(int NUM,int num) { return m_vBonePos[NUM][num]; }
	//�X�e�[�W�̓G�̌o�H�{�[���̒l��Ԃ�
	VECTOR GetRoot(int NUM, int num) { return m_vRootPos[NUM][num]; }
	//�N���A�t���O�擾
	bool GetIsClear() { return m_isClearFlg; }
	//�N���A�t���O�Z�b�g
	void SetIsClear(bool flg) { m_isClearFlg = flg; }
};