#include "jmDeadScene.h"
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
	DeadScene::DeadScene()
	{
	}
	DeadScene::~DeadScene()
	{
	}
	void DeadScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BGDeadScene01");
		sr->SetTexture(bg);

		Scene::Initialize();
	}
	void DeadScene::Update()
	{
		Scene::Update();
	}
	void DeadScene::LateUpdate()
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
		else if (Input::GetKeyDown(eKeyCode::One))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
	}
	void DeadScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void DeadScene::OnEnter()
	{
	}
	void DeadScene::OnExit()
	{
	}
}
