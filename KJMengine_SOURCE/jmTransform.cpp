#include "jmTransform.h"

namespace jm
{
	Transform::Transform()
		:Component(enums::eComponentType::Transform)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
		// Component 클래스의 업데이트로 인하여 Transform클래스의 업데이트를 진행한다.
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}
