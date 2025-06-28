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
		// Layer클래스의 for문으로 인해 GameObject가 활성화 됨으로써 Background 클래스를 업데이트를
		// GameObject클래스의 Update로 인해 활성화를 시킨다.
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