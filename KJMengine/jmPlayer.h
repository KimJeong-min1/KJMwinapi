#pragma once
#include "..\\KJMengine_SOURCE\\jmGameObject.h"

namespace jm
{
	class Player : public GameObject
	{
	public:
		Player();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}
