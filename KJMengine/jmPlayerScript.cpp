#include "jmPlayerScript.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"
#include "jmGameObject.h"
#include "jmAnimator.h"

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
		// GameObject�� ���ؼ� PlayerScript Ŭ������ ������Ʈ�� Ȱ��ȭ��Ų��.
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
	void PlayerScript::RightMove()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Pos = tr->GetPosition();
		mTime += Time::DeltaTime();

		if (mdir == 1)
		{
			Pos = Vector2::Lerp(Pos, Vector2(Prevpos.x + 100.0f, Prevpos.y), 0.05f);
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


		if (mTime > 2.0f)
		{
			mState = PlayerScript::eState::RightIdle;
			mAnimator->PlayAnimation(L"RightIdle");
			mTime = 0;
		}
		// �������� �����ؿ���
		// ��,��,��,��
		// idle����
		// monster ��ũ��Ʈ ����
	}
	void PlayerScript::LeftMove()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Pos = tr->GetPosition();
		mTime += Time::DeltaTime();
		
		if (mdir == 2)
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
		// 0�������� �װԸ����
		mTime += Time::DeltaTime();
		
		if (mTime > 1.0f)
		{
			mState = PlayerScript::eState::RightIdle;
			mAnimator->PlayAnimation(L"RightIdle");
			mTime = 0;
		}
	}
}