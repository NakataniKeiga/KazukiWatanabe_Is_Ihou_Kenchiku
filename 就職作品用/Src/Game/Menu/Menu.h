#pragma once
#include"DxLib.h"

class CMenu 
{
public:
	enum tagMenuType	//���j���[��ʎ��̎��
	{
		TYEP_MAP,		//�}�b�v
		TYPE_OPERATUON,	//������@
		TYPE_BACK,		//�߂�

		TYPE_NUM,		//����
	};
	
private:
	int* m_iHandle;		//���f���n���h��
	bool m_isMenuflg;			//���j���[�t���O
	int m_MenuType;		//���j���[�^�C�v�̔ԍ�
	int m_iStageType;		//�X�e�[�W�̎�ނ����邽�߂̕ϐ�
	VECTOR DrawPlayerPos;	//�~�j�}�b�v�Ɉڂ��v���C���[�̌��ݒn���W
	VECTOR DrawGolemPos;	//�~�j�}�b�v�Ɉڂ��S�[�����̌��ݒn���W

public:

	CMenu() {};
	~CMenu() {};
	//�t���O�擾
	bool Getflg() { return m_isMenuflg; }
	//�t���O�Z�b�g
	void Setflg(bool flg) { m_isMenuflg = flg; }
	//������
	void Init();
	//���[�h����
	void Load();
	//���C������
	void Step();
	//�`�揈��
	void Draw();
	//�I��
	void Fin();
};