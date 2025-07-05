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
		// GameObject Ŭ������ ���Ͽ� ComponentŬ������ Update�� Ȱ��ȭ ��Ų��.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->Update();
		}
	}
	void GameObject::LateUpdate()
	{
		// GameObject Ŭ������ ���Ͽ� ComponentŬ������ LateUpdate�� Ȱ��ȭ ��Ų��.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		// GameObject Ŭ������ ���Ͽ� ComponentŬ������ Render�� Ȱ��ȭ ��Ų��.
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;
			
			comp->Render(hdc);
		}
	}

	// ���������� ��ġ�� �ʱ�ȭ�����ش�? (�߸𸣰���)
	void GameObject::initializeTransform()
	{
		AddComponent<Transform>();
	}
}
