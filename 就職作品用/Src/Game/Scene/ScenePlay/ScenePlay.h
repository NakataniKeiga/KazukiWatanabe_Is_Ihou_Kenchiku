#pragma once
#include"../SceneManager.h"
#include"../SceneBase.h"
#include"../../Field/StageManager.h"
#include"../../Camera/CamaraManager.h"
#include"../../UI/UIManager.h"
#include"../../Character/Golem/Golem.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Enemy/EnemyManager.h"
#include"../../Menu/Menu.h"
#include"../../Character/CharacterManager.h"



class CObjectManager;

class CScenePlay :public CSceneBase
{
private: 


	/*CPlayer* Player;
	CGolem* Golem;*/
	CCharacterManager* m_CharacterManager;
	CStageManager* m_Stage;
	CObjectManager* m_ObjectMnager;
	CCameraManager* m_Camera;
	CUIManager m_UI;
	CEnemyManager* m_EnemyManager;
	CMenu Menu;
	
	int m_ScenePlay;

public:
	//�R���X�g���N�^�E�f�X�g���N�^
	CScenePlay();
	~CScenePlay() {};
	//������
	void Init();
	//���C������
	int Step();
	//�`��
	void Draw();
	//�㏈��
	void Fin();
};