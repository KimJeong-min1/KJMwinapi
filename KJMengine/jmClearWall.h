#pragma once
#include "..\\KJMengine_SOURCE\\jmGameObject.h"
namespace jm
{
	class ClearWall : public GameObject
	{
	public:
		ClearWall();
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}

