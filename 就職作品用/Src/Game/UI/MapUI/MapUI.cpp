#include"MapUI.h"
#include"../../Field/StageManager.h"
#include"../../Character/Player/Player.h"
#include"../../Character/Golem/Golem.h"
#include"../../Field/StageManager.h"
#include"../../../Lib/math/MyMath.h"
#include"../../../Lib/math/Hit/Hit.h"

static const char* MAP_PATH_S[] = { "Data/model/UI/iMap.png","Data/model/UI/player.png","Data/model/UI/gorem.png" };
//������
void CMapUI::Init()
{
	m_iHandle = new int[3];
}
//���[�h����
void CMapUI::Load()
{
	for (int map_index = 0; map_index < 3; map_index++)
	{
		m_iHandle[map_index] = LoadGraph(MAP_PATH_S[map_index]);
	}
}
//���C������
void CMapUI::Step()
{
	//CPlayer* player = CPlayer::GetInstance();
	//CGolem* golem = CGolem::GetInstance();
	////�v���C���[�ƃS�[�����̋������v��
	//VECTOR vLong = VSub(player->GetPos(), golem->GetPos());
	//float fLong = MyMath::VecLong(vLong);

	//VECTOR PlayerPos = player->GetPos();
	//VECTOR GolemPos = golem->GetPos();

	////������125�ȉ��Ȃ�E��̃}�b�v�ɃS�[�����p�́E��\��������
	//if (fLong < 125)
	//{
	//	VECTOR pos = VSub(GolemPos, PlayerPos);
	//	m_vDrawPos = VSub(VGet(1140.0f+(pos.x*2), 0.0f, 150.0f), pos);
	//	
	//	m_isMapflg = true;
	//}
	//else
	//{
	//	m_isMapflg = false;
	//}

}
//�`�揈��
void CMapUI::Draw()
{
	DrawRotaGraph(1140, 150, 1.0f, 1.0f, m_iHandle[0], true, false);
	DrawRotaGraph(1140, 150, 0.05f, 1.0f, m_iHandle[1], true, false);
	if (m_isMapflg ==true)
	{
		DrawRotaGraph(static_cast<int>(m_vDrawPos.x), static_cast<int>(m_vDrawPos.z), 0.05f, 1.0f, m_iHandle[2], true, false);
	}
	
}
//�I������
void CMapUI::Fin()
{
	for (int index = 0; index < 1; index)
	{
		DeleteGraph(m_iHandle[index], true);
	}
}