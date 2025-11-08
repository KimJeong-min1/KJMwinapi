#include "jmCircleCollider.h"
#include "jmTransform.h"
#include "jmGameObject.h"
#include "jmRenderer.h"
#include "jmCamera.h"

namespace jm
{
	CircleCollider::CircleCollider()
		:Collider(enums::eColliderType::Circle2D)
	{
	}
	CircleCollider::~CircleCollider()
	{
	}
	void CircleCollider::Initialize()
	{

	}
	void CircleCollider::Update()
	{

	}
	void CircleCollider::LateUpdate()
	{

	}
	void CircleCollider::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);

		Vector2 offset = Getoffset();

		HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldbrush = (HBRUSH)SelectObject(hdc, transparentBrush);

		HPEN greenpen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldpen = (HPEN)SelectObject(hdc, greenpen);

		Vector2 rightbottom;
		rightbottom.x = pos.x + offset.x + 100 * GetSize().x;
		rightbottom.y = pos.y + offset.y + 100 * GetSize().y;

		Ellipse(hdc, pos.x + offset.x,
			pos.y + offset.y,
			rightbottom.x,
			rightbottom.y);

		SelectObject(hdc, oldbrush);
		SelectObject(hdc, oldpen);
		DeleteObject(greenpen);
	}
}
