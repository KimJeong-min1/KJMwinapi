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
#include "jmMonster.h"
#include "jmNPC.h"

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
		mBG->AddComponent<PlayerScript>(); // PlayerScript 대신에 BackGround를 넣어야하는게 아닌가 안되는이유
		
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		
		graphcis::Texture* HelltakerTexture = Resources::Find<graphcis::Texture>(L"Player");
		PlayerAnimator = mPlayer->AddComponent<Animator>();
		PlayerAnimator->CreateAnimation(L"PlayerIdel", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 195.0f),
			Vector2::Zero, 12, 0.1f);
		PlayerAnimator->CreateAnimation(L"PlayerKick", HelltakerTexture, Vector2(0.0f,195.0f), Vector2(100.0f,195.0f),
			Vector2::Zero, 13, 0.1f);

		PlayerAnimator->PlayAnimation(L"PlayerIdel", true);
		
		Transform* pltr = mPlayer->GetComponent<Transform>();
		pltr->SetPosition(Vector2(100.0f, 100.0f));
		
		mMonster = object::Instantiate<Monster>(enums::eLayerType::Monster);
		mMonster->AddComponent<PlayerScript>();

		graphcis::Texture* MonsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
		MonsterAnimator = mMonster->AddComponent<Animator>();
		MonsterAnimator->CreateAnimation(L"MonsterIdel", MonsterTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 12, 0.1f);
		MonsterAnimator->CreateAnimation(L"Monstergetkicked", MonsterTexture, Vector2(0.0f, 220.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 6, 0.1f);

		MonsterAnimator->PlayAnimation(L"MonsterIdel", true);

		Transform* motr = mMonster->GetComponent<Transform>();
		motr->SetPosition(Vector2(200.0f, 100.0f));
		
		Azazel = object::Instantiate<NPC>(enums::eLayerType::NPC);
		Azazel->AddComponent<PlayerScript>();

		graphcis::Texture* NPCTexture = Resources::Find<graphcis::Texture>(L"Azazel");
		NPCAnimator = Azazel->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"AzazelIdel", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);
		
		NPCAnimator->PlayAnimation(L"AzazelIdel", true);

		Cerberus = object::Instantiate<NPC>(enums::eLayerType::NPC);
		Cerberus->AddComponent<PlayerScript>();

		NPCTexture = Resources::Find<graphcis::Texture>(L"Cerberus");
		NPCAnimator = Cerberus->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"CerberusIdel", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"CerberusIdel", true);

		Transform* npctr = Azazel->GetComponent<Transform>();
		npctr->SetPosition(Vector2(400.0f, 200.0f));
		npctr = Cerberus->GetComponent<Transform>();
		npctr->SetPosition(Vector2(500.0f, 200.0f));
		
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
			PlayerAnimator->PlayAnimation(L"PlayerKick", true);
			MonsterAnimator->PlayAnimation(L"Monstergetkicked", true);
		}
		if (Input::GetKeyDown(eKeyCode::O))
		{
			PlayerAnimator->PlayAnimation(L"PlayerIdel", true);
			MonsterAnimator->PlayAnimation(L"MonsterIdel", true);
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