#pragma once


#include"UI.h"
#include<list>

class CUIManager
{
private:

	static std::list<CUI*> m_UIList;
public:
	//�R���X�g���N�^
	CUIManager() {};
	~CUIManager() {};

	void Init();//������
	void Load();//���[�h����
	void Step();//���C������
	void Draw();//�`�揈��
	void Fin();	//�I������

	//���X�g��ǉ�
	void AddUIList(CUI* list);
	//���X�g�̑S�폜
	void AllDeleteUIList();
	//���X�g���擾
	static std::list<CUI*> GetCharactorList() { return m_UIList; }

};