#pragma once
#include "..\\KJMengine_SOURCE\\jmGameObject.h"
namespace jm
{
	class Wall : public GameObject
	{
	public:
		Wall();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

