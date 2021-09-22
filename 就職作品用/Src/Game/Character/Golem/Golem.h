#pragma once
#include"DxLib.h"
#include"../PlayerAnimation.h"
#include"../CharacterBase.h"
#include"../../../Lib/Singleton.h"

//定義関連=============================
static const float DRONE_SIZE_X = 20.0f;
static const float DRONE_SIZE_Y = 80.0f;
static const float DRONE_SIZE_Z = 30.0f;

class CPlayer;

class CGolem :public CCharacterBase/*,public CSingleton<CGolem>*/
{
	/*friend CSingleton;*/
private:
	enum tagdrone
	{
		STATE_START=1,	//立ち上がる
		STATE_STOP=2,	//座っている
		STATE_WATING=3,	//待機
		STATE_MOVE=4,		//前進
		STATE_MOVE_KEEP,//前進維持
		STATE_BACK=6,	//後退	

		STATE_NUM,  //総数
	};
	tagdrone m_state;



	

	VECTOR m_vCamRot;
	VECTOR m_vBackPos;
	bool m_isLever_Flg;
	bool m_isChase;		//追いかけていく判定フラグ
	
	//起動
	void Start();
	//座っている
	void Stop();
	//待機
	void Wait();
	//移動
	void Move();
	//playerから呼ばれた時の処理
	void Call(CPlayer* player);

public:
	//コンストラクタ
	CGolem() {};
	~CGolem() { Fin(); }

	//初期化
	void Init();
	//モデルのロード
	void Load();
	//メイン処理
	void Step(CPlayer* player);
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();

	void Collision();
	//移動処理
	VECTOR GetSpeed();
	//後方当たり判定
	VECTOR GetBackPos();
	//移動更新
	void CalcSpeed(VECTOR speed);

	//レバーを押した判定フラグ取得
	bool GetLever() { return m_isLever_Flg; }
	
	void SetLever(bool leverflg) { m_isLever_Flg = leverflg; }
};