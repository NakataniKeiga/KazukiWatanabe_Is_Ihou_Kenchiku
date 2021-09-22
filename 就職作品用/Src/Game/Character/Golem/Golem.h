#pragma once
#include"DxLib.h"
#include"../PlayerAnimation.h"
#include"../CharacterBase.h"
#include"../../../Lib/Singleton.h"

//��`�֘A=============================
static const float DRONE_SIZE_X = 20.0f;
static const float DRONE_SIZE_Y = 80.0f;
static const float DRONE_SIZE_Z = 30.0f;

class CPlayer;

class CGolem :public CCharacterBase/*,public CSingleton<CGolem>*/
{
	/*friend CSingleton;*/
private:
	enum tagdrone
	{
		STATE_START=1,	//�����オ��
		STATE_STOP=2,	//�����Ă���
		STATE_WATING=3,	//�ҋ@
		STATE_MOVE=4,		//�O�i
		STATE_MOVE_KEEP,//�O�i�ێ�
		STATE_BACK=6,	//���	

		STATE_NUM,  //����
	};
	tagdrone m_state;



	

	VECTOR m_vCamRot;
	VECTOR m_vBackPos;
	bool m_isLever_Flg;
	bool m_isChase;		//�ǂ������Ă�������t���O
	
	//�N��
	void Start();
	//�����Ă���
	void Stop();
	//�ҋ@
	void Wait();
	//�ړ�
	void Move();
	//player����Ă΂ꂽ���̏���
	void Call(CPlayer* player);

public:
	//�R���X�g���N�^
	CGolem() {};
	~CGolem() { Fin(); }

	//������
	void Init();
	//���f���̃��[�h
	void Load();
	//���C������
	void Step(CPlayer* player);
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();

	void Collision();
	//�ړ�����
	VECTOR GetSpeed();
	//��������蔻��
	VECTOR GetBackPos();
	//�ړ��X�V
	void CalcSpeed(VECTOR speed);

	//���o�[������������t���O�擾
	bool GetLever() { return m_isLever_Flg; }
	
	void SetLever(bool leverflg) { m_isLever_Flg = leverflg; }
};