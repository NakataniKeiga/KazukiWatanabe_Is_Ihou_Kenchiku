#include"CameraGolem.h"
#include"../Input/Input.h"
//#include"../Character/Golem/Golem.h"
#include"math.h"

	static const float CAMERA_LENGTH = 0.1f;	//�J�����Ƃ̋���
	static const float CAMERA_OFFSET_Y = 2.0f; //�J�����Ƃ�
	static const float FOCUS_DRONE_OFFSET_Y = 0.0f;	//���S�Ƃ�


CGolemCamera::CGolemCamera()
{
	
	memset(&m_vPos, 0, sizeof(m_vPos));
	memset(&m_vRot, 0, sizeof(m_vRot));
	memset(&m_vFocus, 0, sizeof(m_vFocus));
	m_vUp = VGet(0.0f, 1.0f, 0.0f);
	m_fNear = 1.0f;
	m_fFar = 1500.0f;
}

CGolemCamera::~CGolemCamera()
{

}
//������
void CGolemCamera::Init()
{

}
//�j�A�E�t�@�[
void CGolemCamera::SetNeartFar(float nearLength, float farLength)
{
	m_fNear = nearLength;
	m_fFar = farLength;
	SetCameraNearFar(nearLength, farLength);
}
//���C������
void CGolemCamera::Step(VECTOR focus)
{
	if (CInputKey::IsPuchTrg(KEY_INPUT_RIGHT))
	{
		m_vRot.y += 0.05f;
	}

	if (CInputKey::IsPuchTrg(KEY_INPUT_LEFT))
	{
		m_vRot.y -= 0.05f;
	}
	//�i�[����֐�
	MATRIX result = MGetIdent();

	//���ݒn��ۊǂ���
	VECTOR return_pos = focus;

	//�����_�����_��
	VECTOR dronePos = VSub(focus, focus);

	//�����_�����_�ɂ���Ƃ��̃}�g���b�N�X
	MATRIX dronefocus = MGetTranslate(dronePos);

	//�J������ݒu���鐔�l������}�g�b���N�X
	MATRIX campos = MGetTranslate(VGet(dronePos.x, dronePos.y += 2.0f, dronePos.z += 10.0f));

	//��]�p�̍s��
	MATRIX playerCameraPos_X = MGetRotX(m_vRot.x);
	MATRIX playerCameraPos_Y = MGetRotY(m_vRot.y);
	MATRIX playerCameraPos_Z = MGetRotZ(m_vRot.z);

	//���Ƃɖ߂��s��
	MATRIX playerCamera = MGetTranslate(return_pos);
	//���ԂɊ֐��ɓ���Ă���
	result = MMult(result, dronefocus);
	result = MMult(result, campos);
	result = MMult(result, playerCameraPos_X);
	result = MMult(result, playerCameraPos_Y);
	result = MMult(result, playerCameraPos_Z);
	result = MMult(result, playerCamera);
	//
	m_vPos = VTransform(dronePos, result);

	m_vFocus = focus;

}
//�X�V����
void CGolemCamera::Update()
{
	SetCameraNearFar(m_fNear, m_fFar);
	SetCameraPositionAndTargetAndUpVec(m_vPos, m_vFocus, m_vUp);
}