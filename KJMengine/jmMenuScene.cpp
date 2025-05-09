#include "jmMenuScene.h"
#include "jmInput.h"
#include "jmPlayScene.h"
#include "jmSceneManager.h"

namespace jm
{
	MenuScene::MenuScene()
	{
	}
	MenuScene::~MenuScene()
	{
	}
	void MenuScene::Initialize()
	{
		Scene::Initialize();
	}
	void MenuScene::Update()
	{
		Scene::Update();
	}
	void MenuScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void MenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"MenuScene";
		TextOut(hdc, 0, 0, str, 11);
	}
}
