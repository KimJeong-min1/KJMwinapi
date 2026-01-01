#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class StageOne : public Scene
	{
	public:
		enum class PickGameObjectType
		{
			Player,
			Monster,
			Wall01,
			Wall03,
			Wall04,
			Wall08,
			End,
		};
		
		StageOne();
		~StageOne();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

		void Save();
		void Load();
	private:
		class BackGround* mBG;
		
		class Player* mPlayer;
		
		class Monster* mMonster;
		
		class NPC* Pandemonica;
		
		class Wall* Wall01;
		class Wall* Wall03;
		class Wall* Wall04;
		class Wall* Wall08;

		class Fire* mFire01;
		class Fire* mFire02;
		class Fire* mFlamebase0;
		class Fire* mFlamebase1;
		class Fire* mFlamebase2;
		class Fire* mFlamebase3;
		
		class Animator* PlayerAnimator;
		class Animator* MonsterAnimator;
		class Animator* NPCAnimator;
		class Animator* FireAnimator;

		PickGameObjectType mPickObjectType;

		Vector2 mMousePosition;

		std::vector<GameObject*> mObj;
	};
}

