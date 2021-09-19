#pragma once
#include"../PlayerAnimation.h"
#include"../../Camera/CamaraManager.h"
#include"../CharacterBase.h"

#include"../../../Lib/Singleton.h"


//定義関連=============================
static const float PLAYER_SIZE_X = 10.0f;
static const float PLAYER_SIZE_Y = 80.0f;
static const float PLAYER_SIZE_Z = 30.0f;

class CGolem;

class  CPlayer :public CCharacterBase/*, public CSingleton<CPlayer>*/
{
	/*friend CSingleton;*/
private:

	enum  tagPlayerState {
		STATE_WALK,//歩く
		STATE_WATING,//待機
		STATE_BOXHAVE,//箱を持っている状態
		STATE_BOXHAVE_1,//箱を持っている状態2
		STATE_BOXHAVE_WAIT,//箱を持った状態で待機
		STATE_BOXHAVE_WALK,//箱を持った状態で歩く
		STATE_GOLEM_START,//ゴーレムを起動させるための
		STATE_BACK,

		STATE_NUM,//プレイヤーの全状態数
	};
	tagPlayerState m_state;

	

	int m_iHitPoint;
	bool m_isKeyHave_Flg;	//鍵を取得判定フラグ
	bool m_isShove_Flg;		//箱を押した時の判定フラグ
	bool m_isLever_Flg;		//レバーを押した時のフラグ
	bool m_isZenmaiHave_Flg;//ぜんまいばね取得判定フラグ
	//ノックバック用
	VECTOR m_vSpeed;

	//待機
	void Wait(CGolem* golem);
	//移動
	void Run();
	//持つ
	void Have();
	//持っている状態で待機
	void HaveWait();
	//持っている状態で移動
	void HaveMove();
	//ゴーレム起動
	void GolemStart(CGolem* golem);
public:

//コンストラクタ・デストラクタ
	CPlayer() { Init(), Load();}
	~CPlayer() { Fin(); }
	
	//初期化
	void Init();
	//ロード
	void Load();
	//切り替え
	void IsChange(CGolem* golem);
	//セット
	void Step(CGolem* golem);
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//後処理
	void Fin();

	void Collision();

	//移動更新
	void CalcSpeed(VECTOR speed);
	//ノックバック
	void HitCalc(VECTOR m_speed);
	//ノックバック処理
	void MoveBack();
	//前方の当たり判定
	VECTOR GetHitPos();
	//方向移動取得
	VECTOR GetSpeed();
	
//取得フラグ//
	//体力取得
	int GetHitPoint() { return m_iHitPoint; }
	//生存フラグ取得
	bool GetIsAlive() { return m_isAlive; }
	//アクティブフラグ取得
	bool GetIsActiv() { return m_isActivate; }
	//取得フラグを取得
	bool GetHave() { return m_isKeyHave_Flg; }
	//箱を押した時の判定フラグ取得
	bool GetShove() { return m_isShove_Flg; }
	//レバーを押した判定フラグ取得
	bool GetLever() { return m_isLever_Flg; }
	//ぜんまいばねフラグ取得
	bool GetZenmaiHave() { return m_isZenmaiHave_Flg; }
//セットフラグ//
	//体力のセット
 	void SetHitPoint(int hp) { m_iHitPoint = hp; }
	//カギ取得判定セット
	void SetHave(bool have) { m_isKeyHave_Flg = have; }
	//箱を押した時の判定セット
	void SetShove(bool shove) { m_isShove_Flg = shove; }
	//レバーを押した判定セット
	void SetLever(bool leverflg) { m_isLever_Flg = leverflg; }
	////ぜんまいばね取得判定セット
	void SetZenmaiHave(bool zenmaihave) { m_isZenmaiHave_Flg = zenmaihave; }
};
