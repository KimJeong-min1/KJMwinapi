#include "jmGameObject.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmTransform.h"

namespace jm
{
	GameObject::GameObject()
		:mState(eState::Active)
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initializeTransform();
	}
	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}
	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->Initialize();
		}
	}
	void GameObject::Update()
	{
		// GameObject 클래스를 통하여 Component클래스의 Update를 활성화 시킨다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		// GameObject 클래스를 통하여 Component클래스의 LateUpdate를 활성화 시킨다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		// GameObject 클래스를 통하여 Component클래스의 Render를 활성화 시킨다.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->Render(hdc);
		}
	}

	// 지속적으로 위치를 초기화시켜준다? (잘모르겠음)
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}
