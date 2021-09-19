#pragma once
#include"../../Lib/Singleton.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"CameraPlayer.h"
#include"CameraGolem.h"

//�V�[���}�l�[�W���[�N���X
class CCameraManager:public CSingleton<CCameraManager>
{
	friend CSingleton;
public:
	enum tagCameraID
	{
		GAME_PLAYER,//�v���C���[�J����
		GAME_GOLEM,//�h���[���J����
		CAMERA_DEBUG,//�f�o�b�N�J����

		CAMERA_NUM //����
	};

private:
	CPlayCamera m_Playcamera;
	CGolemCamera m_Golemcamera;
	
	tagCameraID m_state;


//�R���X�g���N�^�E�f�X�g���N�^
	CCameraManager();
	~CCameraManager();
public:


	void Init();//������
	void Load();//���[�h����
	void Step(CPlayer* player,CGolem* golem);//���C������
	void Draw();//�`�揈��
	void Fin();//�I������

	//�v���C���[�p�J����
	CPlayCamera GetCamera() { return m_Playcamera; }
	//�S�[���p�J����
	CGolemCamera GetGolemCamera() { return m_Golemcamera;}
};