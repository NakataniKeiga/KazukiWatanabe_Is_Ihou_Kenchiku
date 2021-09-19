#include"Enemy.h"
#include"../../Field/StageManager.h"
#include"../Player/Player.h"
#include"../../../Lib/math/MyMath.h"
#include"../../../Lib/math/Hit/Hit.h"


static const char* MODEL_PATH_S = { "Data/model/Enemy/Enemy.x" };
#define WALK_SPEED			( 0.01f )	// 歩き速度
static const float ANIM_SPD = 1.0f;
static const int ROOT_NUM = 4;

//初期化
void CEnemy::Init()
{
	memset(&m_vPos, 0, sizeof(VECTOR));
	memset(&m_vRot, 0, sizeof(VECTOR));
	m_fRadius = 2.5f;
	m_fGravity = 0.0f;
	m_vScale = VGet(0.01f, 0.01f, 0.01f);
	m_isChase = false;
	Load();
	
}

//ロード
void CEnemy::Load()
{
	m_iHndl = MV1LoadModel(MODEL_PATH_S);
	//CAnimation::RequestLoop(STATE_CHASE, ANIM_SPD);
}

void CEnemy::Step()
{

//	CPlayer* Player = CPlayer::GetInstance();
//	VECTOR PlayerPos = Player->GetPos();
//
////ここで向き座標を求める
//	VECTOR Spd = MyMath::GetSpeed(m_vRot.y+ DX_PI_F / 2, 1);
////向き座標を現在の座表に加算する
//	VECTOR SpdVec = VAdd(Spd, m_vPos);
////ここで内積の計算をする
//	float Vec_length = MyMath::VecDotRot(m_vPos, PlayerPos, SpdVec);
//	
//	//プレイヤーと敵の現在の距離を計る
//	VECTOR dir = VSub(PlayerPos, m_vPos);
//	float len = VSize(dir);
//
//	
//	if (len < 20.0f)
//	{
//		//プレイヤーとの距離が50以下かつ敵の視界範囲60度に入っているなら
//		if (Vec_length < DX_PI_F / 3)
//		{
//			m_isChase = true;
//		}
//	}
//	else
//	{
//		m_isChase = false;
//	}
//
//	if (CHit::IsHitSphereToSphere(PlayerPos, Player->GetRadius(), GetAttackPos(), m_fRadius))
//	{
//
//		VECTOR Speed=VSub(PlayerPos,m_vPos);
//
//		float len = VSize(Speed);
//
//		Speed = VNorm(Speed);
//
//		Speed.y = 2.8f;
//		Speed.z = 2.5f;
//
//		Speed = VScale(Speed, 0.4f);
//
//		Player->HitCalc(Speed);
//
//		Player->SetHitPoint((Player->GetHitPoint() - 5));
//
//	}
//	
//	Update();
}

//更新処理
void CEnemy::Update()
{
	//重力処理
	m_vGravity.y -= m_fGravity;

	m_vPos = VAdd(m_vPos, m_vGravity);
	

	MV1SetPosition(m_iHndl, m_vPos);
	MV1SetRotationXYZ(m_iHndl, m_vRot);
	MV1SetScale(m_iHndl, m_vScale);
	//CAnimation::UpdateAnim();
}

//描画処理
void CEnemy::Draw()
{
	MV1DrawModel(m_iHndl);
}


//終了処理
void CEnemy::Fin()
{
	MV1DeleteModel(m_iHndl);
}

//攻撃の当たり判定
VECTOR CEnemy::GetAttackPos()
{
	VECTOR pos = m_vPos;
	VECTOR rot = m_vRot;
	VECTOR dir;

	float len = -3.0f;

	dir.x = sinf(rot.y) * len;
	dir.y = m_fRadius;
	dir.z = cosf(rot.y) * len;

	pos = VAdd(pos, dir);

	return pos;
}