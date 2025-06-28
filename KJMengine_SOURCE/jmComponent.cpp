#include "jmComponent.h"

namespace jm
{
	Component::Component(enums::eComponentType type)
		:mType(type)
	{

	}

	Component::~Component()
	{

	}
	// 실질적으로 Component 클래스를 초기화 시키는건 아니지만 
	// enum클래스의 Componenttype을 통해 어떤 특정 클래스를 초기화시킴
	// 밑에있는 다른 함수들도 다 똑같은 의미
	void Component::Initialize()
	{

	}
	void Component::Update()
	{

	}
	void Component::LateUpdate()
	{

	}
	void Component::Render(HDC hdc)
	{

	}
}