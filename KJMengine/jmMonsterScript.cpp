#include "jmMonsterScript.h"
#include "jmTime.h"
#include "jmGameObject.h"
#include "jmAnimator.h"
#include "jmInput.h"
namespace jm
{
	MonsterScript::MonsterScript()
		:mState(MonsterScript::eState::Idle)
		,mAnimator(nullptr)
	{
	}
	MonsterScript::~MonsterScript()
	{
	}
	void MonsterScript::Initialize()
	{
	}
	void MonsterScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case MonsterScript::eState::Idle:
			Idle();
			break;
		case MonsterScript::eState::Getkick:
			Getkick();
			break;
		}
	}
	void MonsterScript::LateUpdate()
	{
	}
	void MonsterScript::Render(HDC hdc)
	{
	}
	void MonsterScript::Idle()
	{
		if (Input::GetKeyDown(eKeyCode::I))
		{
			mState = MonsterScript::eState::Getkick;
			mAnimator->PlayAnimation(L"Monstergetkicked", true);
		}
	}
	void MonsterScript::Getkick()
	{
		if (Input::GetKeyDown(eKeyCode::P))
		{
			mState = MonsterScript::eState::Idle;
			mAnimator->PlayAnimation(L"MonsterIdle", true);
		}
	}
}
