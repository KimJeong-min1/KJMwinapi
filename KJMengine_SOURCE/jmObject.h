#pragma once
#include "jmComponent.h"
#include "jmGameObject.h"
#include "jmLayer.h"
#include "jmScene.h"
#include "jmSceneManager.h"
#include "jmTransform.h"

namespace jm::object
{
	template <typename T>
	static T* Instantiate(jm::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(jm::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		if (obj == nullptr)
			return;

		obj->Death();
	}

	static void DontDestroyOnLoad(GameObject* gameobj)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		activeScene->EraseGameObject(gameobj);

		Scene* dontDestroyOnload = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnload->AddGameObject(gameobj, gameobj->GetLayerType());
	}
}
