#pragma once
#include "jmCollider.h"

namespace jm
{
	class CircleCollider : public Collider
	{
	public:
		CircleCollider();
		~CircleCollider();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
	
	private:
		float mRadius;
	};
}

