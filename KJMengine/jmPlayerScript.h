#pragma once
#include "..\\KJMengine_SOURCE\\\jmScript.h"

namespace jm
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Move,
			Dead,
			Kick,
			Idle,
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:
		void Move();
		void Kick();
		void Dead();
		void Idle();
	
	private:
		eState mState;
		class Animator* mAnimator;
		class Time* mTime;
	};
}

