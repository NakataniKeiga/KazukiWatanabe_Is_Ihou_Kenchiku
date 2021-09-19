#pragma once
#include"DxLib.h"
//アニメーションクラス
class CAnimation
{

	private:
		// アニメ関連のデータをまとめた構造体
		typedef struct {
			float	m_fEndFrm;		// アニメ全再生時間
			float	m_fFrm;			// アニメ再生時間
			float	m_fSpd;			// アニメ再生速度
			int		m_iHndl;		// アニメハンドル
			int		m_iID;			// 再生中のアニメID
			int		m_iState;		// アニメの状態
		}ANIM_DATA;

		ANIM_DATA m_sAnimData;		// アニメ再生関連データ


public:
	CAnimation();
	virtual ~CAnimation() {};

	//		初期化
	virtual void	Init(void);
	//		アニメ全再生時間取得
	inline float	GetAnimEndFrm(void) { return m_sAnimData.m_fEndFrm; }
	//		アニメ再生時間取得
	inline float	GetAnimFrm(void) { return m_sAnimData.m_fFrm; }
	//		アニメ速度取得
	inline float	GetAnimSpd(void) { return m_sAnimData.m_fSpd; }
	//		再生中のアニメID取得
	//	@memo	:	アニメが再生されていない場合は-1が戻ってくる
	inline int		GetAnimID(void) { return m_sAnimData.m_iID; }
	//		アニメが終了したか
	inline bool		IsEndAnim(void) { return m_sAnimData.m_fEndFrm == m_sAnimData.m_fFrm || m_sAnimData.m_fEndFrm == 0.f; }

	//***************************************
	//		設定関数
	//***************************************
	//		アニメ再生時間設定
	inline void	SetAnimFrm(float fFrm) { m_sAnimData.m_fFrm = fFrm; }
	//		アニメ速度設定
	inline void	SetAnimSpd(float fSpd) { m_sAnimData.m_fSpd = fSpd; }

	//		アニメアップデート
	//	@memo	:	アニメ更新処理、毎回呼んでください
	void	UpdateAnim(int modelHandle);
	//		アニメリクエスト
	//	iAnimID		:	アタッチするアニメ番号
	//	iAnimSpd	:	アニメ再生速度
	//	iAnimSrcHndl:	アニメーションを持っているモデルのハンドル(-1ならばこのモデルのアニメ使用)
	//	NameCheck	:	別モデルのアニメを使用する場合、モデルのフレーム名が一致していない場合
	//					アニメをアタッチするか(iAnimSrcHndl=-1の場合は無視)
	void	Request(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//		ループアニメリクエスト
	//	@memo		:	アニメが最終フレームになったら最初に戻ります。
	void	RequestLoop(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//		エンドループアニメリクエスト
	//	@memo		:	アニメが最終フレームになったらそのままで止まります。
	void	RequestEndLoop(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);

private:
	//		安全にアニメをデタッチ
	void DetachAnim(int modelHandle);
};

