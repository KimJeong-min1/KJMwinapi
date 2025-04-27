#include "jmScene.h"

namespace jm
{
	Scene::Scene()
		:mLayers()
	{

	}
	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{

	}
	void Scene::Update()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Update();
		}
	}
	void Scene::LateUpdate()
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->LateUpdate();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : mLayers)
		{
			if (layer == nullptr)
				continue;
			layer->Render(hdc);
		}
	}
	void Scene::OnExit()
	{

	}
	void Scene::OnEnter()
	{

	}
}
