#include "jmBadendScene.h"
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
	BadendScene::BadendScene()
	{
	}
	BadendScene::~BadendScene()
	{
	}
	void BadendScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BGDeadScene01");
		sr->SetTexture(bg);

		Scene::Initialize();
	}
	void BadendScene::Update()
	{
		Scene::Update();
	}
	void BadendScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::Two))
		{
			SceneManager::LoadScene(L"StageOne");
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			SceneManager::LoadScene(L"CutScene");
		}
		else if (Input::GetKeyDown(eKeyCode::One))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Five))
		{
			SceneManager::LoadScene(L"StageTwo");
		}
	}
	void BadendScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void BadendScene::OnEnter()
	{
	}
	void BadendScene::OnExit()
	{
	}
}
