#pragma once

class CDrawText
{
private:
	int m_handl;			//�e�L�X�g�n���h��
	int m_nowCnt;			//���݉������ڂ܂ŕ\�����Ă��邩
	int m_waitTime;			//���̕�����\������܂łɂ����鎞��
	int m_time;				//���̕�����\������܂ł̎���
	int m_textAmount;		//1�s�ɕ\���ł���e�L�X�g��
	int m_fontSize;			//�����̑傫��
	int m_color;			//�����̐F
	const char* m_txt;		//�e�L�X�g�̃A�h���X�ۑ�
	char* m_dispBuf;		//1�s���̕�������f�B�X�v���C�ɕ\�����邽�߂̃o�b�t�@
	bool m_isEnd;			//�ŏI�����܂ŕ\�����ꂽ��

public:

	CDrawText();

	~CDrawText();

	//�@�t�H�����[�h
	//@fontName	:	���[�h����t�H���g��
	//@size		:	�t�H���g�̑傫��
	//@thick	:	�t�H���g�̑���
	//@type		:	�t�H���g�̃^�C�v
	//@memo		:	����͑��̃v���O�����ɉe����^���Ȃ��悤�A�ʂɃt�H���g�����[�h����
	bool Load(char* forntName = nullptr, int size = -1, int thick = -1, int type = -1);
	//	���N�G�X�g
	//@txt	:�\�����������e�L�X�g�̐擪�A�h���X
	//		(�󂯓n���͔j�����Ȃ�)
	//@wait	:1�������\��������Ƃ��̊Ԋu
	void Request(const char* txt, int wait);
	//�X�V
	void Update();
	//�`��
	// iX,iY :��������̕\���ʒu
	void Draw(int x,int y);
	//���Z�b�g
	void Reset();

	//�I������
	bool IsEnd(void);
	//1�s�̕����ʐݒ�
	void SetAmount(int amount);
	//�����̐F�ݒ�
	void SetColor(int r, int g, int b);
	//�������Ō�܂ň�C�ɕ\��
	void SetAllText();

};