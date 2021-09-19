#pragma once
class CInputKey {
private:
	static char m_buf[256];     //現在のキーボード情報
	static char m_old_Buf[256];  //1フレーム前のキーボード情報
	static char m_key_buf[0];
public:
	//初期化
	static void Init();
	//更新処理
	static void Update();
	//ボタンを押したか？
	static bool IsPuch(int key);
	//ボタンを押したか？(トリガー)
	static bool IsPuchTrg(int key);

	static bool IsPushDown(int key);
};