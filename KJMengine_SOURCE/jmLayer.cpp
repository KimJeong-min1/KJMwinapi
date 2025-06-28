#include "jmLayer.h"

namespace jm
{
	Layer::Layer()
		:mGameObjects()
	{
	}
	Layer::~Layer()
	{
	}
	void Layer::Initialize()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			gameobj->Initialize();
		}
	}
	void Layer::Update()
	{
		// for���� ���Ͽ� GameObjectŬ������ gameobject���� ������Ʈ��Ų��.
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			gameobj->Update();
		}
	}
	void Layer::LateUpdate()
	{
		// LayerŬ������ LateUpdate�Լ��� ���Ͽ� GameObjectŬ������ LateUpdate�� Ȱ��ȭ��Ų��.
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			gameobj->LateUpdate();
		}
	}
	void Layer::Render(HDC hdc)
	{
		// LayerŬ������ LateUpdate�Լ��� ���Ͽ� GameObjectŬ������ LateUpdate�� Ȱ��ȭ��Ų��.
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			gameobj->Render(hdc);
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}
