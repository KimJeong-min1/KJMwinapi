#include "jmMonster.h"
#include "jmTransform.h"
#include "jmTime.h"

namespace jm
{
	Monster::Monster()
	{
		SetGameObjectType(eGameObjectType::Monster);
	}
	void Monster::Initialize()
	{
		GameObject::Initialize();
	}
	void Monster::Update()
	{
		GameObject::Update();
	}
	void Monster::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Monster::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}