#pragma once
#include"Box_1.h"
#include"../GimmickBase.h"
#include <vector>
class CCollisionManager;
class CStageManager;
static const int BOX_MAX = 3;
//static const int BOX_NUM[3] = { 3,1,0 };

class CBox_1Manager:public CGimmickBase
{
private:

	//�{�b�N�X�̃f�[�^�������ė��₷�����邽��Vecter�ł͂Ȃ�
	CBox_1* m_Box;

public:
	CBox_1Manager() ;
	~CBox_1Manager() {};

	//������
	void Init();
	//���[�h
	void Load();
	//�Z�b�g
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�㏈��
	void Fin();

	CBox_1* GetBoxData() { return m_Box; }
	//���̔ԍ��擾
	//int GetBoxNum(int num) { return BOX_NUM[num]; }


};