#include "jmApplication.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmSceneManager.h"
#include "jmResources.h"

namespace jm
{
	Application::Application()
		:mHwnd(nullptr)
		, mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		// 윈도우창만들기
		adjustWindowRect(hwnd,width,height);
		// 백버퍼만들기
		createBuffer(width, height);
		// 그 이외의 초기화할 것들
		initializeEtc();

		// 플레이어의 위치를 해줌
		SceneManager::Initialize();
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
		Destroy();
	}
	void Application::Update()
	{
		// Input클래스 업데이트
		Input::Update();
		// Time클래스 업데이트
		Time::Update();
		// Player 업데이트
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		// Player Late업데이트
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		// 뒤에 핸들에 사각형을 그려주는 함수
		clearRenderTarget();
		
		// 주사율을 표기해주는 함수
		Time::Render(mBackHdc);
		// 플레이어를 그려주는 함수
		SceneManager::Render(mBackHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사 (그려준다)
		copyRenderTarget(mBackHdc, mHdc);
	}
	void Application::Destroy()
	{
		SceneManager::Destroy();
	}
	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}
	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		// 비트맵파일로 이미지를 화면에 출력해주는 함수
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) //윈도우창생성
	{
		// 윈도우창 핸들
		mHwnd = hwnd;
		// 윈도우창 그리기위한 핸들
		mHdc = GetDC(hwnd);

		// 사각형의 크기 정보를 담을 변수를 만들어서 대입
		RECT rect = { 0,0,width,height };
		// 윈도우창을 생성
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// 가로값
		mWidth = rect.right - rect.left;
		// 세로값
		mHeight = rect.bottom - rect.top;

		// 내가 정한크기로 윈도우를 세팅
		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		// 윈도우를 화면상에 보여주게함
		ShowWindow(hwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height) //버퍼생성
	{
		// 윈도우 해상도에 맞는 백버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		// 백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);
		// BackHdc 와 BackBitmap 연결
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		// 기존의 디폴트로 들어가있던걸 지워준다.
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{
		// Input클래스안에 초기화함수에 들어감
		Input::Initialize();
		// Time클래스안에 초기화함수에 들어감
		Time::Initailize();
	}
}
