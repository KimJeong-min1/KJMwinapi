#pragma once
#include "..\\KJMengine_SOURCE\\jmScene.h"

namespace jm
{
	class CutScene : public Scene
	{
	public:
		CutScene();
		~CutScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	
	private:
	};
}

