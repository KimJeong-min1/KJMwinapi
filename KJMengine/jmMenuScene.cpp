#include "jmMenuScene.h"
#include "jmGameObject.h"
#include "jmPlayer.h"
#include "jmTransform.h"
#include "jmSpriteRenderer.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmObject.h"
#include "jmTexture.h"
#include "jmResources.h"

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
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BGMenu");
		sr->SetTexture(bg);

		Scene::Initialize();
	}
	void MenuScene::Update()
	{
		Scene::Update();
	}
	void MenuScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::Two))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			SceneManager::LoadScene(L"CutScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			SceneManager::LoadScene(L"BadendScene");
		}
	}
	void MenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"MenuScene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void MenuScene::OnEnter()
	{
	}
	void MenuScene::OnExit()
	{
	}
}
