#include "MyMath.h"
#include <math.h>

//�����̃x�N�g����x,y,z�̎w�肳�ꂽ���W�ȊO��
//0�ɂ��ĕԂ��֐�	X=0,Y=1,Z=2
VECTOR MyMath::VecToZeros(VECTOR vec, int num) {
	VECTOR result = vec;
	if (num == 0) {	//�@X�ȊO��0�ɂ���
		result.y = 0.f;
		result.z = 0.f;
	}
	if (num == 1) {	//�@Y�ȊO��0�ɂ���
		result.x = 0.f;
		result.z = 0.f;
	}
	if (num == 2) {	//�@Z�ȊO��0�ɂ���
		result.y = 0.f;
		result.x = 0.f;
	}

	return result;
}
//�x�N�g���̗v�������ׂ�0���Ԃ��i0�̏ꍇ��true�j
bool MyMath::CheckVecAllZero(VECTOR vec) {
	if (vec.x != 0.f) { return false; }
	if (vec.y != 0.f) { return false; }
	if (vec.z != 0.f) { return false; }
	return true;
}

//2�̃x�N�g�����r���ē������ǂ�����Ԃ�
bool MyMath::VecSame(VECTOR vec1, VECTOR vec2) {
	if (vec1.x != vec2.x) { return false; }
	if (vec1.y != vec2.y) { return false; }
	if (vec1.z != vec2.z) { return false; }
	return true;
}
//2�_�Ԃ̋�����Ԃ�
float MyMath::GetDistance(VECTOR posA, VECTOR posB){
	float x = posB.x - posA.x;
	float y = posB.y - posA.y;
	float z = posB.z - posA.z;

	return sqrtf(x * x + y * y + z * z);
}
float MyMath::GetDistance(float x1, float y1, float z1, float x2, float y2, float z2) {
	// �_P����_Q�܂ł̒������ΕӂƂ��钼�p�O�p�`�����A
	// �s�^�S���X�̒藝����Εӂ̒������v�Z����B
	float x = x2 - x1;
	float y = y2 - y1;
	float z = z2 + z1;
	float double_c = x * x + y * y + z * z;

	return sqrtf(double_c);
}
//��]�l��0�`2�΂̒l�ɂ���
float MyMath::RadianNormalize(float rad) {
	float result = rad;
	if (result < 0.0f) {
		while (result < 0.0f) { result += DX_TWO_PI_F; }
	}
	else if (result > DX_TWO_PI_F) {
		while (result <= DX_TWO_PI_F) { result -= DX_TWO_PI_F; }
	}

	return result;
}
//�f�B�O���[�p�����W�A���p�֕ϊ�
float MyMath::ChangeRadian(float Deg) {
	float result;
	result = Deg * DX_PI_F / 180.f;
	return result;
}
//���W�A���p���f�B�O���[�p�֕ϊ�
float MyMath::ChangeDegree(float Rad) {
	float result;
	result = Rad * 180.f / DX_PI_F;
	return result;
}
// �n�_�ƏI�_����x�N�g�����쐬
VECTOR MyMath::VecCreate(VECTOR vPosA, VECTOR vPosB){
	VECTOR result;
	result.x = vPosB.x - vPosA.x;
	result.y = vPosB.y - vPosA.y;
	result.z = vPosB.z - vPosA.z;
	return result;
}
//Y���W��0�ɂ����x�N�g����Ԃ�
VECTOR MyMath::GetYNoVec(VECTOR vec) {
	VECTOR result = vec;
	result.y = 0.f;
	return result;
}

// �x�N�g���̒���
float MyMath::VecLong(VECTOR PosA, VECTOR PosB){
	float result;
	result = sqrtf((PosA.x - PosB.x) * (PosA.x - PosB.x) + (PosA.y - PosB.y) * (PosA.y - PosB.y) + (PosA.z - PosB.z) * (PosA.z - PosB.z));
	return result;
}
float MyMath::VecLong(VECTOR Pos) {
	float result;
	result = VecLong(Pos, VGet(0.f, 0.f, 0.f));
	return result;
}

//�x�N�g���{�x�N�g��
VECTOR MyMath::VecAdd(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.x + vecB.x;
	result.y = vecA.y + vecB.y;
	result.z = vecA.z + vecB.z;

	return result;
}
//�x�N�g���|�x�N�g��
VECTOR MyMath::VecSub(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.x - vecB.x;
	result.y = vecA.y - vecB.y;
	result.z = vecA.z - vecB.z;

	return result;

}
//�x�N�g�����X�J���[�l
VECTOR MyMath::VecDiv(VECTOR vec, float num) {
	VECTOR result = { 0 };
	result.x = vec.x / num;
	result.y = vec.y / num;
	result.z = vec.z / num;

	return result;
}
//�x�N�g���~�X�J���[�{
VECTOR MyMath::VecScale(VECTOR vec, float scale){
	VECTOR result;
	result.x = vec.x * scale;
	result.y = vec.y * scale;
	result.z = vec.z * scale;

	return result;
}
//�x�N�g���̓���
float MyMath::VecDot(VECTOR vecA, VECTOR vecB){
	float result;
	result = vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
	return result;
}
//�x�N�g���̊O��
VECTOR MyMath::VecCross(VECTOR vecA, VECTOR vecB){
	VECTOR result;
	result.x = vecA.y * vecB.z - vecA.z * vecB.y;
	result.y = vecA.z * vecB.x - vecA.x * vecB.z;
	result.z = vecA.x * vecB.y - vecA.y * vecB.x;
	return result;
}
//�x�N�g���̓��ς���p�x���v�Z
float MyMath::VecDotRot(VECTOR origin, VECTOR vecA, VECTOR vecB) {
	//�v�Z�p�x
	float result_rot;
	//���_����̍��W�ɕύX
	VECTOR vecA_a = VecSub(vecA, origin);
	VECTOR vecB_b = VecSub(vecB, origin);
	//�e���W�̒������v�Z
	float vecA_long = VecLong(vecA_a);
	float vecB_long = VecLong(vecB_b);
	//���ς��v�Z
	float dot = VecDot(vecA_a, vecB_b);
	//�p�x�v�Z
	result_rot = dot / (vecA_long * vecB_long);
	result_rot = acosf(result_rot);

	return result_rot;
}

// �x�N�g���̌��������W�A���l�Ŏ擾
float MyMath::VecDir(VECTOR vec){
	return atan2f(vec.y, vec.x);
}
//�����̃x�N�g���̊e�p�x���v�Z���ăx�N�g���ŕԂ�
VECTOR MyMath::GetVecRot(VECTOR vec) {
	VECTOR result;
	result.x = atan2f(vec.y, vec.z);
	result.y = atan2f(vec.x, vec.z);
	result.z = atan2f(vec.y, vec.x);

	return result;
}

//�����x�N�g���̎擾�i�p�x�A�ړ��ʁj
VECTOR MyMath::GetSpeed(float rot, float move_speed) {
	MATRIX yaw_mat = GetYawMatrix(rot);
	MATRIX move_mat = GetTranslateMatrix(move_speed, 0.f, 0.f);
	MATRIX result_mat = MatMult(yaw_mat, move_mat);
	VECTOR result = GetTranslateVector(result_mat);
	return result;
}
//�x�N�g���̐��K��
VECTOR MyMath::VecNormalize(VECTOR vec){
	float size;
	VECTOR result;
	size = vec.x * vec.x + vec.y * vec.y + vec.z * vec.z;
	size = sqrtf(size);
	result.x = vec.x / size;
	result.y = vec.y / size;
	result.z = vec.z / size;
	return result;
}
//�x�N�g������]������
VECTOR MyMath::VecRotation(VECTOR vec, VECTOR rotation) {
	MATRIX rotation_mat = GetRotationMatrix(rotation);

	VECTOR result = MyMath::MatTransform(rotation_mat, vec);

	return result;
}
//�P�ʍs��̎擾
MATRIX MyMath::GetldentityMatrix(){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++)	{
		for(int j = 0; j < 4; j++){
			if(i == j){
				result.m[i][j] = 1;
			}
			else{
				result.m[i][j] = 0;
			}
		}
	}

	return result;
}

//MATRIX��VECTOR��
VECTOR MyMath::GetTranslateVector(MATRIX mat) {
	VECTOR result = { 0 };
	result.x = mat.m[0][3];
	result.y = mat.m[1][3];
	result.z = mat.m[2][3];
	return result;
}
//�ړ��s��̎擾
MATRIX MyMath::GetTranslateMatrix(float x, float y, float z)
{
	MATRIX result = GetldentityMatrix();
	result.m[0][3] = x;
	result.m[1][3] = y;
	result.m[2][3] = z;

	return result;
}
MATRIX MyMath::GetTranslateMatrix(VECTOR trans){
	return GetTranslateMatrix(trans.x, trans.y, trans.z);
}
//�g�k�s��̎擾
MATRIX MyMath::GetScaleMatrix(float x, float y, float z){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = x;
	result.m[1][1] = y;
	result.m[2][2] = z;

	return result;
}
MATRIX MyMath::GetScaleMatrix(VECTOR trans){
	return GetScaleMatrix(trans.x, trans.y, trans.z);
}
//X����]�s��̎擾
MATRIX MyMath::GetPitchMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[1][1] = cosf(rot);
	result.m[1][2] = -sinf(rot);
	result.m[2][1] = sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}
//Y����]�s��̎擾
MATRIX MyMath::GetYawMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][2] = sinf(rot);
	result.m[2][0] = -sinf(rot);
	result.m[2][2] = cosf(rot);

	return result;
}
//Z����]�s��̎擾
MATRIX MyMath::GetRollMatrix(float rot){
	MATRIX result = GetldentityMatrix();
	result.m[0][0] = cosf(rot);
	result.m[0][1] = -sinf(rot);
	result.m[1][0] = sinf(rot);
	result.m[1][1] = cosf(rot);

	return result;
}
//��]�s����擾
MATRIX MyMath::GetRotationMatrix(VECTOR rotation) {
	MATRIX move_z = MyMath::GetRollMatrix(rotation.z);
	MATRIX move_y = MyMath::GetYawMatrix(rotation.y);
	MATRIX move_x = MyMath::GetPitchMatrix(rotation.x);
	
	MATRIX result = MyMath::MatMult(move_z, move_y);
	result = MyMath::MatMult(result, move_x);

	return result;
}
//Y����]�̍��W�𔼌a�Ɗp�x��n���Ď擾
VECTOR MyMath::GetYawPosition(float radius, float rot) {
	VECTOR result = { 0 };
	//�ړ��s����擾
	MATRIX result_mat_a = GetTranslateMatrix(radius, 0.f, 0.f);
	//Y�����W�̉�]�s��̎擾
	MATRIX result_mat_b = GetYawMatrix(rot);
	//�v�Z���ʂ��s��Ŏ擾
	MATRIX result_mat = MatMult(result_mat_b, result_mat_a);
	//�v�Z���ʍs������F�N�g���ɕϊ�
	result = GetTranslateVector(result_mat);
	
	return result;
}

//�s��{�s��
MATRIX MyMath::MatAdd(MATRIX matA, MATRIX matB){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = matA.m[i][j] + matB.m[i][j];
		}
	}

	return result;
}
//�s��|�s��
MATRIX MyMath::MatSub(MATRIX matA, MATRIX matB) {
	MATRIX result = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[i][j] = matA.m[i][j] - matB.m[i][j];
		}
	}

	return result;
}

//�s��~�s��
MATRIX MyMath::MatMult(MATRIX matA, MATRIX matB){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				result.m[i][j] += (matA.m[i][k] * matB.m[k][j]);
			}
		}
	}

	return result;
}
//�s��~�X�J���[�l
MATRIX MyMath::MatScale(MATRIX mat, float scale){
	MATRIX result = { 0 };
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			result.m[i][j] = mat.m[i][j] * scale;
		}
	}

	return result;
}
//�x�N�g���~�s��
VECTOR MyMath::MatTransform(MATRIX mat, VECTOR vec){
	float work[4] = { 0 };
	float result_buf[4] = { 0 };
	VECTOR result_vec = { 0 };
	work[0] = vec.x;
	work[1] = vec.y;
	work[2] = vec.z;
	work[3] = 1;
	for(int i = 0; i < 4; i++){
		for(int k = 0; k < 4; k++){
			result_buf[i] += (mat.m[i][k] * work[k]);
		}
	}

	result_vec.x = result_buf[0];
	result_vec.y = result_buf[1];
	result_vec.z = result_buf[2];

	return result_vec;
}
//�s��̓]�u
MATRIX MyMath::MatTranspose(MATRIX mat){
	MATRIX result = { 0 };
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			result.m[j][i] = mat.m[i][j];
		}
	}

	return result;
}
//�|���S���̖@���x�N�g��
VECTOR MyMath::GetPolygonNormalVec(VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	VECTOR vecABAC = VecCross(vecAB, vecAC);
	return VecNormalize(vecABAC);
}
//�N�I�[�^�j�I�����m�̊|���Z
Quaternion MyMath::QuaternionMult(Quaternion quaA, Quaternion quaB) {
	float w1 = quaA.w, w2 = quaB.w;
	VECTOR v1 = { quaA.x,quaA.y ,quaA.z }, v2 = { quaB.x,quaB.y ,quaB.z };

	float result_w = w1 * w2 - VecDot(v1, v2);
	VECTOR result_v = VAdd(VAdd(VecScale(v2, w1), VecScale(v1, w2)), VecCross(v1, v2));

	Quaternion result;
	result.w = result_w;
	result.x = result_v.x;
	result.y = result_v.y;
	result.z = result_v.z;

	return result;
}
float MyMath::GetTriangleHeightXY(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float z = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.y * (point.y - vertexA.y) + vecNorm.z * vertexA.z) / vecNorm.z;

	return z;
}

float MyMath::GetTriangleHeightXZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float y = (-vecNorm.x * (point.x - vertexA.x) - vecNorm.z * (point.z - vertexA.z) + vecNorm.y * vertexA.y) / vecNorm.y;

	return y;
}

float MyMath::GetTriangleHeightYZ(VECTOR point, VECTOR vertexA, VECTOR vertexB, VECTOR vertexC)
{
	// �ӂɉ������x�N�g��AB��AC���v�Z
	VECTOR vecAB = VecCreate(vertexA, vertexB);
	VECTOR vecAC = VecCreate(vertexA, vertexC);
	// �ʖ@�����v�Z
	VECTOR vecNorm = VecCross(vecAB, vecAC);
	vecNorm = VecNormalize(vecNorm);
	// ���ʂ̕��������獂���iY���W���v�Z�j
	float x = (-vecNorm.y * (point.y - vertexA.y) - vecNorm.z * (point.z - vertexA.z) + vecNorm.x * vertexA.x) / vecNorm.x;

	return x;
}

float MyMath::Abs(float val)
{
	if (val < 0.0f) {
		return -val;
	}
	return val;
}

