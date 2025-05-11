#include "jmPlayScene.h"
#include "jmGameObject.h"
#include "jmPlayer.h"
#include "jmTransform.h"
#include "jmSpriteRenderer.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmObject.h"
#include "jmTexture.h"
#include "jmResources.h"
#include "jmPlayerScript.h"
#include "jmCamera.h"
#include "jmRenderer.h"
#include "jmBackGround.h"
#include "jmAnimator.h"

namespace jm
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		
		mBG = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBG->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.0f, 1.0f));
		mBG->AddComponent<PlayerScript>();
		
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		
		graphcis::Texture* HelltakerTexture = Resources::Find<graphcis::Texture>(L"Player");
		mAnimator = mPlayer->AddComponent<Animator>();
		mAnimator->CreateAnimation(L"PlayerIdel", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 195.0f),
			Vector2::Zero, 12, 0.1f);
		mAnimator->CreateAnimation(L"PlayerKick", HelltakerTexture, Vector2(0.0f,195.0f), Vector2(100.0f,195.0f),
			Vector2::Zero, 13, 0.1f);

		mAnimator->PlayAnimation(L"PlayerIdel", true);

		Transform* tr = mPlayer->GetComponent<Transform>();
		tr->SetPosition(Vector2(100.0f, 100.0f));
		
		Scene::Initialize();
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::One))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			SceneManager::LoadScene(L"CutScene");
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			SceneManager::LoadScene(L"DeadScene");
		}
		if (Input::GetKeyDown(eKeyCode::H))
		{
			mAnimator->PlayAnimation(L"PlayerKick", true);
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{
	
	}
}