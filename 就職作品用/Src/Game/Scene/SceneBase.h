#pragma once
#include"DxLib.h"
#include"../Input/Input.h"

//�V�[���N���X�@�p���p
class CSceneBase
{
public:
	//�R���X�g���N�^�E�f�X�g���N�^
	~CSceneBase() {};

	//���z�֐�
	virtual void Init()=0;//������
	virtual int Step() = 0;//���C������
	virtual void Draw() =0;//�`�揈��
	virtual void Fin() =0;//�I������

};
