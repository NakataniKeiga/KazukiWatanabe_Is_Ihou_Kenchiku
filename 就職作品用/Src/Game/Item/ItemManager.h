#pragma once
#include"ItemBase.h"
#include"ItemCommon.h"
#include"../../Lib/Singleton.h"
#include<list>

class CItemManager: public CSingleton<CItemManager>
{
private:
	friend CSingleton;

private:


	std::list<CItemBase*>m_UseItem;//���܎g���Ă���f�[�^�v�[��

	int m_Handle[ITEM_NUM];



public:
	CItemManager() {};
	~CItemManager() {};


	//������
	void Init();
	//���C������
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();

	void Reqest(tagitem kind);

	void Create(tagitem kind,VECTOR pos);

	std::list<CItemBase*>GetUsePool() { return m_UseItem; }
};