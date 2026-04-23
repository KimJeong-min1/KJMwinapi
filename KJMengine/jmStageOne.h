#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class StageOne : public Scene
	{
	public:
		StageOne();
		~StageOne();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void StageSetup();
		void ProcessInput(int dx, int dy);
		

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

		class TileType* mTileType;

		Vector2 mMousePosition;

		std::vector<GameObject*> mObj;
		std::vector<std::vector<GameObject*>> mMapdata;

		int stamina = 40;
	};
}

