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
		class Player* mPlayer;
		
		class Monster* Monster01;
		class Monster* Monster02;
		class Monster* Monster03;
		
		class NPC* Pandemonica;
		
		class Wall* Wall01;
		class Wall* Wall03;
		class Wall* Wall04;
		class Wall* Wall08;

		class ClearWall* mClearWall;
		
		class Animator* PlayerAnimator;
		class Animator* MonsterAnimator;
		class Animator* NPCAnimator;
		class Animator* FireAnimator;

		PickGameObjectType mPickObjectType;

		Vector2 mMousePosition;

		std::vector<GameObject*> mObj;
		std::vector<std::vector<GameObject*>> mMapdata;
	};
}

