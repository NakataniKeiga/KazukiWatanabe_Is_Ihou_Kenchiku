#include"PlayerAnimation.h"

// 定義関連
static const VECTOR VECTOR_ZERO = { 0.0f, 0.0f, 0.0f };
static const VECTOR DEFAULT_SCALE = { 1.0f, 1.0f, 1.0f };

// アニメ再生タイプ
enum {
	ANIMSTATE_NORMAL = 0,	// 終了後デタッチする(多分使わない)
	ANIMSTATE_LOOP,			// 繰返しループ
	ANIMSTATE_END,			// 最終フレームで停止

	ANIMSTATE_NUM
};

//------------------------------
//		コンストラクタ
//------------------------------
CAnimation::CAnimation() 
{
	ZeroMemory(&m_sAnimData, sizeof(m_sAnimData));
}



//---------------------------------
//		初期化
//---------------------------------
void	CAnimation::Init(void)
{
	ZeroMemory(&m_sAnimData, sizeof(m_sAnimData));
	m_sAnimData.m_iHndl = -1;
	m_sAnimData.m_iID = -1;
}


//---------------------------------
//		アニメアップデート
//---------------------------------
void	CAnimation::UpdateAnim(int modelHandle)
{
	if (m_sAnimData.m_iHndl != -1)
	{
		m_sAnimData.m_fFrm += m_sAnimData.m_fSpd;

		if (m_sAnimData.m_fFrm >= m_sAnimData.m_fEndFrm)
		{
			// 最終フレームまで来たら、状態に合わせて動作を変える
			switch (m_sAnimData.m_iState)
			{
				// 通常は終了させる
			case ANIMSTATE_NORMAL:
				DetachAnim(modelHandle);
				m_sAnimData.m_fEndFrm = 0.f;
				m_sAnimData.m_fFrm = 0.0f;
				m_sAnimData.m_fSpd = 0.0f;
				return;
				// ループは最初に戻るだけ
			case ANIMSTATE_LOOP:
				m_sAnimData.m_fFrm = 0.0f;
				break;
				// エンドループは最後で止める
			case ANIMSTATE_END:
				m_sAnimData.m_fFrm = m_sAnimData.m_fEndFrm;
				break;
			}
		}

		// 再生時間設定
		MV1SetAttachAnimTime(modelHandle, m_sAnimData.m_iHndl, m_sAnimData.m_fFrm);

	}
}


//---------------------------------
//		アニメリクエスト
//---------------------------------
void	CAnimation::Request(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	DetachAnim(modelHandle);

	m_sAnimData.m_iHndl = MV1AttachAnim(modelHandle, iAnimID, iAnimSrcHndl, NameCheck);
	m_sAnimData.m_iID = iAnimID;
	m_sAnimData.m_fEndFrm = MV1GetAnimTotalTime(modelHandle, iAnimID);
	m_sAnimData.m_fFrm = 0.f;
	m_sAnimData.m_fSpd = iAnimSpd;
	m_sAnimData.m_iState = ANIMSTATE_NORMAL;
}


//---------------------------------
//		ループアニメリクエスト
//---------------------------------
void	CAnimation::RequestLoop(int modelHandle, int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	DetachAnim(modelHandle);

	m_sAnimData.m_iHndl = MV1AttachAnim(modelHandle, iAnimID, iAnimSrcHndl, NameCheck);
	m_sAnimData.m_iID = iAnimID;
	m_sAnimData.m_fEndFrm = MV1GetAnimTotalTime(modelHandle, iAnimID);
	m_sAnimData.m_fFrm = 0.f;
	m_sAnimData.m_fSpd = iAnimSpd;
	m_sAnimData.m_iState = ANIMSTATE_LOOP;
}


//---------------------------------
//		エンドループアニメリクエスト
//---------------------------------
void	CAnimation::RequestEndLoop(int modelHandle, int iAnimID, float iAnimSpd, int iAnimSrcHndl, bool NameCheck)
{
	DetachAnim(modelHandle);

	m_sAnimData.m_iHndl = MV1AttachAnim(modelHandle, iAnimID, iAnimSrcHndl, NameCheck);
	m_sAnimData.m_iID = iAnimID;
	m_sAnimData.m_fEndFrm = MV1GetAnimTotalTime(modelHandle, iAnimID);
	m_sAnimData.m_fFrm = 0.f;
	m_sAnimData.m_fSpd = iAnimSpd;
	m_sAnimData.m_iState = ANIMSTATE_END;
}


//---------------------------------
//		アニメーションデタッチ
//---------------------------------
void	CAnimation::DetachAnim(int modelHandle)
{
	if (m_sAnimData.m_iHndl != -1)
	{
		MV1DetachAnim(modelHandle, m_sAnimData.m_iHndl);
		m_sAnimData.m_iHndl = -1;
	}
}