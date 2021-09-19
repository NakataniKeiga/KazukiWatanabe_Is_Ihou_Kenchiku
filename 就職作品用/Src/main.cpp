
#include "DxLib.h"
#include <crtdbg.h>
#include <list>
#include"Game/Scene/SceneManager.h"
#include"Lib/Frame.h"
#include "../Src/Game/Input/Input.h"

// �v���O������ WinMain ����n�܂�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	//�E�B���h�E�̏�Ԃ�ݒ肷��	
	ChangeWindowMode(true);
	SetGraphMode(1280, 720, 32);
	//���������[�N���m�F����
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	if (DxLib_Init() == -1)		// �c�w���C�u��������������
	{
		return -1;			// �G���[���N�����璼���ɏI��
	}
	SetUseZBuffer3D(TRUE);
	SetWriteZBuffer3D(TRUE);

	//�`�悷��X�N���[����ݒ�
	SetDrawScreen(DX_SCREEN_BACK);

	DrawPixel(320, 240, GetColor(255, 255, 255));	// �_��ł�

	//�V�[���}�l�[�W���[���m�ۂ���
	CSceneManager cSceneManager;
	/*CSceneManager* cSceneManager = CSceneManager::GetInstance();*/
	//������
	//cSceneManager->Init();

	while (ProcessMessage() != -1)
	{

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) break;
		ClearDrawScreen();
		//���C���E�`�揈��
		cSceneManager.Loop();
		cSceneManager.Draw();
		/*cSceneManager->Step();
		cSceneManager->Draw();*/
		ScreenFlip();
	}

	//�I��
	/*cSceneManager->Fin();*/
	//�폜
	//delete cSceneManager;

	DxLib_End();				// �c�w���C�u�����g�p�̏I������

	return 0;				// �\�t�g�̏I�� 
}
