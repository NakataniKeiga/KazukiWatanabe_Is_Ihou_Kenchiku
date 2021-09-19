#pragma once
#include"CharacterCommon.h"
#include"Player/Player.h"
#include"Golem/Golem.h"
#include"../Camera/CamaraManager.h"
#include"../../Lib/Singleton.h"

class CCharacterManager :public CSingleton<CCharacterManager>
{
private:
	friend CSingleton;

private:
	//std::list<CCharacterBase*>m_PoolCharacter;
	//std::list<CCharacterBase*>m_UseCharacter;

	CPlayer* m_Player;
	CGolem* m_Golem;
	CCameraManager* m_Camera;

public:


	CCharacterManager();
	~CCharacterManager() {};

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

	bool PlayerGetFlg();


};