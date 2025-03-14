#include "jmApplication.h"
#include "jmInput.h"

namespace jm
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		
		// 기존의 윈도우 크기가 아닌 위쪽의 툴을 제외한 윈도우의 크기를
		// 설정하기 위한 소스코드
		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// BackHdc 와 BackBitmap 연결
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		// 기존의 디폴트로 들어가있던걸 지워준다.
		DeleteObject(oldBitmap);

		// 플레이어의 위치를 해줌
		mPlayer.SetPosition(0, 0);
		// Input클래스를 초기화
		Input::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		// Input클래스 업데이트
		Input::Update();
		// Player 업데이트
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		// 뒤에 핸들에 사각형을 그려주는 함수
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		
		// 플레이어를 그려주는 함수
		mPlayer.Render(mBackHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사 (그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
