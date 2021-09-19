#pragma once
#include"DxLib.h"
#include"../Input/Input.h"

//シーンクラス　継承用
class CSceneBase
{
public:
	//コンストラクタ・デストラクタ
	~CSceneBase() {};

	//仮想関数
	virtual void Init()=0;//初期化
	virtual int Step() = 0;//メイン処理
	virtual void Draw() =0;//描画処理
	virtual void Fin() =0;//終了処理

};
