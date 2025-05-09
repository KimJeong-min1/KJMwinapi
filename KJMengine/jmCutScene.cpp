#include "jmCutScene.h"
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
	CutScene::CutScene()
	{
	}
	CutScene::~CutScene()
	{
	}
	void CutScene::Initialize()
	{
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround);

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BGCutScene01");
		sr->SetTexture(bg);

		Scene::Initialize();
	}
	void CutScene::Update()
	{
		Scene::Update();
	}
	void CutScene::LateUpdate()
	{
		if (Input::GetKeyDown(eKeyCode::One))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Two))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			SceneManager::LoadScene(L"DeadScene");
		}

		Scene::LateUpdate();
	}
	void CutScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void CutScene::OnEnter()
	{
	}
	void CutScene::OnExit()
	{
	}
}
