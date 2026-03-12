#include "jmPlayerScript.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"
#include "jmGameObject.h"
#include "jmAnimator.h"
#include "jmMonsterScript.h"

namespace jm
{
	PlayerScript::PlayerScript()
		:mState(PlayerScript::eState::RightIdle)
		, mAnimator(nullptr)
		, mdir(0)
		, mTime(0.0f)
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
		// GameObject를 통해서 PlayerScript 클래스의 업데이트를 활성화시킨다.
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case jm::PlayerScript::eState::RightMove:
			RightMove();
			break;
		case jm::PlayerScript::eState::LeftMove:
			LeftMove();
			break;
		case jm::PlayerScript::eState::RightKick:
			RightKick();
			break;
		case jm::PlayerScript::eState::LeftKick:
			LeftKick();
			break;
		case jm::PlayerScript::eState::RightIdle:
			RightIdle();
			break;
		case jm::PlayerScript::eState::LeftIdle:
			LeftIdle();
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
	void PlayerScript::AttackEffect()
	{
	}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{
	}
	void PlayerScript::OnCollisionExit(Collider* other)
	{
	}
	void PlayerScript::SetMapData(std::vector<std::vector<GameObject*>>& mapdata)
	{
		mMapdata = &mapdata;
	}
	void PlayerScript::RightMove()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Pos = tr->GetPosition();
		mTime += Time::DeltaTime();
		int prevtileX = (Prevpos.x / 84.0f);
		int prevtileY = (Prevpos.y / 84.0f);
		if (mdir == 1)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x + 84.0f, Prevpos.y), 0.5f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 3)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y - 84.0f), 0.5f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 4)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y + 84.0f), 0.5f);
			tr->SetPosition(Pos);
		}

		prevtileX = prevtileX - 5;
		prevtileY = prevtileY - 1;

		(*mMapdata)[prevtileY][prevtileX] = nullptr;
		
		if (mTime > 1.0f)
		{
			Vector2 finalPos = tr->GetPosition();

			int tileX = (finalPos.x / 84.0f);
			int tileY = (finalPos.y / 84.0f);

			tileX = tileX - 5;
			tileY = tileY - 1;

			GameObject* target = (*mMapdata)[tileY][tileX];

			if (target != nullptr)
			{
				MonsterScript* monster =
					target->GetComponent<MonsterScript>();
				if (monster)
				{
					monster->Gettype();
				}
			}
		
			(*mMapdata)[tileY][tileX] = GetOwner();
			
			mState = PlayerScript::eState::RightIdle;
			mAnimator->PlayAnimation(L"RightIdle");
			mTime = 0;
		}
		// 선형보간 공부해오기
		// 좌,우,상,하
		// idle상태
		// monster 스크립트 구현
	}
	void PlayerScript::LeftMove()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Pos = tr->GetPosition();
		mTime += Time::DeltaTime();
		int prevtileX = (Prevpos.x / 84.0f);
		int prevtileY = (Prevpos.y / 84.0f);

		if (mdir == 2)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x - 84.0f, Prevpos.y), 0.5f);
			tr->SetPosition(Pos);	
		}
		else if (mdir == 3)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y - 84.0f), 0.5f);
			tr->SetPosition(Pos);
		}
		else if (mdir == 4)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x, Prevpos.y + 84.0f), 0.5f);
			tr->SetPosition(Pos);
		}

		prevtileX = prevtileX - 5;
		prevtileY = prevtileY - 1;

		(*mMapdata)[prevtileY][prevtileX] = nullptr;

		if (mTime > 1.0f)
		{
			Vector2 finalPos = tr->GetPosition();

			int tileX = (finalPos.x / 84.0f);
			int tileY = (finalPos.y / 84.0f);

			tileX = tileX - 5;
			tileY = tileY - 1;

			(*mMapdata)[tileY][tileX] = GetOwner();

			mState = PlayerScript::eState::LeftIdle;
			mAnimator->PlayAnimation(L"LeftIdle");
			mTime = 0;
		}
	}
	void PlayerScript::RightKick()
	{
	}
	void PlayerScript::LeftKick()
	{

	}
	void PlayerScript::LeftIdle()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 1;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::RightMove;
			mAnimator->PlayAnimation(L"RightKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 2;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::LeftMove;
			mAnimator->PlayAnimation(L"LeftKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();

			mdir = 3;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::LeftMove;
			mAnimator->PlayAnimation(L"LeftKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 4;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::LeftMove;
			mAnimator->PlayAnimation(L"LeftKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Zero))
		{
			mState = PlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"PlayerDead");
		}
	}
	void PlayerScript::RightIdle()
	{
		if (Input::GetKeyDown(eKeyCode::Right))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 1;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::RightMove;
			mAnimator->PlayAnimation(L"RightKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Left))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 2;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::LeftMove;
			mAnimator->PlayAnimation(L"LeftKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Up))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();

			mdir = 3;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::RightMove;
			mAnimator->PlayAnimation(L"RightKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Down))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			mdir = 4;
			Prevpos = tr->GetPosition();
			mState = PlayerScript::eState::RightMove;
			mAnimator->PlayAnimation(L"RightKick");
		}
		else if (Input::GetKeyDown(eKeyCode::Zero))
		{
			mState = PlayerScript::eState::Dead;
			mAnimator->PlayAnimation(L"PlayerDead");
		}
	}
	void PlayerScript::Dead()
	{
		// 0번누르면 죽게만들기
		mTime += Time::DeltaTime();
		
		if (mTime > 1.0f)
		{
			mState = PlayerScript::eState::RightIdle;
			mAnimator->PlayAnimation(L"RightIdle");
			mTime = 0;
		}
	}
}