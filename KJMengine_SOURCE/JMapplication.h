#pragma once
#include "CommonInclude.h"
#include "jmGameObject.h"

namespace JM
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		jm::GameObject mPlayer;
	};
}

