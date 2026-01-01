#include "jmWall.h"
#include "jmTransform.h"
#include "jmTime.h"

namespace jm
{
	Wall::Wall()
	{
		
	}
	void Wall::Initialize()
	{
		GameObject::Initialize();
	}
	void Wall::Update()
	{
		GameObject::Update();
	}
	void Wall::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Wall::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}