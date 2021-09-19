#include"DrawText.h"
#include"DxLib.h"

static const int DEF_FONT_SIZE = 16;	//�f�t�H���g�̃t�H���g�̑傫��
static const int TEXT_LENGTH = 256;		//1�s������̍ő吔(�o�C�g)

//�R���X�g���N�^

CDrawText::CDrawText() :m_handl(-1), m_nowCnt(-1), m_waitTime(-1), m_time(-1),
m_textAmount(TEXT_LENGTH), m_fontSize(DEF_FONT_SIZE), m_color(GetColor(255, 255, 255)),
m_txt(nullptr), m_dispBuf(new char[m_textAmount]), m_isEnd(true)
{
}

//�f�X�g���N�^
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

//�t�H���g���[�h
bool CDrawText::Load(char* fontName, int size, int thick, int type)
{
//�T�C�Y�͕ۑ����Ă����K�v�����邪�f�t�H���g��-1���o���Ƃ��Ή����K�v
	if (size == -1)m_fontSize = DEF_FONT_SIZE;
	else m_fontSize = size;
	m_handl = CreateFontToHandle(fontName, size, thick, type);
	return m_handl != -1;
}

void CDrawText::Request(const char* txt, int wait)
{
//�����ŏ���������̂ō��܂ŕ\�����������͕\������Ȃ��Ȃ�
	m_txt = txt;
	m_waitTime = wait;
	m_time = wait;

	if (wait <= 0)	//�҂����ԂȂ�
	{
		m_nowCnt = static_cast<int>(strlen(txt));
		m_isEnd = true;
	}
	else            //�҂����Ԃ���
	{
		m_nowCnt = 0;
		m_isEnd = false;
	}
}

void CDrawText::Update()
{
	if (m_txt == nullptr)return;
	if (m_isEnd)return;

	//��莞�Ԍo�߂��Ƃɕ\������镶����������
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
			//\n���\���\��̕����܂ŗ����ꍇ�͕��ʂɔ�����
			if (m_txt[cnt + i] == '\n' || cnt + i >= m_nowCnt)
			{
				break;
			}
			//\0�܂ŗ����ꏊ�͑S�Ă��I��������
			else if (m_txt[cnt + i] == '\0')
			{
				isEnd = true;
				m_isEnd = true;
				break;
			}
		}
		//cot�̏ꏊ����\���\��̕���1�s���������R�s�[
	/*	memccpy(m_dispBuf,&m_txt[cnt], i);*/
		m_dispBuf[i] = '\0';

		//������\���A�����͂��܂����炷
		DrawFormatStringToHandle(x, y + col * m_fontSize, m_color, m_handl, m_dispBuf);
		//
		if (m_txt[cnt + i] == '\n')cnt += i + 1;
		else cnt += i;

		//�\���\�萔�܂ŗ����ꍇ�͏I��
		if (m_nowCnt <= cnt)isEnd = true;
		//�\������s��1����
		else ++col;
	}


}