#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class ChapterOne : public Scene
	{
	public:
		ChapterOne();
		~ChapterOne();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class BackGround* BG;
		class Character* Pandemonica;
	};
}


