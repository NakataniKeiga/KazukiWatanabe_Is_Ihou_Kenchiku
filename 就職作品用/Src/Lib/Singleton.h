#ifndef __SINGLETON_H__
#define __SINGLETON_H__

//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
//継承先のコンストラクタ、デストラクタは
//publicで作るように!
//＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊

//"T"は各継承先のクラス名
template <class T>

//シングルトン継承用クラス
class CSingleton { 
private:
protected:
	//コンストラクタ、デストラクタ
	CSingleton() {}
	~CSingleton(){}
	static T* Instance;			//インスタンス

public:
	//インスタンス取得
	static T* GetInstance() {
		//インスタンスがないなら生成
		if (Instance == nullptr) {
			Instance = new T;
		}
		return Instance;
	}
	//インスタンス削除
	static void DeleteInstance() {
		//インスタンスがあるなら削除
		if (Instance != nullptr) {
			delete Instance;
			Instance = nullptr;
		}
	}
};

//静的メンバ変数の宣言
template <class T>
T* CSingleton<T>::Instance = nullptr;

#endif