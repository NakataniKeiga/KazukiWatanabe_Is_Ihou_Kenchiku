#pragma once
#include"DxLib.h"
#include"../Camera/CameraBase.h"

class CPlayCamera:public CCameraBase
{
private:

public:
	//�R���X�g���N�^
	CPlayCamera();

	//�����֐�
	void Init();
	//�j�A�E�t�@�[�Z�b�g
	void SetNearFar(float nearLength, float farLength);
	//���C������
	void Step(VECTOR focus);
	//�X�V����
	void Update();

};