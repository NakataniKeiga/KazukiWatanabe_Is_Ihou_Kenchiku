#pragma once
#include"DxLib.h"

class CUI
{
protected:

	int* m_iHandle;

public:

	CUI() {};
	~CUI() {};

	virtual void Init() {};//������
	virtual void Load() {};//���[�h����
	virtual void Step() {};//���C������
	virtual void Draw() {};//�`�揈��
	virtual void Fin() {};	//�I������

};