#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class ChapterSeven : public Scene
	{
	public:
		ChapterSeven();
		~ChapterSeven();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class BackGround* BG;
		class Character* Justice;
	};
}


