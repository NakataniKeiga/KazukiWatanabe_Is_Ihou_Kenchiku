#pragma once
#include"DxLib.h"
#include"../SceneBase.h"
#include"../ScenePlay/ScenePlay.h"



class CSceneClear :public CSceneBase
{
public:
	int m_iHndle;

private:
	
	CScenePlay m_selectPlay;
public:
	//�R���X�g���N�^
	CSceneClear() { };
	~CSceneClear();

	//������
	void Init();
	//���C������
	int Step();
	//�`��
	void Draw();
	//�I��
	void Fin();

};