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

		void SetMapData(std::vector<std::vector<GameObject*>>& mapdata);
		void OnKicked();
	private:
		void Idle();
		void Getkick();

	private:
		eState mState;
		class Animator* mAnimator;
		float mTime;
		class Vector2 Prevpos;
		class Vector2 Pos;
		std::vector<std::vector<GameObject*>>* mMapdata = nullptr;
	};
}

