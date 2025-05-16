#include "jmBackGround.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"
#include "jmGameObject.h"

namespace jm
{
	void BackGround::Initialize()
	{
		GameObject::Initialize();
	}
	void BackGround::Update()
	{
		GameObject::Update();
	}
	void BackGround::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}