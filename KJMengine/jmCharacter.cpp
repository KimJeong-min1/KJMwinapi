#include "jmCharacter.h"
#include "jmGameObject.h"
namespace jm
{
	void Character::Initialize()
	{
		GameObject::Initialize();
	}
	void Character::Update()
	{
		GameObject::Update();
	}
	void Character::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Character::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
