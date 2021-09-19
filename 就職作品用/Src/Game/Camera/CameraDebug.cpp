#include"CameraDebug.h"
#include"math.h"

static const float CAMERA_LENGTH = 30.0f;   //
static const float CAMERA_OFFSET_Y = 20.0f;
static const float FOCUS_OFFSET_Y = 10.0f;	// �t�H�[�J�X�̃I�t�Z�b�g
static const float MOVE_SPEED = 2.0f;		// �J�����̈ړ����x


//�R���X�g���N�^
CDebugCamera::CDebugCamera()
{
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	m_near = 1.0f;
	m_far = 1500.0f;
}

//������
void CDebugCamera::Init()
{
	m_vPos = VGet(0.0f, 10.0f, -10.0f);
	memset(&m_vRot, 0, sizeof(m_vRot));
	m_near = 1.0f;
	m_far = 1500.0f;

}
//�Z�b�g�E�j�A�E�t�@�[
void CDebugCamera::SetNearFar(float nearLength, float farLength)
{
	m_near = nearLength;
	m_far = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//���C������
void CDebugCamera::Step(VECTOR focus, float rotY)
{
	float camspeed = 0.1f;
	//�J�����̏㉺��]
	if (CheckHitKey(KEY_INPUT_UP))
	{
		if (m_vRot.x > -90.0 * DX_PI_F / 180.0f)
			m_vRot.x -= camspeed;
	}
	else if (CheckHitKey(KEY_INPUT_DOWN))
	{
		if (m_vRot.x < 90.0 * DX_PI_F / 180.0f)
			m_vRot.x += camspeed;
	}

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_vRot.y += camspeed;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_vRot.y -= camspeed;
	}
	//�J�����̍��E��]
	float spped = 0.0f;
	//�L�����N�^�[�O��ړ�
	if (CheckHitKey(KEY_INPUT_W))spped = MOVE_SPEED;
	else if (CheckHitKey(KEY_INPUT_S))spped = -MOVE_SPEED;

	//���͂����L�[���ƃv���C���[�̊p�x����A�ړ����x�����߂�
	VECTOR v;
	v.x = sinf(m_vRot.y) * spped;
	v.y = 0.0f;
	v.z = cosf(m_vRot.y) * spped;

	//�v���C���[�̍��W���X�V���ăZ�b�g����
	m_vPos = VAdd(m_vPos, v);

	spped = 0.0f;

	//�L�����N�^�[���E�ړ�
	if (CheckHitKey(KEY_INPUT_D))spped = MOVE_SPEED;
	else if (CheckHitKey(KEY_INPUT_A))spped = -MOVE_SPEED;

	v.x = sinf(m_vRot.y + DX_PI_F * 0.5f) * spped;
	v.y = 0.0f;
	v.z = cosf(m_vRot.y + DX_PI_F * 0.5f) * spped;

	m_vPos = VAdd(m_vPos, v); SetCameraPositionAndAngle(m_vPos, m_vRot.x, m_vRot.y, m_vRot.z);

}
//�`��
void CDebugCamera::Draw()
{
	int color = GetColor(255, 255, 255);
	DrawFormatString(32, 32, color, "���݃f�o�b�N���[�h�ł��I");
	DrawFormatString(32, 64, color, "�J�����̍��W:x=%f y=%f z=%f", m_vPos.x, m_vPos.y, m_vPos.z);
	DrawFormatString(32, 96, color, "�J�����̊p�x:x=%f y=%f z=%f", m_vPos.x, m_vPos.y, m_vPos.z);
}