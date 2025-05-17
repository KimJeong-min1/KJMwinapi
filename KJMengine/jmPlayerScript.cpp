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
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos = Vector2::Lerp(pos, Vector2(pos.x + 100.0f, pos.y), 0.05f);
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Left))
		{
			pos = Vector2::Lerp(pos, Vector2(pos.x - 100.0f, pos.y), 0.05f);
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Up))
		{
			pos = Vector2::Lerp(pos, Vector2(pos.x, pos.y - 100.0f), 0.05f);
			tr->SetPosition(pos);
		}
		else if (Input::GetKey(eKeyCode::Down))
		{
			pos = Vector2::Lerp(pos, Vector2(pos.x, pos.y + 100.0f), 0.05f);
			tr->SetPosition(pos);
		}

		//mState = PlayerScript::eState::Idle;
		
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
	}
	void PlayerScript::Idle()
	{
		if (mState == PlayerScript::eState::Idle)
		{
			mAnimator->PlayAnimation(L"PlayerIdel");
		}

		if (Input::GetKeyDown(eKeyCode::Right))
		{
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Up))
		{
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			mState = PlayerScript::eState::Move;
			mAnimator->PlayAnimation(L"PlayerKick");
		}
	}
}