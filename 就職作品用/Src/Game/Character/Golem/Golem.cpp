#include"Golem.h"
#include"../../Collision/CollisionManager.h"
#include"../../Input/Input.h"
#include"../Player/Player.h"
#include"../../Field/StageManager.h"
#include"../../../Lib/math/Hit/Hit.h"

static const char* DRONE_PATH_S = { "Data/model/golem/golem.x" };
static const float MOVE_SPEED = 0.1f;//移動値
static const float COLL_SPEED = 0.6f;//呼んだ時の速さ
static const float ROTATE_SPEED = 0.1f;//回転値
static const float ANIM_SPD = 0.5f;

//初期化
void CGolem::Init()
{


	CStageManager* Stage = CStageManager::GetInstance();

	CCharacterBase::Init();
	m_vRot.y = DX_PI_F;
	m_fRadius = 1.0f;
	m_fGravity = 0.01f;
	m_state = STATE_STOP;
	m_isChase = false;

	m_vScale = VGet(0.01f, 0.01f, 0.01f);

	VECTOR GolemuPos = Stage->GetManeBone(13, 0);
	SetPos(GolemuPos);
	m_isAlive =false;
	m_isActivate = false;
	if (Stage->GetStageNum() == 1)
	{
		m_vRot.y = 1.5f;
	}

	Load();
}

//ロードの
void CGolem::Load()
{
	//モデルロード
	CCharacterBase::LoadModel(DRONE_PATH_S);

	if (m_isAlive == false)
	{
		m_Anime.RequestEndLoop(m_iHandle,STATE_STOP, ANIM_SPD);
	}
	else
	{
		m_Anime.RequestEndLoop(m_iHandle, STATE_WATING, ANIM_SPD);
	}
}
//メイン処理
void CGolem::Step(CPlayer* player)
{
	switch (m_Anime.GetAnimID())
	{
	case STATE_START:
		Start();
		break;
	case STATE_STOP:
		Stop();
		break;
	case STATE_WATING:
		Wait();
		break;
	case STATE_MOVE:
		Move();
		break;
	}

	Call(player);
	Collision();
	Update();
}

//更新処理
void CGolem::Update()
{


	m_vGravity.y -= m_fGravity;
	//ドローンの座標を更新してセットする
	m_vPos = VAdd(m_vPos, m_vGravity);

	//デバッグ用
	//更新したデータを反映
	m_Anime.UpdateAnim(m_iHandle);

	CCharacterBase::Update();

}

//描画処理
void CGolem::Draw()
{

	CCharacterBase::Draw();

}
//終了処理
void CGolem::Fin()
{
	CCharacterBase::Fin();
}

void CGolem::Collision()
{
	ReflecCollision(CCollisionManager::CollCheckGolemToStage(this));
	ReflecCollision(CCollisionManager::CollCheckGolemToGimmick(this));
}

void CGolem::Start()
{
	if (m_Anime.IsEndAnim() == true)
		m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);

}

void CGolem::Stop()
{
	if (m_isAlive == true)
	{
		m_Anime.RequestEndLoop(m_iHandle, STATE_START, ANIM_SPD);
	}


}

//待機
void CGolem::Wait()
{

	VECTOR Spd = GetSpeed();

	if (m_isActivate == true)
	{
		if (Spd.x != 0.0f || Spd.y != 0.0f || Spd.z != 0.0f)
		{
			m_Anime.RequestLoop(m_iHandle, STATE_MOVE, ANIM_SPD);
			Spd = VScale(Spd, 1.0f);

			CalcSpeed(Spd);
		}
	}
	else if (m_isCall == true)
	{
		if (m_isChase==true)
		{
			m_Anime.RequestLoop(m_iHandle, STATE_MOVE, ANIM_SPD);
			Spd = VScale(Spd, 1.0f);

			CalcSpeed(Spd);
		}
	}

}
//動き
void CGolem::Move()
{
	VECTOR Spd = GetSpeed();
	if (m_isActivate == true)
	{
		if (Spd.x == 0.0f && Spd.y == 0.0f && Spd.z == 0.0f)
		{
			m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		}
		else
		{

			Spd = VScale(Spd, MOVE_SPEED);

			CalcSpeed(Spd);
		}
	}
	if (m_isCall == true)
	{
		if (m_isChase==false)
		{
			m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		}
		else
		{

			Spd = VScale(Spd, MOVE_SPEED);

			CalcSpeed(Spd);
		}
	}
	else 
	{
		if (m_isActivate == false && m_isCall == false)
		{
			m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		}
	}

}

void CGolem::Call(CPlayer* player)
{


	VECTOR PlayerPos = player->GetPos();

	//プレイヤーとの距離
	VECTOR dir = VSub(PlayerPos, m_vPos);
	float len = VSize(dir);
		dir = VNorm(dir);

		dir = VScale(dir, MOVE_SPEED);
	//ゴーレムが起動している・呼ばれている
	if (m_isCall == true && m_isAlive == true && m_isActivate == false)
	{
		if (len <= 5.0f)
		{
			dir = VGet(0.0f, 0.0f, 0.0f);
			SetMove(dir);
			m_isChase = false;

			float rot(atan2f(-dir.x, -dir.z));
			SetRot(VGet(0.0f, rot, 0.0f));
		}
		else if (len >= 100.0f)
		{
			player->SetCall(false);
			m_isCall = false;
			m_isChase = false;
		}
		else
		{

			dir = VScale(dir, COLL_SPEED);
			m_vPos = VAdd(m_vPos,dir);
			m_isChase = true;

			float rot(atan2f(-dir.x, -dir.z));
			SetRot(VGet(0.0f, rot, 0.0f));
		}

	}
	else if(m_isCall==false)
	{
		m_isChase = false;
	}
}

//
VECTOR CGolem::GetSpeed()
{
	CGolemCamera GolemCamera = CCameraManager::GetInstance()->GetGolemCamera();

	bool isMove = false;

	m_vMove = { 0.0f,0.0f,0.0f };
	float spd = 0.1f;

	if (m_isActivate == true)
	{

		if (CInputKey::IsPushDown(KEY_INPUT_D))
		{
			m_vMove.x -= spd;
		}
		if (CInputKey::IsPushDown(KEY_INPUT_A))
		{
			m_vMove.x += spd;
		}
		if (CInputKey::IsPushDown(KEY_INPUT_W))
		{
			m_vMove.z -= spd;
		}
		if (CInputKey::IsPushDown(KEY_INPUT_S))
		{
			m_vMove.z += spd;
		}
	}

	if (m_vMove.x != 0.0f || m_vMove.z != 0.0f)
	{

		m_vMove = VNorm(m_vMove);

		MATRIX mat1, mat2;
		mat1 = MGetTranslate(m_vMove);
		mat2 = MGetRotY(GolemCamera.GetCameraRot().y);
		mat1 = MMult(mat1, mat2);
		m_vMove = VGet(mat1.m[3][0], mat1.m[3][1], mat1.m[3][2]);
	}


	return m_vMove;

}
//ゴーレム後方当たり判定
VECTOR CGolem::GetBackPos()
{
	VECTOR Pos = m_vPos;
	VECTOR Rot = m_vRot;
	VECTOR Dir;

	float len = 5.0f;

	Dir.x = sinf(Rot.y) * len;
	Dir.y = m_fRadius;
	Dir.z = cosf(Rot.y) * len;

	Pos = VAdd(Pos, Dir);

	return Pos;
}

//移動更新
void CGolem::CalcSpeed(VECTOR speed)
{
	m_vPos = VAdd(m_vPos, speed);

	float rotY = atan2f(-speed.x, -speed.z);

	CCharacterBase::SetPos(m_vPos);
	CCharacterBase::SetRot(VGet(0.0f, rotY, 0.0f));

}