#pragma once
#include"../../Lib/Singleton.h"
#include"../Character/Player/Player.h"
#include"../Character/Golem/Golem.h"
#include"CameraPlayer.h"
#include"CameraGolem.h"

//シーンマネージャークラス
class CCameraManager:public CSingleton<CCameraManager>
{
	friend CSingleton;
public:
	enum tagCameraID
	{
		GAME_PLAYER,//プレイヤーカメラ
		GAME_GOLEM,//ドローンカメラ
		CAMERA_DEBUG,//デバックカメラ

		CAMERA_NUM //総数
	};

private:
	CPlayCamera m_Playcamera;
	CGolemCamera m_Golemcamera;
	
	tagCameraID m_state;


//コンストラクタ・デストラクタ
	CCameraManager();
	~CCameraManager();
public:


	void Init();//初期化
	void Load();//ロード処理
	void Step(CPlayer* player,CGolem* golem);//メイン処理
	void Draw();//描画処理
	void Fin();//終了処理

	//プレイヤー用カメラ
	CPlayCamera GetCamera() { return m_Playcamera; }
	//ゴール用カメラ
	CGolemCamera GetGolemCamera() { return m_Golemcamera;}
};