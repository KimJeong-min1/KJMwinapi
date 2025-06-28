#include "jmTime.h"
namespace jm
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initailize()
	{
		// Cpu ���� �������� ����
		QueryPerformanceFrequency(&CpuFrequency);

		// ���α׷��� ���� ���� �� ���� �������� ����
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		// ������ �������� �����Ѵ�.
		QueryPerformanceCounter(&CurrentFrequency);

		// ������ ���� �������� ���� ������������ ���Ͽ� ����� ������ �������� ���̸� ���Ѵ�.
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		// �������� ���� ���� cpu ���� �������� ����� Deltatimevalue ���� ���Ѵ�.
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		// �׸��� ������ ���� �������� ������ ������������ �����Ѵ�.
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		// �ʴ� �������� ���
		static float time = 0.0f;
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		// ������â�ȿ� �ʴ�������ǥ������ ���ʻ������ ǥ��
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
