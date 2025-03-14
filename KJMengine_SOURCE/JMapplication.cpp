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
		
		// ������ ������ ũ�Ⱑ �ƴ� ������ ���� ������ �������� ũ�⸦
		// �����ϱ� ���� �ҽ��ڵ�
		RECT rect = { 0,0,width,height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		//������ �ػ󵵿� �´� �����(��ȭ��) ����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		// BackHdc �� BackBitmap ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		// ������ ����Ʈ�� ���ִ��� �����ش�.
		DeleteObject(oldBitmap);

		// �÷��̾��� ��ġ�� ����
		mPlayer.SetPosition(0, 0);
		// InputŬ������ �ʱ�ȭ
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
		// InputŬ���� ������Ʈ
		Input::Update();
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
		mPlayer.Render(mBackHdc);

		// BackBuffer�� �ִ°� ���� Buffer�� ���� (�׷��ش�)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);
	}
}
