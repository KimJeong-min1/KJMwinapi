#include "jmApplication.h"
#include "jmInput.h"
#include "jmTime.h"

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
		// ������â�����
		adjustWindowRect(hwnd,width,height);
		// ����۸����
		createBuffer(width, height);
		// �� �̿��� �ʱ�ȭ�� �͵�
		initializeEtc();

		// �÷��̾��� ��ġ�� ����
		mPlayer.SetPosition(0, 0);
	}
	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	void Application::Update()
	{
		// InputŬ���� ������Ʈ
		Input::Update();
		// TimeŬ���� ������Ʈ
		Time::Update();
		// Player ������Ʈ
		mPlayer.Update();
	}

	void Application::LateUpdate()
	{

	}
	void Application::Render()
	{
		// �ڿ� �ڵ鿡 �簢���� �׷��ִ� �Լ�
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		
		// �÷��̾ �׷��ִ� �Լ�
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// BackBuffer�� �ִ°� ���� Buffer�� ���� (�׷��ش�)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(hwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);
		// ����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);
		// BackHdc �� BackBitmap ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		// ������ ����Ʈ�� ���ִ��� �����ش�.
		DeleteObject(oldBitmap);
	}
	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initailize();
	}
}
