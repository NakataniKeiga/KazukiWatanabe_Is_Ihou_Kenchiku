#include"SceneClear.h"
#include"../../Input/Input.h"
#include"../../Common.h"

CSceneClear::~CSceneClear()
{
	Fin();
}
//�����l
void CSceneClear::Init()
{
	m_iHndle = -1;
}
//�`��
void CSceneClear::Draw()
{
	
		DrawFormatString(100, 100, GetColor(255, 255, 255), "�N���A Enter�Ń^�C�g��");
	
}
//���C������
int CSceneClear::Step()
{

	int ret = -1;
	if (CInputKey::IsPuch(KEY_INPUT_RETURN))
	{
		ret = SCENE_TITLE;
	}
	return ret;
}
//�I������
void CSceneClear::Fin()
{

	if (m_iHndle != 1)
	{
		m_iHndle = -1;
	}
}