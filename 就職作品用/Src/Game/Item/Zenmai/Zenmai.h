#pragma once
#include"../ItemBase.h"

class CZenmai :public CItemBase
{
private:


public:
	CZenmai() {};
	~CZenmai() {};

	//������
	void Init();
	//���[�h����
	void Load();
	//���C������
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();


};