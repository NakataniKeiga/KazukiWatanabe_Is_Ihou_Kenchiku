#pragma once
#include"DxLib.h"
#include"SceneBase.h"
#include"../Common.h"

class CSceneBase;

//�V�[���}�l�[�W���[
class CSceneManager
{
private:

// �e�V�[���̗���
	// ��{�I�ɂǂ̃V�[�������̗��ꂾ���œ����悤�ɂ���
	// ����ɗ���𑝂₵�����ꍇ�́A�e�V�[����Step���ő��₷
	enum tagState{
		STATEID_INIT,
		STATEID_STEP,
		STATEID_FIN,

		STATEID_NUM

	};

	CSceneBase* m_Base;									// �e�V�[�����i�[
	int m_iState;										// ���݂̏��
	int m_iNextstate;									// ���Ɉړ�����V�[��
	void (CSceneManager::* m_iScene[STATEID_NUM])();	// �V�[�����֐��|�C���^�ŊǗ����邽�߂̂���

public:
	
	void CreateScene();

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CSceneManager();
	~CSceneManager();
	//���[�v����
	int Loop();
	//�`�揈��
	void Draw();

private:
	//������
	void Init();
	//���C������
	void Step();
	//�㏈��
	void Fin();
};