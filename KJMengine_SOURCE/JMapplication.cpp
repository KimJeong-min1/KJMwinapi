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
		// ������â�����
		adjustWindowRect(hwnd,width,height);
		// ����۸����
		createBuffer(width, height);
		// �� �̿��� �ʱ�ȭ�� �͵�
		initializeEtc();

		// �÷��̾��� ��ġ�� ����
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
		// InputŬ���� ������Ʈ
		Input::Update();
		// TimeŬ���� ������Ʈ
		Time::Update();
		// Player ������Ʈ
		SceneManager::Update();
	}

	void Application::LateUpdate()
	{
		// Player Late������Ʈ
		SceneManager::LateUpdate();
	}
	void Application::Render()
	{
		// �ڿ� �ڵ鿡 �簢���� �׷��ִ� �Լ�
		clearRenderTarget();
		
		// �ֻ����� ǥ�����ִ� �Լ�
		Time::Render(mBackHdc);
		// �÷��̾ �׷��ִ� �Լ�
		SceneManager::Render(mBackHdc);

		// BackBuffer�� �ִ°� ���� Buffer�� ���� (�׷��ش�)
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
		// ��Ʈ�����Ϸ� �̹����� ȭ�鿡 ������ִ� �Լ�
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height) //������â����
	{
		// ������â �ڵ�
		mHwnd = hwnd;
		// ������â �׸������� �ڵ�
		mHdc = GetDC(hwnd);

		// �簢���� ũ�� ������ ���� ������ ���� ����
		RECT rect = { 0,0,width,height };
		// ������â�� ����
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// ���ΰ�
		mWidth = rect.right - rect.left;
		// ���ΰ�
		mHeight = rect.bottom - rect.top;

		// ���� ����ũ��� �����츦 ����
		SetWindowPos(hwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		// �����츦 ȭ��� �����ְ���
		ShowWindow(hwnd, true);
	}
	void Application::createBuffer(UINT width, UINT height) //���ۻ���
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
		// InputŬ�����ȿ� �ʱ�ȭ�Լ��� ��
		Input::Initialize();
		// TimeŬ�����ȿ� �ʱ�ȭ�Լ��� ��
		Time::Initailize();
	}
}
