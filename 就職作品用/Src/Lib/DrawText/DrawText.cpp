#include"DrawText.h"
#include"DxLib.h"

static const int DEF_FONT_SIZE = 16;	//デフォルトのフォントの大きさ
static const int TEXT_LENGTH = 256;		//1行当たりの最大数(バイト)

//コンストラクタ

CDrawText::CDrawText() :m_handl(-1), m_nowCnt(-1), m_waitTime(-1), m_time(-1),
m_textAmount(TEXT_LENGTH), m_fontSize(DEF_FONT_SIZE), m_color(GetColor(255, 255, 255)),
m_txt(nullptr), m_dispBuf(new char[m_textAmount]), m_isEnd(true)
{
}

//デストラクタ
CDrawText::~CDrawText()
{
	if (m_dispBuf != nullptr)
	{
		delete m_dispBuf;
		m_dispBuf = nullptr;
	}
	if(m_handl!=-1)
	{ 
		DeleteFontToHandle(m_handl);
		m_handl = -1;
	}
}

//フォントロード
bool CDrawText::Load(char* fontName, int size, int thick, int type)
{
//サイズは保存しておく必要があるがデフォルトの-1が出たとき対応が必要
	if (size == -1)m_fontSize = DEF_FONT_SIZE;
	else m_fontSize = size;
	m_handl = CreateFontToHandle(fontName, size, thick, type);
	return m_handl != -1;
}

void CDrawText::Request(const char* txt, int wait)
{
//ここで初期化するので今まで表示した文字は表示されなくなる
	m_txt = txt;
	m_waitTime = wait;
	m_time = wait;

	if (wait <= 0)	//待ち時間なし
	{
		m_nowCnt = static_cast<int>(strlen(txt));
		m_isEnd = true;
	}
	else            //待ち時間あり
	{
		m_nowCnt = 0;
		m_isEnd = false;
	}
}

void CDrawText::Update()
{
	if (m_txt == nullptr)return;
	if (m_isEnd)return;

	//一定時間経過ごとに表示される文字が増える
	--m_time;
	if (m_time == 0)
	{
		//
		int cnt = GetCharBytes(DX_CHARCODEFORMAT_SHIFTJIS, &m_txt[m_nowCnt]);
		//
		if (m_txt[m_nowCnt + cnt] == '\n')cnt += 1;
		//
		m_nowCnt += cnt;
		m_time = m_waitTime;
	}
}

void CDrawText::Draw(int x,int y)
{
	if (m_txt == nullptr)return;

	int cnt = 0;
	int col = 0;
	bool isEnd = false;

	while (!isEnd)
	{
		ZeroMemory(m_dispBuf, sizeof(char)*m_textAmount);


		int i;

		for (i = 0; i < m_textAmount - 1; i++)
		{
			//\nか表示予定の文字まで来た場合は普通に抜ける
			if (m_txt[cnt + i] == '\n' || cnt + i >= m_nowCnt)
			{
				break;
			}
			//\0まで来た場所は全てを終了させる
			else if (m_txt[cnt + i] == '\0')
			{
				isEnd = true;
				m_isEnd = true;
				break;
			}
		}
		//cotの場所から表示予定の文字1行分だけをコピー
	/*	memccpy(m_dispBuf,&m_txt[cnt], i);*/
		m_dispBuf[i] = '\0';

		//文字を表示、高さはうまくずらす
		DrawFormatStringToHandle(x, y + col * m_fontSize, m_color, m_handl, m_dispBuf);
		//
		if (m_txt[cnt + i] == '\n')cnt += i + 1;
		else cnt += i;

		//表示予定数まで来た場合は終了
		if (m_nowCnt <= cnt)isEnd = true;
		//表示する行を1つ次へ
		else ++col;
	}


}