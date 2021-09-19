#pragma once
#include"DxLib.h"
#include"../Gimmick/GimmickBase.h"
#include"../../Lib/Singleton.h"

class CExit :public CGimmickBase
{
private:
	//シーンの切り替えフラグ
	bool m_isScene;
public:

CExit() { Init(); Load();  };
	~CExit() { Fin(); };

	//初期化
	void Init();
	//ロード処理
	void Load();

	void Step();
	//更新処理
	void Update();
	//描画処理
	void Draw();
	//終了処理
	void Fin();
	//切り替えフラグ取得
	bool GetIscene() { return m_isScene; }
	//シーンのセット
	void SetIscene(bool flg) { m_isScene = flg; }

};