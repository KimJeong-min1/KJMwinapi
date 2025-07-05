#include "jmLayer.h"

namespace jm
{
	Layer::Layer()
		:mGameObjects()
	{
	}
	Layer::~Layer()
	{
		for (GameObject* gameobj : mGameObjects)
		{
			if (gameobj == nullptr)
				continue;

			delete gameobj;
			gameobj = nullptr;
		}
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
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused ||
				state == GameObject::eState::Dead)
			{
				continue;
			}

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
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused ||
				state == GameObject::eState::Dead)
			{
				continue;
			}

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
			GameObject::eState state = gameobj->GetActive();
			if (state == GameObject::eState::Paused ||
				state == GameObject::eState::Dead)
			{
				continue;
			}
			
			gameobj->Render(hdc);
		}
	}
	void Layer::Destroy()
	{
		for (GameObjectIter iter = mGameObjects.begin();
			iter != mGameObjects.end();)
		{
			GameObject::eState active = (*iter)->GetActive();
			if (active == GameObject::eState::Dead)
			{
				GameObject* deathobj = (*iter);
				iter = mGameObjects.erase(iter);

				delete deathobj;
				deathobj = nullptr;

				continue;
			}

			iter++;
		}
	}
	void Layer::AddGameObject(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		mGameObjects.push_back(gameObject);
	}
}
