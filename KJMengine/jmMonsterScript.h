#pragma once
#include "..\\KJMengine_SOURCE\\jmScript.h"
namespace jm
{
	class MonsterScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Getkick,
		};
		MonsterScript();
		~MonsterScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Idle();
		void Getkick();

	private:
		eState mState;
		class Animator* mAnimator;
		class Time* mTime;
	};
}

