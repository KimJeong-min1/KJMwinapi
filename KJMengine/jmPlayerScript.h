#pragma once
#include "..\\KJMengine_SOURCE\\\jmScript.h"

namespace jm
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			RightMove,
			LeftMove,
			RightKick,
			LeftKick,
			RightIdle,
			LeftIdle,
			Dead,
		};
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void AttackEffect();

	private:
		void RightMove();
		void LeftMove();
		void RightKick();
		void Dead();
		void RightIdle();
		void LeftKick();
		void LeftIdle();
	
	private:
		eState mState;
		class Animator* mAnimator;
		float mTime;
		int mdir;
		class Vector2 Prevpos;
		class Vector2 Pos;
	};

}

