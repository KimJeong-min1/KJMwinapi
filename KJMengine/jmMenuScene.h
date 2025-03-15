#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class MenuScene : public Scene
	{
	public:
		MenuScene();
		~MenuScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

