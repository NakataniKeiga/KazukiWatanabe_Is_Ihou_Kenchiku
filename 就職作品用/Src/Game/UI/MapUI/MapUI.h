#pragma once
#include"../UI.h"
class CMapUI:public CUI
{
private:
	VECTOR m_vDrawPos;

	//�}�b�v�̕\���p�t���O
	bool m_isMapflg;

public:

	void Init();//������
	void Load();//���[�h����
	void Step();//���C������
	void Draw();//�`�揈��
	void Fin();	//�I������

};