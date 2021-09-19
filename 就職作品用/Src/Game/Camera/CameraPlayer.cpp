#include"CameraPlayer.h"
#include"../Input/Input.h"
#include"DxLib.h"
#include"math.h"
// �萔�ꗗ
//static const float CAMERA_LENGTH = 10.0f;	// �^�[�Q�b�g�ƃJ�����̋���
//static const float CAMERA_OFFSET_Y = 20.0f;	// �J�����̃I�t�Z�b�g
//static const float FOCUS_OFFSET_Y = 30.0f;	// �t�H�[�J�X�̃I�t�Z�b�g

static const float CAMERA_LENGTH = 30.0f;
static const float CAMERA_OFFSET_Y = 20.0f;
static const float FOCUS_OFFSET_Y = 10.0f;

//�R���X�g���N�^
CPlayCamera::CPlayCamera()
{
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	memset(&m_vFocus, 0, sizeof(m_vFocus));
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
	m_fNear = 1.0f;
	m_fFar = 1500.0f;
}

//������
void CPlayCamera::Init()
{

}
//�j�A�E�t�@�[
void CPlayCamera::SetNearFar(float nearLength, float farLength)
{
	m_fNear = nearLength;
	m_fFar = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//���C������
void CPlayCamera::Step(VECTOR focus)
{
	//VECTOR temp;
	if (CInputKey::IsPuchTrg(KEY_INPUT_UP))
	{
		m_vRot.x += 0.00f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_DOWN))
	{
		m_vRot.x -= 0.00f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_RIGHT))
	{
		m_vRot.y += 0.01f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_LEFT))
	{
		m_vRot.y -= 0.01f;
	}

	

	//�i�[����֐�
	MATRIX result=MGetIdent();

	//���ݒn��ۊǂ���
	VECTOR return_pos = focus;

	//�����_�����_��
	VECTOR playerPos = VSub(focus, focus);

	//�����_�����_�ɂ���Ƃ��̃}�g���b�N�X
	MATRIX playerfocus = MGetTranslate(playerPos);

	//�J������ݒu���鐔�l������}�g�b���N�X
	MATRIX campos = MGetTranslate(VGet(playerPos.x, playerPos.y += 1.5f, playerPos.z +=5.0f));

	//��]�p�̍s��
	MATRIX playerCameraPos_X = MGetRotX(m_vRot.x);
	MATRIX playerCameraPos_Y = MGetRotY(m_vRot.y);
	MATRIX playerCameraPos_Z = MGetRotZ(m_vRot.z);

	//���Ƃɖ߂��s��
	MATRIX playerCamera = MGetTranslate(return_pos);

	result = MMult(result,playerfocus);
	result = MMult(result, campos);
	result = MMult(result, playerCameraPos_X);
	result = MMult(result, playerCameraPos_Y);
	result = MMult(result, playerCameraPos_Z);
	result = MMult(result, playerCamera);

	m_vPos = VTransform(playerPos, result);
	//�����_��ݒ�
	m_vFocus = focus;


 
}

//�X�V����
void CPlayCamera::Update()
{
	SetCameraNearFar(m_fNear, m_fFar);
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vFocus, m_vUp);
}