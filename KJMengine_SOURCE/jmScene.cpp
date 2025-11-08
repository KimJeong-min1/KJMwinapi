#include "jmScene.h"

namespace jm
{
	Scene::Scene()
		:mLayers()
	{
		createLayers();
	}
	Scene::~Scene()
	{
		for (Layer* layer : mLayers)
		{
			delete layer;
			layer = nullptr;
		}
	}

	void Scene::Initialize()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Initialize();
		}
	}
	void Scene::Update()
	{
		// Layer클래스의 Layer들을 업데이트시킨다
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		// Scene클래스의 LateUpdate함수를 통해서 Layer 클래스를 LateUpdate를 활성화한다.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		// Scene클래스의 Render함수를 통해서 Layer 클래스의 Render를 활성화한다
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}
	void Scene::Destroy()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;

			layer->Destroy();
		}
	}
	void Scene::AddGameObject(GameObject* gameobj, const enums::eLayerType type)
	{
		mLayers[(UINT)type]->AddGameObject(gameobj);
	}
	void Scene::createLayers()
	{
		mLayers.resize((UINT)enums::eLayerType::Max);
		for (size_t i = 0; i < (UINT)enums::eLayerType::Max; i++)
		{
			mLayers[i] = new Layer();
		}
	}
	
	void Scene::EraseGameObject(GameObject* gameobj)
	{
		eLayerType layerType = gameobj->GetLayerType();
		mLayers[(UINT)layerType]->EraseGameObject(gameobj);
	}

	void Scene::OnExit()
	{

	}
	void Scene::OnEnter()
	{

	}
}
