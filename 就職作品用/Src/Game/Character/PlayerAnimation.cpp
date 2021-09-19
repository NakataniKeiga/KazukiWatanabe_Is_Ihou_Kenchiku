#include"PlayerAnimation.h"

// ��`�֘A
static const VECTOR VECTOR_ZERO = { 0.0f, 0.0f, 0.0f };
static const VECTOR DEFAULT_SCALE = { 1.0f, 1.0f, 1.0f };

// �A�j���Đ��^�C�v
enum {
	ANIMSTATE_NORMAL = 0,	// �I����f�^�b�`����(�����g��Ȃ�)
	ANIMSTATE_LOOP,			// �J�Ԃ����[�v
	ANIMSTATE_END,			// �ŏI�t���[���Œ�~

	ANIMSTATE_NUM
};

//------------------------------
//		�R���X�g���N�^
//------------------------------
CAnimation::CAnimation() 
{
	ZeroMemory(&m_sAnimData, sizeof(m_sAnimData));
}



//---------------------------------
//		������
//---------------------------------
void	CAnimation::Init(void)
{
	ZeroMemory(&m_sAnimData, sizeof(m_sAnimData));
	m_sAnimData.m_iHndl = -1;
	m_sAnimData.m_iID = -1;
}


//---------------------------------
//		�A�j���A�b�v�f�[�g
//---------------------------------
void	CAnimation::UpdateAnim(int modelHandle)
{
	if (m_sAnimData.m_iHndl != -1)
	{
		m_sAnimData.m_fFrm += m_sAnimData.m_fSpd;

		if (m_sAnimData.m_fFrm >= m_sAnimData.m_fEndFrm)
		{
			// �ŏI�t���[���܂ŗ�����A��Ԃɍ��킹�ē����ς���
			switch (m_sAnimData.m_iState)
			{
				// �ʏ�͏I��������
			case ANIMSTATE_NORMAL:
				DetachAnim(modelHandle);
				m_sAnimData.m_fEndFrm = 0.f;
				m_sAnimData.m_fFrm = 0.0f;
				m_sAnimData.m_fSpd = 0.0f;
				return;
				// ���[�v�͍ŏ��ɖ߂邾��
			case ANIMSTATE_LOOP:
				m_sAnimData.m_fFrm = 0.0f;
				break;
				// �G���h���[�v�͍Ō�Ŏ~�߂�
			case ANIMSTATE_END:
				m_sAnimData.m_fFrm = m_sAnimData.m_fEndFrm;
				break;
			}
		}

		// �Đ����Ԑݒ�
		MV1SetAttachAnimTime(modelHandle, m_sAnimData.m_iHndl, m_sAnimData.m_fFrm);

	}
}


//---------------------------------
//		�A�j�����N�G�X�g
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
//		���[�v�A�j�����N�G�X�g
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
//		�G���h���[�v�A�j�����N�G�X�g
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
//		�A�j���[�V�����f�^�b�`
//---------------------------------
void	CAnimation::DetachAnim(int modelHandle)
{
	if (m_sAnimData.m_iHndl != -1)
	{
		MV1DetachAnim(modelHandle, m_sAnimData.m_iHndl);
		m_sAnimData.m_iHndl = -1;
	}
}