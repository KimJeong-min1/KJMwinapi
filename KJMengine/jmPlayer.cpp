#include "jmPlayer.h"
#include "jmInput.h"
#include "jmTransform.h"
#include "jmTime.h"

namespace jm
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}
	void Player::Update()
	{
		// layer Ŭ������ ������Ʈ�� ���� Gameobjcet�� ������Ʈ�� ���Ͽ� playerŬ������ ������Ʈ�� �Ѵ�.
		GameObject::Update();
	}
	void Player::LateUpdate()
	{
		// layer Ŭ������ LateUpdate�� ���� Gameobjcet�� LateUpdate�� ���Ͽ� playerŬ������ LateUpdate�� �Ѵ�.
		GameObject::LateUpdate();
	}
	void Player::Render(HDC hdc)
	{
		// Layer Ŭ������ Render�� ���� GameObject�� Render�� ���Ͽ� PlayerŬ������ Render�� Ȱ��ȭ�Ѵ�
		GameObject::Render(hdc);
	}
}