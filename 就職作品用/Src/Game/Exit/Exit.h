#pragma once
#include"DxLib.h"
#include"../Gimmick/GimmickBase.h"
#include"../../Lib/Singleton.h"

class CExit :public CGimmickBase
{
private:
	//�V�[���̐؂�ւ��t���O
	bool m_isScene;
public:

CExit() { Init(); Load();  };
	~CExit() { Fin(); };

	//������
	void Init();
	//���[�h����
	void Load();

	void Step();
	//�X�V����
	void Update();
	//�`�揈��
	void Draw();
	//�I������
	void Fin();
	//�؂�ւ��t���O�擾
	bool GetIscene() { return m_isScene; }
	//�V�[���̃Z�b�g
	void SetIscene(bool flg) { m_isScene = flg; }

};