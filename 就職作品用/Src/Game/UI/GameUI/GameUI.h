#pragma once
#include"../UI.h"

class CGameUI:public CUI
{
private:

	int m_iHp_x[20];		//�̗͍��W
	int m_iHp_y;			//�̗͍��W
public:

	CGameUI() {};
	~CGameUI() {};
	//���f���n���h��

	


	void Init();//������
	void Load();//���[�h����
	void Draw();//�`�揈��
	void Fin();	//�I������
};