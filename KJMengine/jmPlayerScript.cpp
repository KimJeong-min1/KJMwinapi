#include "jmPlayerScript.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"
#include "jmGameObject.h"
#include "jmAnimator.h"

namespace jm
{
	PlayerScript::PlayerScript()
		:mState(PlayerScript::eState::Idle)
		,mAnimator(nullptr)
		,mdir(0)
		,mTime(0.0f)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case jm::PlayerScript::eState::Idle:
			Idle();
			break;
		case jm::PlayerScript::eState::Move:
			Move();
			break;

		case jm::PlayerScript::eState::Kick:
			Kick();
			break;
		case jm::PlayerScript::eState::Dead:
			Dead();
			break;
		}

	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::Move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Pos = tr->GetPosition();
		mTime += Time::DeltaTime();
		
		if (mdir == 1)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x + 100.0f, Prevpos.y), 0.05f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 2)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x - 100.0f, Prevpos.y), 0.05f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 3)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y - 100.0f), 0.05f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 4)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y + 100.0f), 0.05f);
			tr->SetPosition(Pos);
		}
		

		if (mTime > 1.0f)
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"PlayerIdle");
			mTime = 0;
		}
		// 선형보간 공부해오기
		// 좌,우,상,하
		// idle상태
		// monster 스크립트 구현
	}
	void PlayerScript::Kick()
	{
	}
	void PlayerScript::Dead()
	{
		// 0번누르면 죽게만들기
	}
	void PlayerScript::Idle()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 1;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 2;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerLeftKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 3;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 4;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
	}
}