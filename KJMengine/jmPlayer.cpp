#include "jmPlayer.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"

namespace jm
{
	Player::Player()
	{
		SetGameObjectType(eGameObjectType::Player);
	}
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		// layer 클래스의 업데이트로 인해 Gameobjcet의 업데이트를 통하여 player클래스의 업데이트를 한다.
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		// layer 클래스의 LateUpdate로 인해 Gameobjcet의 LateUpdate를 통하여 player클래스의 LateUpdate를 한다.
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc)
	{
		// Layer 클래스의 Render로 인해 GameObject의 Render를 통하여 Player클래스의 Render를 활성화한다
		GameObject::Render(hdc);
	}
}