#pragma once
#include"../SceneBase.h"
#include"../SceneManager.h"

class CSceneGameOver :public CSceneBase
{
private:
	int* m_iHndle;

public:
	CSceneGameOver();
	~CSceneGameOver();



	//������
	void Init();
	//���[�h����
	void Load();
	//���C������
	int Step();
	//�`��
	void Draw();
	//�I��
	void Fin();


};