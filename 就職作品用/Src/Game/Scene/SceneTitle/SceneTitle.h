#pragma once
//#include"SceneTitle.h"
#include"../SceneManager.h"
#include"../SceneBase.h"

//�V�[���^�C�g���N���X
class CSceneTitle :public CSceneBase
{
private:
	int* m_iHndle;
public:
	enum tagGraphics {
		TITLE,
		ENTER,
		GRAPHICS_NUM,
	};

	//�R���X�g���N�^
	CSceneTitle();
	~CSceneTitle();

	int m_iSelectNumber;
	int m_iDrawNumber;

	//������
	void Init();
	//���[�v
	int Step();
	//�`��
	void Draw();
	//�㏈��
	void Fin();

};