#ifndef __SINGLETON_H__
#define __SINGLETON_H__

//��������������������������������������
//�p����̃R���X�g���N�^�A�f�X�g���N�^��
//public�ō��悤��!
//��������������������������������������

//"T"�͊e�p����̃N���X��
template <class T>

//�V���O���g���p���p�N���X
class CSingleton { 
private:
protected:
	//�R���X�g���N�^�A�f�X�g���N�^
	CSingleton() {}
	~CSingleton(){}
	static T* Instance;			//�C���X�^���X

public:
	//�C���X�^���X�擾
	static T* GetInstance() {
		//�C���X�^���X���Ȃ��Ȃ琶��
		if (Instance == nullptr) {
			Instance = new T;
		}
		return Instance;
	}
	//�C���X�^���X�폜
	static void DeleteInstance() {
		//�C���X�^���X������Ȃ�폜
		if (Instance != nullptr) {
			delete Instance;
			Instance = nullptr;
		}
	}
};

//�ÓI�����o�ϐ��̐錾
template <class T>
T* CSingleton<T>::Instance = nullptr;

#endif