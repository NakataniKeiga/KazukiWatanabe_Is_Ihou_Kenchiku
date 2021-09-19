#include"DxLib.h"

static const int FRAME_RATE = 60;								// 1�b�ӂ�̃t���[����
static const int FRAME_RATE_MILLI_SECOND = 1000 / FRAME_RATE;	// ���~���b��1�t���[����

// �t���[�����[�g�Ǘ��p�\����
typedef struct {
	double m_frameRate;			// �t���[�����[�g(��ʕ\���p)
	int m_count;				// �t���[�����J�E���g(��ʕ\���p)
	int m_updateFrameRateTime;	// �t���[�����[�g�X�V����(��ʕ\���p)
	int m_currentTime;			// ���݂�PC����
	int m_lastTime;				// 1�t���[���O��PC����
}FrameData;

// �O���[�o���ϐ��Ƃ��ĊǗ�
static FrameData g_frame = { 0.0 };



//-------------------------------
//		�t���[�����[�g������
//-------------------------------
void InitFrameRate()
{
	// �f�[�^��S�ď��������Ă���
	g_frame.m_count = 0;
	g_frame.m_frameRate = 0.0;
	g_frame.m_currentTime = GetNowCount();
	g_frame.m_lastTime = g_frame.m_currentTime;	// �Ƃ肠���������l���i�[
	g_frame.m_updateFrameRateTime = g_frame.m_currentTime;
}


//-------------------------------
//		�t���[����i�߂Ă��������f
//-------------------------------
bool CheckFrameRate()
{
	// ���݂̎��Ԃ��擾����
	g_frame.m_currentTime = GetNowCount();
	// �O��̎��Ԃ��獡��܂ł̍������v�Z
	int difTime = g_frame.m_currentTime - g_frame.m_lastTime;

	// �O��̎��Ԃ���w�肵���t���[�����o�߂��Ă��邩�`�F�b�N
	if (difTime >= FRAME_RATE_MILLI_SECOND) return true;
	else return false;
}


//-------------------------------
//		�t���[�����[�g�v�Z
//-------------------------------
void CalcFrameRate()
{
	// �O�񎞊Ԃ��X�V
	g_frame.m_lastTime = g_frame.m_currentTime;
}


//-------------------------------
//		FPS�\��
//-------------------------------
void PrintFps()
{
	// 1�t���[���i�񂾂Ɣ��f
	g_frame.m_count++;
	// �O��̕\�����Ԃ��獡��܂ł̍������v�Z
	int difTime = g_frame.m_currentTime - g_frame.m_updateFrameRateTime;

	// 1�b���o�߂���܂Ōo�߂͂���ȍ~���s���Ȃ�
	if (difTime >= 1000)
	{
		float frameCnt = (float)(g_frame.m_count * 1000);
		// �t���[�����[�g���v�Z
		g_frame.m_frameRate = frameCnt / difTime;
		// �J�E���g������
		g_frame.m_count = 0;
		// �t���[�����[�g�X�V���Ԃ��ŐV��
		g_frame.m_updateFrameRateTime = g_frame.m_currentTime;
	}

	// FPS�͏�ɕ\���𑱂���
	DrawFormatString(16, 16, GetColor(255, 255, 255),
		"FPS:%.2lf", g_frame.m_frameRate);
}