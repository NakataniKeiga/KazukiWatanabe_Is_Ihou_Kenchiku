#pragma once

class CDrawText
{
private:
	int m_handl;			//テキストハンドル
	int m_nowCnt;			//現在何文字目まで表示しているか
	int m_waitTime;			//次の文字を表示するまでにかかる時間
	int m_time;				//次の文字を表示するまでの時間
	int m_textAmount;		//1行に表示できるテキスト量
	int m_fontSize;			//文字の大きさ
	int m_color;			//文字の色
	const char* m_txt;		//テキストのアドレス保存
	char* m_dispBuf;		//1行分の文字列をディスプレイに表示するためのバッファ
	bool m_isEnd;			//最終文字まで表示されたか

public:

	CDrawText();

	~CDrawText();

	//　フォンロード
	//@fontName	:	ロードするフォント名
	//@size		:	フォントの大きさ
	//@thick	:	フォントの太さ
	//@type		:	フォントのタイプ
	//@memo		:	今回は他のプログラムに影響を与えないよう、個別にフォントをロードする
	bool Load(char* forntName = nullptr, int size = -1, int thick = -1, int type = -1);
	//	リクエスト
	//@txt	:表示させたいテキストの先頭アドレス
	//		(受け渡しは破棄しない)
	//@wait	:1文字ずつ表示させるときの間隔
	void Request(const char* txt, int wait);
	//更新
	void Update();
	//描画
	// iX,iY :文字左上の表示位置
	void Draw(int x,int y);
	//リセット
	void Reset();

	//終了判定
	bool IsEnd(void);
	//1行の文字量設定
	void SetAmount(int amount);
	//文字の色設定
	void SetColor(int r, int g, int b);
	//文字を最後まで一気に表示
	void SetAllText();

};