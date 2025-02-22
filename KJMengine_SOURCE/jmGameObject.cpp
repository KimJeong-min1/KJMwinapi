#include "jmGameObject.h"

namespace jm
{
	GameObject::GameObject()
		:mX(0.0f)
		,mY(0.0f)
	{
	}
	GameObject::~GameObject()
	{
	}
	void GameObject::Update()
	{

		// 오른쪽 -> x가 플러스
		// 왼쪽 -> x가 마이너스
		// 위 -> y가 마이너스
		// 아래 -> y가 플러스

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		// 파란색 브러쉬 생성
		HBRUSH bluebrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파란색 브러쉬에 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, bluebrush);

		HPEN redpen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldpen = (HPEN)SelectObject(hdc, redpen);
		SelectObject(hdc, oldpen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldbrush);
		DeleteObject(bluebrush);
		DeleteObject(redpen);
	}
}
