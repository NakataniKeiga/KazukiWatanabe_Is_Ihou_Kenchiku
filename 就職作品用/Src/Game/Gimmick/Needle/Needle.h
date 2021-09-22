#pragma once
#include"DxLib.h"
#include"../../ObjectBase/Object3DBase.h"
#include"../../Gimmick/GimmickBase.h"
#include"../../Character/Player/Player.h"


class CNeedle:public CGimmickBase
{
private:

	bool m_isChange;			//���o�[�t���O

public:

	CNeedle() { Init(), Load(); };
	~CNeedle() { Fin(); };

	//������
	void Init();
	//���f���̃��[�h
	void Load();
	//���C������
	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();

	void PlayerHit(CPlayer* player);

	void PlayerHitPosHit(CPlayer* player);

	void GolemHit(CGolem* golem);

	void GolemHitPosHit(CGolem* golem);

	//�n���h���擾
	int GetHndl() { return m_iHndl; }
	//���o�[�̃t���O�擾
	bool GetIsChange() { return m_isChange; }
	//���o�[�̃t���O�Z�b�g
	void SetIsChange(bool flg) { m_isChange = flg; }
	
	VECTOR GetCeneter();
};
