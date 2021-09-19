#include "Input.h"
#include"DxLib.h"

//�ÓI�����o�ϐ��̐錾
char CInputKey::m_buf[256];
char CInputKey::m_old_Buf[256];


//������

void CInputKey::Init()
{
	memset(m_buf, 0, sizeof(m_buf));
	memset(m_old_Buf, 0, sizeof(m_old_Buf));
}

//�X�V����

void CInputKey::Update()
{
	memcpy_s(m_old_Buf, sizeof(m_old_Buf), m_buf, sizeof(m_buf));

	GetHitKeyStateAll(m_buf);
}

//�{�^���������ꂽ�Ȃ�
bool CInputKey::IsPuch(int key)
{
	if (m_buf[key] ==0  && m_old_Buf[key] == 1)return true;

	else return false;
}

//�{�^��(�g���K�[)��������Ă���Ȃ�
bool CInputKey::IsPuchTrg(int key)
{
	if (m_buf[key] == 1 && m_old_Buf != 0)return true;

	else return false;
}

bool CInputKey::IsPushDown(int key)
{
	if (m_buf[key] == 1)
		return true;

	return false;
}
