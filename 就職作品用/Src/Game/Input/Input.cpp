#include "Input.h"
#include"DxLib.h"

//静的メンバ変数の宣言
char CInputKey::m_buf[256];
char CInputKey::m_old_Buf[256];


//初期化

void CInputKey::Init()
{
	memset(m_buf, 0, sizeof(m_buf));
	memset(m_old_Buf, 0, sizeof(m_old_Buf));
}

//更新処理

void CInputKey::Update()
{
	memcpy_s(m_old_Buf, sizeof(m_old_Buf), m_buf, sizeof(m_buf));

	GetHitKeyStateAll(m_buf);
}

//ボタンが押されたなら
bool CInputKey::IsPuch(int key)
{
	if (m_buf[key] ==0  && m_old_Buf[key] == 1)return true;

	else return false;
}

//ボタン(トリガー)が押されているなら
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
