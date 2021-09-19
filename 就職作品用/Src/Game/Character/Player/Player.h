#pragma once
#include"../PlayerAnimation.h"
#include"../../Camera/CamaraManager.h"
#include"../CharacterBase.h"

#include"../../../Lib/Singleton.h"


//��`�֘A=============================
static const float PLAYER_SIZE_X = 10.0f;
static const float PLAYER_SIZE_Y = 80.0f;
static const float PLAYER_SIZE_Z = 30.0f;

class CGolem;

class  CPlayer :public CCharacterBase/*, public CSingleton<CPlayer>*/
{
	/*friend CSingleton;*/
private:

	enum  tagPlayerState {
		STATE_WALK,//����
		STATE_WATING,//�ҋ@
		STATE_BOXHAVE,//���������Ă�����
		STATE_BOXHAVE_1,//���������Ă�����2
		STATE_BOXHAVE_WAIT,//������������Ԃőҋ@
		STATE_BOXHAVE_WALK,//������������Ԃŕ���
		STATE_GOLEM_START,//�S�[�������N�������邽�߂�
		STATE_BACK,

		STATE_NUM,//�v���C���[�̑S��Ԑ�
	};
	tagPlayerState m_state;

	

	int m_iHitPoint;
	bool m_isKeyHave_Flg;	//�����擾����t���O
	bool m_isShove_Flg;		//�������������̔���t���O
	bool m_isLever_Flg;		//���o�[�����������̃t���O
	bool m_isZenmaiHave_Flg;//����܂��΂ˎ擾����t���O
	//�m�b�N�o�b�N�p
	VECTOR m_vSpeed;

	//�ҋ@
	void Wait(CGolem* golem);
	//�ړ�
	void Run();
	//����
	void Have();
	//�����Ă����Ԃőҋ@
	void HaveWait();
	//�����Ă����Ԃňړ�
	void HaveMove();
	//�S�[�����N��
	void GolemStart(CGolem* golem);
public:

//�R���X�g���N�^�E�f�X�g���N�^
	CPlayer() { Init(), Load();}
	~CPlayer() { Fin(); }
	
	//������
	void Init();
	//���[�h
	void Load();
	//�؂�ւ�
	void IsChange(CGolem* golem);
	//�Z�b�g
	void Step(CGolem* golem);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�㏈��
	void Fin();

	void Collision();

	//�ړ��X�V
	void CalcSpeed(VECTOR speed);
	//�m�b�N�o�b�N
	void HitCalc(VECTOR m_speed);
	//�m�b�N�o�b�N����
	void MoveBack();
	//�O���̓����蔻��
	VECTOR GetHitPos();
	//�����ړ��擾
	VECTOR GetSpeed();
	
//�擾�t���O//
	//�̗͎擾
	int GetHitPoint() { return m_iHitPoint; }
	//�����t���O�擾
	bool GetIsAlive() { return m_isAlive; }
	//�A�N�e�B�u�t���O�擾
	bool GetIsActiv() { return m_isActivate; }
	//�擾�t���O���擾
	bool GetHave() { return m_isKeyHave_Flg; }
	//�������������̔���t���O�擾
	bool GetShove() { return m_isShove_Flg; }
	//���o�[������������t���O�擾
	bool GetLever() { return m_isLever_Flg; }
	//����܂��΂˃t���O�擾
	bool GetZenmaiHave() { return m_isZenmaiHave_Flg; }
//�Z�b�g�t���O//
	//�̗͂̃Z�b�g
 	void SetHitPoint(int hp) { m_iHitPoint = hp; }
	//�J�M�擾����Z�b�g
	void SetHave(bool have) { m_isKeyHave_Flg = have; }
	//�������������̔���Z�b�g
	void SetShove(bool shove) { m_isShove_Flg = shove; }
	//���o�[������������Z�b�g
	void SetLever(bool leverflg) { m_isLever_Flg = leverflg; }
	////����܂��΂ˎ擾����Z�b�g
	void SetZenmaiHave(bool zenmaihave) { m_isZenmaiHave_Flg = zenmaihave; }
};
