#include "jmGameObject.h"
#include "jmInput.h"
#include "jmTime.h"

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
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
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
