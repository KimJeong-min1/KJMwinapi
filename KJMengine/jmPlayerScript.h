#pragma once
#include "..\\KJMengine_SOURCE\\\jmScript.h"

namespace jm
{
	class PlayerScript : public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:
	};
}

