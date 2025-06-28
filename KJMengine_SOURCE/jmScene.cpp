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
		// LayerŬ������ Layer���� ������Ʈ��Ų��
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		// SceneŬ������ LateUpdate�Լ��� ���ؼ� Layer Ŭ������ LateUpdate�� Ȱ��ȭ�Ѵ�.
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		// SceneŬ������ Render�Լ��� ���ؼ� Layer Ŭ������ Render�� Ȱ��ȭ�Ѵ�
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
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
	
	void Scene::OnExit()
	{

	}
	void Scene::OnEnter()
	{

	}
}
