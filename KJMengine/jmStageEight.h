#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class StageEight : public Scene
	{
	public:
		StageEight();
		~StageEight();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class BackGround* mBG;

		class Player* mPlayer;

		class Monster* mMonster;

		class NPC* Azazel;
		class NPC* Cerberus;
		class NPC* Judgement;
		class NPC* Justice;
		class NPC* Lucifer;
		class NPC* Malina;
		class NPC* Modeus;
		class NPC* Pandemonica;
		class NPC* Zdrada;

		class Key* mKey;

		class Animator* PlayerAnimator;
		class Animator* MonsterAnimator;
		class Animator* NPCAnimator;
		class Animator* KeyAnimator;
	};
}

