#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class DeadScene : public Scene
	{
	public:
		DeadScene();
		~DeadScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;
	};
}


