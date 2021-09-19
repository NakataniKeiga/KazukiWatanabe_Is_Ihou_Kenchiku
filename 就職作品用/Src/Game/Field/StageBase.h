#pragma once
#include"DxLib.h"


class CStageBase
{
protected:
	int f_Handl;	//�t�B�[���h�n���h��

	bool m_isHitFlg;


	int *m_iHandle;

	int *m_iRootHandle;

	int *m_iBoneHandle;

	bool m_isClearFlg;

public:

//�R���X�g���N�^�E�f�X�g���N�^
	CStageBase() {};
	~CStageBase() {};


	//������
	virtual void Init();
	//�ǂݍ���
	virtual void Load();
	//�`�揈��
	virtual void Draw();
	//�I������
	virtual void Fin();

	bool LoadStageModel(const char* pFileName);
	//�N���A�t���O�擾
	virtual bool GetIsClear() { return m_isClearFlg; }
	//�N���A�t���O�Z�b�g
	virtual void SetIsClear(bool flg) { m_isClearFlg = flg; }

	int GetStageHandle() { return f_Handl; }

	virtual VECTOR GetBone(int NUM, int num) { return VGet(0.0f, 0.0f, 0.0f); }

	virtual VECTOR GetRoot(int NUM, int num) { return VGet(0.0f, 0.0f, 0.0f); }

	virtual int GetRootNum(int NUM) { return 0;}
	

};