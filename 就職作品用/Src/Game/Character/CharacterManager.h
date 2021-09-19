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

	//初期化
	void Init();
	//ロード処理
	void Load();
	//メイン処理
	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	bool PlayerGetFlg();


};