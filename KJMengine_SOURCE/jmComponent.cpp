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
	// ���������� Component Ŭ������ �ʱ�ȭ ��Ű�°� �ƴ����� 
	// enumŬ������ Componenttype�� ���� � Ư�� Ŭ������ �ʱ�ȭ��Ŵ
	// �ؿ��ִ� �ٸ� �Լ��鵵 �� �Ȱ��� �ǹ�
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