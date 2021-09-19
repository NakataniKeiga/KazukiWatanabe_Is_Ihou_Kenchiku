#include"Player.h"
#include"../../Input/Input.h"
#include"../Golem/Golem.h"
#include"../../Collision/CollisionManager.h"
#include"../../../Lib/math/Hit/Hit.h"
#include"../../Camera/CamaraManager.h"
#include"math.h"


static const char* MODEL_PATH_S = { "Data/model/Player/Player.x" };
static const float MOVE_SPEED = 0.2f;   //移動値
static const float ROTATE_SPEED = 0.1f; //回転値
static const VECTOR PLAYER_SCALE = { 0.06f, 0.06f, 0.06f };
static const VECTOR KNOCK_BACK = { 0.07f, 0.07f, 0.07f };
const float GRAVITY_SPEED = 0.01f;
const float PLAYER_RADIUS = 1.0f;
static const float JUMP_SPEED = 1.0f;
static const float ANIM_SPD = 0.4f;
static const int PLAYER_HP = 5;

//初期化
void CPlayer::Init()
{
	m_kind = PLAYER;
	CCharacterBase::Init();
	m_state = STATE_WATING;
	m_vRot.y = DX_PI_F;
	m_vScale = PLAYER_SCALE;
	m_vSpeed = KNOCK_BACK;
	m_iHitPoint = PLAYER_HP;
	m_fGravity = GRAVITY_SPEED;
	m_fRadius = PLAYER_RADIUS;
	m_isAlive = true;
	m_isKeyHave_Flg = false;
	m_isShove_Flg = false;
	m_isLever_Flg = false;
	m_isZenmaiHave_Flg = false;
	m_isCall = false;


	Load();
}
//モデルのロード
void CPlayer::Load()
{
	CCharacterBase::LoadModel(MODEL_PATH_S);
}


void CPlayer::IsChange(CGolem* golem)
{
	/*CGolem* Golem = CGolem::GetInstance();*/
	//ゴーレムを呼ぶ処理
	if (golem->GetIsAlive() == true && golem->GetActivate() == false && m_isActivate == true)
	{
		if (CInputKey::IsPuch(KEY_INPUT_C))
		{
			if (m_isCall == true)
			{
				m_isCall = false;
				golem->SetCall(false);

			}
			else if (m_isCall == false)
			{
				m_isCall = true;
				golem->SetCall(true);
			}
		}

	}
	//プレイヤーとゴーレム切り替え
	if (golem->GetIsAlive() == true)
	{
		if (CInputKey::IsPuch(KEY_INPUT_G))
		{
			if (m_isActivate == true)
			{
				golem->SetActivate(true);
				golem->SetIsAlive(true);
				m_isActivate = false;
				m_isCall = false;
			}

			else if (m_isActivate == false)
			{
				golem->SetActivate(false);
				m_isActivate = true;
			}
		}
	}

}
//メイン処理
void CPlayer::Step(CGolem* golem)
{
	if (m_iHitPoint == 0)
	{
		m_isAlive = false;
	}

	if (m_isAlive == true)
	{
		if (m_isActivate == true)
		{
			switch (m_Anime.GetAnimID())
			{
			case 0:
				Run();
				break;
			case 1:
				Wait(golem);
				break;
			case STATE_BOXHAVE_1:
				Have();
				break;
			case STATE_BOXHAVE_WAIT:
				HaveWait();
				break;
			case STATE_BOXHAVE_WALK:
				HaveMove();
				break;
			case STATE_GOLEM_START:
				GolemStart(golem);
				break;
			}
			if (m_state == STATE_BACK)
			{
				MoveBack();
			}

		}
	}

	Collision();

	IsChange(golem);
	Update();
}




//更新処理
void CPlayer::Update()
{
	//重力処理
	m_vGravity.y -= m_fGravity;
	m_vPos = VAdd(m_vPos, m_vGravity);
	
	//更新したデータを反映
	CCharacterBase::Update();
	m_Anime.UpdateAnim(m_iHandle);
}
//描画
void CPlayer::Draw()
{
	CCharacterBase::Draw();
}
//終了処理
void CPlayer::Fin()
{
	CCharacterBase::Fin();
}

void CPlayer::Collision()
{
	ReflecCollision(CCollisionManager::CollCheckPlayerToStage(this));
	ReflecCollision(CCollisionManager::CollCheckPlayerToGimmick(this));
	CCollisionManager::CollCheckPlayerToItem(this);


}
//待機
void CPlayer::Wait(CGolem* golem)
{
	VECTOR Spd = GetSpeed();

	if (Spd.x != 0.0f || Spd.y != 0.0f || Spd.z != 0.0f)
	{

		//歩く
		m_Anime.RequestLoop(m_iHandle,STATE_WALK, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);

		CalcSpeed(Spd);
	}
	else if (m_isShove_Flg == true)
	{
		m_Anime.RequestEndLoop(m_iHandle, STATE_BOXHAVE_1, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);
	}

	//CGolem* Golem = CGolem::GetInstance();

	if (CInputKey::IsPuch(KEY_INPUT_SPACE))
	{
		if (CHit::IsHitSphereToSphere(golem->GetBackPos(), golem->GetRadius(), m_vPos, m_fRadius))
		{
			if (m_isZenmaiHave_Flg == true)
			{
				SetPos(golem->GetBackPos());
				SetRot(golem->GetRot());
				m_Anime.Request(m_iHandle, STATE_GOLEM_START, ANIM_SPD);
			}
		}
	}

}


void CPlayer::Run()
{
	VECTOR Spd = GetSpeed();

	if (Spd.x == 0.0f && Spd.y == 0.0f && Spd.z == 0.0f)
	{
		m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
	}
	else if (m_isShove_Flg == true)
	{
		m_Anime.RequestEndLoop(m_iHandle, STATE_BOXHAVE_1, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);
	}
	else
	{
		//歩く
		Spd = VScale(Spd, MOVE_SPEED);

		CalcSpeed(Spd);
	}


}

void CPlayer::Have()
{
	if (m_Anime.IsEndAnim() == true)
	{
		m_Anime.RequestLoop(m_iHandle, STATE_BOXHAVE_WAIT, ANIM_SPD);
	}

}

void CPlayer::HaveWait()
{
	VECTOR Spd = GetSpeed();

	if (Spd.x != 0.0f || Spd.y != 0.0f || Spd.z != 0.0f)
	{
		//歩く
		m_Anime.RequestLoop(m_iHandle, STATE_BOXHAVE_WALK, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);

		CalcSpeed(Spd);
	}
	else if (m_isShove_Flg == false)
	{
		m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);
	}

}

void CPlayer::HaveMove()
{
	VECTOR Spd = GetSpeed();

	if (Spd.x == 0.0f && Spd.y == 0.0f && Spd.z == 0.0f)
	{
		m_Anime.RequestLoop(m_iHandle, STATE_BOXHAVE_WAIT, ANIM_SPD);
	}
	else if (m_isShove_Flg == false)
	{
		m_Anime.RequestEndLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		Spd = VScale(Spd, MOVE_SPEED);
	}
	else
	{
		//歩く
		Spd = VScale(Spd, MOVE_SPEED);

		CalcSpeed(Spd);
	}
}

void CPlayer::GolemStart(CGolem* golem)
{
	/*CGolem* Golem = CGolem::GetInstance();*/

	if (m_Anime.IsEndAnim() == true)
	{
		m_Anime.RequestLoop(m_iHandle, STATE_WATING, ANIM_SPD);
		golem->SetIsAlive(true);
	}

}

//十字キーの方向取得
VECTOR CPlayer::GetSpeed()
{
	CPlayCamera PlayerCamera = CCameraManager::GetInstance()->GetCamera();

	bool isMove = false;
	
	m_vMove = { 0.0f,0.0f,0.0f };
	float spd = 10.0f;

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



	if (m_vMove.x != 0.0f || m_vMove.z != 0.0f)
	{
		m_vMove = VNorm(m_vMove);

		MATRIX mat1, mat2;
		mat1 = MGetTranslate(m_vMove);
		mat2 = MGetRotY(PlayerCamera.GetCameraRot().y);
		mat1 = MMult(mat1, mat2);
		m_vMove = VGet(mat1.m[3][0], mat1.m[3][1], mat1.m[3][2]);
	}
	return m_vMove;
}

//プレイヤーの前方の当たり判定
VECTOR CPlayer::GetHitPos()
{
	VECTOR Pos = m_vPos;
	VECTOR Rot = m_vRot;
	VECTOR Dir;

	float len = -3.0f;

	Dir.x = sinf(Rot.y) * len;
	Dir.y = m_fRadius;
	Dir.z = cosf(Rot.y) * len;

	Pos = VAdd(Pos, Dir);

	return Pos;
}

//速度をプレイヤーに反映させる
void CPlayer::CalcSpeed(VECTOR speed)
{
	m_vPos = VAdd(m_vPos, speed);

	float rotY = atan2f(-speed.x, -speed.z);

	CCharacterBase::SetPos(m_vPos);
	CCharacterBase::SetRot(VGet(0.0f, rotY, 0.0f));

}

//ノックバック
//当たった時の更新処理
void CPlayer::HitCalc(VECTOR m_speed)
{
	m_vSpeed = m_speed;
	m_state = STATE_BACK;
}

//ノックバック処理
void CPlayer::MoveBack()
{

	m_vPos = VAdd(m_vPos, m_vSpeed);
	SetPos(m_vPos);

	m_vSpeed = VScale(m_vSpeed, 0.9f);

	if (VSize(m_vSpeed) < 0.1f)
	{
		m_state = STATE_WATING;
	}

}