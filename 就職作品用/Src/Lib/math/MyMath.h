#pragma once
#include "DxLib.h"

//�p�x
#define DX_PI_F_HALF (DX_PI_F / 2.f)
#define DX_PI_F_HALF_HALF (DX_PI_F / 4.f)

// Quaternion�\����
struct Quaternion {
	float w;
	float x;
	float y;
	float z;
};

//�x�N�g����s��̌v�Z�������܂Ƃ߂��N���X
//���Ƃł�������w���֐�����������
class MyMath{
public:
	//�����̃x�N�g����x,y,z�̎w�肳�ꂽ���W�ȊO��
	//0�ɂ��ĕԂ��֐�	X=0,Y=1,Z=2
	static VECTOR VecToZeros(VECTOR vec, int num);
	//�x�N�g���̗v�������ׂ�0���Ԃ��i0�̏ꍇ��true�j
	static bool CheckVecAllZero(VECTOR vec);
	//2�̃x�N�g�����r���ē������ǂ�����Ԃ�
	static bool VecSame(VECTOR vec1, VECTOR vec2);
	//2�_�Ԃ̋�����Ԃ�
	static float GetDistance(float x1, float y1, float z1, float x2, float y2, float z2);
	static float GetDistance(VECTOR posA, VECTOR posB);
	//��]�l��0�`2�΂̒l�ɂ���
	static float RadianNormalize(float rad);
	//�f�B�O���[�p�����W�A���p�֕ϊ�
	static float ChangeRadian(float Deg);
	//���W�A���p���f�B�O���[�p�֕ϊ�
	static float ChangeDegree(float Rad);
	// �n�_�ƏI�_����x�N�g�����쐬
	static VECTOR VecCreate(VECTOR PosA, VECTOR PosB);
	//Y���W��0�ɂ����x�N�g����Ԃ�
	static VECTOR GetYNoVec(VECTOR vec);
	// �x�N�g���̒���
	static float VecLong(VECTOR PosA, VECTOR PosB);
	static float VecLong(VECTOR Pos);	//�Е��̃x�N�g�������_�Ƃ����Ƃ��̒����v�Z
	//�x�N�g���{�x�N�g��
	static VECTOR VecAdd(VECTOR vecA, VECTOR vecB);
	//�x�N�g���|�x�N�g��
	static VECTOR VecSub(VECTOR vecA, VECTOR vecB);
	//�x�N�g�����X�J���[�l
	static VECTOR VecDiv(VECTOR vec, float num);
	//�x�N�g���~�X�J���[�{
	static VECTOR VecScale(VECTOR vec, float scale);
	//�x�N�g���̓���
	static float VecDot(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̊O��
	static VECTOR VecCross(VECTOR vecA, VECTOR vecB);
	//�x�N�g���̓��ς���p�x���v�Z
	//origin = ���_�ƂȂ���W
	//vecA�AvecB = ���_����Ăł���p�x�̍��W
	static float VecDotRot(VECTOR origin, VECTOR vecA, VECTOR vecB);
	// �x�N�g���̌��������W�A���l�Ŏ擾
	static float VecDir(VECTOR vec);
	//�����̃x�N�g���̊e�p�x���v�Z���ăx�N�g���ŕԂ�
	static VECTOR GetVecRot(VECTOR vec);
	//�����x�N�g���̎擾�iY���p�x�A�ړ��ʁj
	static VECTOR GetSpeed(float rot, float move_speed);
	//�x�N�g���̐��K��
	static VECTOR VecNormalize(VECTOR vec);
	//�x�N�g������]������
	static VECTOR VecRotation(VECTOR vec, VECTOR rotation);
	//�P�ʍs��̎擾
	static MATRIX GetldentityMatrix();
	//MATRIX��VECTOR
	static VECTOR GetTranslateVector(MATRIX mat);
	//�ړ��s��̎擾
	static MATRIX GetTranslateMatrix(float x, float y, float z);
	static MATRIX GetTranslateMatrix(VECTOR trans);
	//�g�k�s��̎擾
	static MATRIX GetScaleMatrix(float x, float y, float z);
	static MATRIX GetScaleMatrix(VECTOR trans);
	//X����]�s��̎擾(���W�A���p)
	static MATRIX GetPitchMatrix(float rot);
	//Y����]�s��̎擾(���W�A���p)
	static MATRIX GetYawMatrix(float rot);
	//Z����]�s��̎擾(���W�A���p)
	static MATRIX GetRollMatrix(float rot);
	//��]�s����擾
	static MATRIX GetRotationMatrix(VECTOR rotation);
	//Y����]�̍��W�𔼌a�Ɗp�x��n���Ď擾
	static VECTOR GetYawPosition(float radius, float rot);
	//�s��{�s��
	static MATRIX MatAdd(MATRIX matA, MATRIX matB);
	//�s��|�s��
	static MATRIX MatSub(MATRIX matA, MATRIX matB);
	//�s��~�s��
	static MATRIX MatMult(MATRIX matA, MATRIX matB);
	//�s��~�X�J���[�l
	static MATRIX MatScale(MATRIX mat, float scale);
	//�x�N�g���~�s��
	static VECTOR MatTransform(MATRIX mat, VECTOR vec);
	//�s��̓]�u
	static MATRIX MatTranspose(MATRIX mat);
	//�|���S���̖@���x�N�g��
	static VECTOR GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC);
	static float Abs(float val);
	//�N�I�[�^�j�I�����m�̊|���Z
	static Quaternion QuaternionMult(Quaternion quaA, Quaternion quaB);
};
