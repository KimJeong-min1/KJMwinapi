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
		// for문을 통하여 GameObject클래스의 gameobject들을 업데이트시킨다.
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
		// Layer클래스의 LateUpdate함수를 통하여 GameObject클래스의 LateUpdate를 활성화시킨다.
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
		// Layer클래스의 LateUpdate함수를 통하여 GameObject클래스의 LateUpdate를 활성화시킨다.
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
