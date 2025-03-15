#include "jmTestScene.h"
#include "jmGameObject.h"

namespace jm
{
	TestScene::TestScene()
	{
	}
	TestScene::~TestScene()
	{
	}
	void TestScene::Initialize()
	{
		for (size_t i = 0; i < 100; i++)
		{
			GameObject* obj = new GameObject();
			obj->SetPosition(rand() % 1600, rand() % 900);
			AddGameObject(obj);
		}
	}
	void TestScene::Update()
	{
		Scene::Update();
	}
	void TestScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TestScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}