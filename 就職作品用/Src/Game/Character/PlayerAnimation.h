#pragma once
#include"DxLib.h"
//�A�j���[�V�����N���X
class CAnimation
{

	private:
		// �A�j���֘A�̃f�[�^���܂Ƃ߂��\����
		typedef struct {
			float	m_fEndFrm;		// �A�j���S�Đ�����
			float	m_fFrm;			// �A�j���Đ�����
			float	m_fSpd;			// �A�j���Đ����x
			int		m_iHndl;		// �A�j���n���h��
			int		m_iID;			// �Đ����̃A�j��ID
			int		m_iState;		// �A�j���̏��
		}ANIM_DATA;

		ANIM_DATA m_sAnimData;		// �A�j���Đ��֘A�f�[�^


public:
	CAnimation();
	virtual ~CAnimation() {};

	//		������
	virtual void	Init(void);
	//		�A�j���S�Đ����Ԏ擾
	inline float	GetAnimEndFrm(void) { return m_sAnimData.m_fEndFrm; }
	//		�A�j���Đ����Ԏ擾
	inline float	GetAnimFrm(void) { return m_sAnimData.m_fFrm; }
	//		�A�j�����x�擾
	inline float	GetAnimSpd(void) { return m_sAnimData.m_fSpd; }
	//		�Đ����̃A�j��ID�擾
	//	@memo	:	�A�j�����Đ�����Ă��Ȃ��ꍇ��-1���߂��Ă���
	inline int		GetAnimID(void) { return m_sAnimData.m_iID; }
	//		�A�j�����I��������
	inline bool		IsEndAnim(void) { return m_sAnimData.m_fEndFrm == m_sAnimData.m_fFrm || m_sAnimData.m_fEndFrm == 0.f; }

	//***************************************
	//		�ݒ�֐�
	//***************************************
	//		�A�j���Đ����Ԑݒ�
	inline void	SetAnimFrm(float fFrm) { m_sAnimData.m_fFrm = fFrm; }
	//		�A�j�����x�ݒ�
	inline void	SetAnimSpd(float fSpd) { m_sAnimData.m_fSpd = fSpd; }

	//		�A�j���A�b�v�f�[�g
	//	@memo	:	�A�j���X�V�����A����Ă�ł�������
	void	UpdateAnim(int modelHandle);
	//		�A�j�����N�G�X�g
	//	iAnimID		:	�A�^�b�`����A�j���ԍ�
	//	iAnimSpd	:	�A�j���Đ����x
	//	iAnimSrcHndl:	�A�j���[�V�����������Ă��郂�f���̃n���h��(-1�Ȃ�΂��̃��f���̃A�j���g�p)
	//	NameCheck	:	�ʃ��f���̃A�j�����g�p����ꍇ�A���f���̃t���[��������v���Ă��Ȃ��ꍇ
	//					�A�j�����A�^�b�`���邩(iAnimSrcHndl=-1�̏ꍇ�͖���)
	void	Request(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//		���[�v�A�j�����N�G�X�g
	//	@memo		:	�A�j�����ŏI�t���[���ɂȂ�����ŏ��ɖ߂�܂��B
	void	RequestLoop(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);
	//		�G���h���[�v�A�j�����N�G�X�g
	//	@memo		:	�A�j�����ŏI�t���[���ɂȂ����炻�̂܂܂Ŏ~�܂�܂��B
	void	RequestEndLoop(int modelHandle,int iAnimID, float iAnimSpd, int iAnimSrcHndl = -1, bool NameCheck = false);

private:
	//		���S�ɃA�j�����f�^�b�`
	void DetachAnim(int modelHandle);
};

