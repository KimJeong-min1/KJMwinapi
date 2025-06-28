#include "jmTime.h"
namespace jm
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltaTimeValue = 0.0f;

	void Time::Initailize()
	{
		// Cpu 고유 진동수를 대입
		QueryPerformanceFrequency(&CpuFrequency);

		// 프로그램이 시작 했을 때 현재 진동수를 대입
		QueryPerformanceCounter(&PrevFrequency);
	}

	void Time::Update()
	{
		// 현재의 진동수를 대입한다.
		QueryPerformanceCounter(&CurrentFrequency);

		// 현재의 고유 진동수와 전의 고유진동수를 통하여 현재와 과거의 진동수의 차이를 구한다.
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);
		// 진동수의 차이 값을 cpu 고유 진동수로 나누어서 Deltatimevalue 값을 구한다.
		DeltaTimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		// 그리고 과거의 고유 진동수에 현재의 고유진동수를 대입한다.
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		// 초당 프레임율 계산
		static float time = 0.0f;
		time += DeltaTimeValue;
		float fps = 1.0f / DeltaTimeValue;

		// 윈도우창안에 초당프레임표시율을 왼쪽상단위에 표기
		wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);
	}
}
