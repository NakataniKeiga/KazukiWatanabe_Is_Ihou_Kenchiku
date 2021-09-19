#pragma once
#include"DxLib.h"
#include"../ObjectBase/Object3DBase.h"
#include"../Character/PlayerAnimation.h"
#include"../Gimmick/GimmickBase.h"


class CDoor :public CGimmickBase
{
private:
	//�����J����������
	bool m_isOpen;

public:

	CDoor() { Init(); Load(); };
	~CDoor() { Fin(); };

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
	//�����J������擾
	void GetOpen(bool flg) { m_isOpen = flg; }
	//�����J������Z�b�g
	bool SetOpen() { return m_isOpen; }

};