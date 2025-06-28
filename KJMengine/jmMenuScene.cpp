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
		// 활성화된 Scene의 부모클래스인 Scene클래스의 업데이트를 한다.
		Scene::Update();
	}
	void MenuScene::LateUpdate()
	{
		Scene::LateUpdate();

		// 만약 내가 특정키를 눌렀을때 내가 설정한 이름의 Scene을 불러오게한다.
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
		// 왼쪽 상단에 어떤 장면인지 적어준다.
		wchar_t str[50] = L"MenuScene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void MenuScene::OnEnter()
	{
		// 현재 활성화되어있는의 클래스에 들어와서 활성화한다.
	}
	void MenuScene::OnExit()
	{
	}
}
