#include"SceneGameOver.h"
#include"../../Input/Input.h"

static const char* GAMEOVER_PATH_S = { "Data/model/Scene/gameover/gameover.png" };
//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{
	Init();
}
//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{
	Fin();
}
//������
void CSceneGameOver::Init()
{
	
	m_iHndle = new int[1];
	Load();
}
//���[�h����
void CSceneGameOver::Load()
{
	m_iHndle[0] = LoadGraph(GAMEOVER_PATH_S);
}
//���C������
int CSceneGameOver::Step()
{
	int ret = -1;
	if (CInputKey::IsPuch(KEY_INPUT_RETURN))
	{
		ret = SCENE_TITLE;
	}
	return ret;

}
//�`�揈��
void CSceneGameOver::Draw()
{

	DrawGraph(0, 0, m_iHndle[0], true);

}
//�I������
void CSceneGameOver::Fin()
{
	delete[] m_iHndle;

}