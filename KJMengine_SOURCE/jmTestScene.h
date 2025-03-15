#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class TestScene : public Scene
	{
	public:
		TestScene();
		~TestScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}