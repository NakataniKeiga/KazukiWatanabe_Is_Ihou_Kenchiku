#include"DxLib.h"
#include"Hit.h"


// ���̓����蔻��(3D) �@
bool CHit::IsHitSphereToSphere(VECTOR pos1, float size1, VECTOR pos2, float size2)
{
	// �܂���2�_�Ԃ̋������v�Z
	VECTOR sub = VSub(pos1, pos2);
	// ���������߂邽�߂�2�悷��
	// ��قǂ̌��ʂ����ׂđ���
	float sum = VSquareSize(sub);

	// ���ꂼ��̖{���̔��a�𑫂��A2�悷��
	float rad = size1 + size2;
	rad *= rad;

	// ���a�𑫂������������Z���Ȃ��Ă�����q�b�g�I
	if (rad > sum) return true;
	else return false;
}


// �{�b�N�X�̓����蔻��
bool CHit::IsHitBoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2)
{
	// �����蔻��p�ɁA���S����[�܂ł̋���(�����̋���)���v�Z
	VECTOR halfSize1, halfSize2;
	halfSize1 = VScale(size1, 0.5f);
	halfSize2 = VScale(size2, 0.5f);

	// X���ł̔���
	bool isHitX = pos1.x - halfSize1.x < pos2.x + halfSize2.x
		&& pos1.x + halfSize1.x > pos2.x - halfSize2.x;
	// Y���ł̔���
	bool isHitY = pos1.y - halfSize1.y < pos2.y + halfSize2.y
		&& pos1.y + halfSize1.y > pos2.y - halfSize2.y;
	// Z���ł̔���
	bool isHitZ = pos1.z - halfSize1.z < pos2.z + halfSize2.z
		&& pos1.z + halfSize1.z > pos2.z - halfSize2.z;
	// �S�Ă̎��œ������Ă����犮��
	if (isHitX && isHitY && isHitZ) return true;
	else return false;
}

//��`�̓����蔻��
bool CHit::IsHitRect(float x1, float y1, float h1, float w1, float x2, float y2, float h2, float w2)
{
	if (x2 + h2 > x1 &&
		x2 < x1 + h1 &&
		y2 + w2 > y1 &&
		y2 < y1 + w1)
	{
		return true;
	}
	else
		return false;
}

//�����̂̓����蔻��
bool CHit::IsHitRect3D(VECTOR pos1, VECTOR size1,VECTOR pos2, VECTOR size2)
{
	//x��y���W�̋�`�̓����蔻�������
	if (IsHitRect(pos1.x, pos1.y, size1.y, size1.x, pos2.x, pos2.y, size2.y, size2.x) == true)
	{
		//Z���̓����蔻�������
		if (pos2.z + size2.z > pos1.z &&
			pos2.z < pos1.z + size1.z)
		{
			return true;
		}
	}
	return false;
}

//�����̂̓����蔻��@���W���^�񒆓��m
bool CHit::IsHitRectCenter3D(VECTOR pos1, VECTOR size1, VECTOR sub1, VECTOR pos2, VECTOR size2, VECTOR sub2)
{
	pos1 = VSub(pos1, sub1);
	pos2 = VSub(pos2, sub2);

	//x��y���W�̋�`�̓����蔻�������
	if (IsHitRect(pos1.x, pos1.y, size1.x, size1.y, pos2.x, pos2.y, size2.x, size2.y) == true)
	{
		//Z���̓����蔻�������
		if (pos2.z + size2.z > pos1.z &&
			pos2.z < pos1.z + size1.z)
		{
			return true;
		}
	}
	return false;
}
