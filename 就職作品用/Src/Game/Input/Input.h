#pragma once
class CInputKey {
private:
	static char m_buf[256];     //���݂̃L�[�{�[�h���
	static char m_old_Buf[256];  //1�t���[���O�̃L�[�{�[�h���
	static char m_key_buf[0];
public:
	//������
	static void Init();
	//�X�V����
	static void Update();
	//�{�^�������������H
	static bool IsPuch(int key);
	//�{�^�������������H(�g���K�[)
	static bool IsPuchTrg(int key);

	static bool IsPushDown(int key);
};