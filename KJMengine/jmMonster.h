#pragma once
#include "..\\KJMengine_SOURCE\\jmGameObject.h"

namespace jm
{
	class Monster : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

