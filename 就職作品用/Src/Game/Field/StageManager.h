#pragma once
#include<vector>
#include"StageBase.h"
#include"../../Lib/Singleton.h"
#include"../Scene/SceneManager.h"


//�X�e�[�W�}�l�[�W���[
class CStageManager: public CSingleton<CStageManager>
{
private:
	friend CSingleton;

public:

private:
	//�X�e�[�W�ԍ�
	int m_StageNum;
	//�X�e�[�W�N���A�t���O
	bool m_Clearflag;

	CStageBase* m_StageData;

	
//�R���X�g���N�^
	CStageManager();
	~CStageManager() {};
public:
	

	void Init();//������
	void Draw();//�`�揈��
	void Fin();	//�I������


	//�X�e�[�W�̐؂�ւ�
	void ChengeStage();
	//�t���O�Z�b�g
	void SetStageClearFlg(bool flg);
	//�X�e�[�W�ԍ��Z�b�g
	void SetStageNum(int NUM) { m_StageNum = NUM; }
	//�Q�[���N���A�t���O�Z�b�g
	void SetStageNum(bool flg) { m_Clearflag = flg; }

	//�X�e�[�W�n���h���擾
	int GetHandle();
	//�G�l�~�[�̃{�[���̑������擾
	int GetRootNum(int root_num);
	//�X�e�[�W�ԍ��擾
	int GetStageNum() { return m_StageNum; }
	//�X�e�[�W����e�M�~�b�N�̍��W���擾
	VECTOR GetManeBone(int handle_num, int num);
	//�X�e�[�W�̃G�l�~�[�̈ړ��{�[�����擾
	VECTOR GetRootBone(int root_path,int num);
	//�t���O�擾
	bool GetStageClearFlg();
	//�Q�[���N���A�t���O�擾
	bool GetGameClearFlg() { return m_Clearflag; }
	

};


