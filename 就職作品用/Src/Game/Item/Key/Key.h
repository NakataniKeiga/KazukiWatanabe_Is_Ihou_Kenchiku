#pragma once
#include"../ItemBase.h"


class CKey :public CItemBase
{
private:
	//���t���O
	bool m_isGetFlg;
public:
	CKey() { Init(); Load(); };
	~CKey() {};
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

	void PlayerHit(CPlayer *player);

	//void HitPlayer(CPlayer* player);
	//���t���O�擾
	bool GetIsGet() { return m_isGetFlg; }
};