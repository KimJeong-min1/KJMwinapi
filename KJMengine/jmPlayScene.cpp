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
#include "jmMonsterScript.h"

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
		
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);
		
		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();
		
		graphcis::Texture* HelltakerTexture = Resources::Find<graphcis::Texture>(L"Player");
		PlayerAnimator = mPlayer->AddComponent<Animator>();
		PlayerAnimator->CreateAnimation(L"PlayerIdle", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 195.0f),
			Vector2::Zero, 12, 0.1f);
		PlayerAnimator->CreateAnimation(L"PlayerKick", HelltakerTexture, Vector2(0.0f,195.0f), Vector2(100.0f,195.0f),
			Vector2::Zero, 13, 0.1f);
		PlayerAnimator->CreateAnimation(L"PlayerLeftIdle", HelltakerTexture, Vector2(1300.0f, 0.0f), Vector2(100.0f, 195.0f),
			Vector2::Zero, 12, 0.1f);
		PlayerAnimator->CreateAnimation(L"PlayerLeftKick", HelltakerTexture, Vector2(1200.0f, 195.0f), Vector2(100.0f, 195.0f),
			Vector2::Zero, 13, 0.1f);

		PlayerAnimator->PlayAnimation(L"PlayerIdle", true);
		
		Transform* pltr = mPlayer->GetComponent<Transform>();
		pltr->SetPosition(Vector2(100.0f, 100.0f));
		
		mMonster = object::Instantiate<Monster>(enums::eLayerType::Monster);
		mMonster->AddComponent<MonsterScript>();

		graphcis::Texture* MonsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
		MonsterAnimator = mMonster->AddComponent<Animator>();
		MonsterAnimator->CreateAnimation(L"MonsterIdle", MonsterTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 12, 0.1f);
		MonsterAnimator->CreateAnimation(L"Monstergetkicked", MonsterTexture, Vector2(0.0f, 220.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 6, 0.1f);

		MonsterAnimator->PlayAnimation(L"MonsterIdle", true);

		Transform* motr = mMonster->GetComponent<Transform>();
		motr->SetPosition(Vector2(200.0f, 100.0f));
		
		Azazel = object::Instantiate<NPC>(enums::eLayerType::NPC);

		graphcis::Texture* NPCTexture = Resources::Find<graphcis::Texture>(L"Azazel");
		NPCAnimator = Azazel->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"AzazelIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);
		
		NPCAnimator->PlayAnimation(L"AzazelIdle", true);

		Cerberus = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Cerberus");
		NPCAnimator = Cerberus->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"CerberusIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"CerberusIdle", true);

		Judgement = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Judgement");
		NPCAnimator = Judgement->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"JudgementIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);
		NPCAnimator->CreateAnimation(L"Judgementappeared", NPCTexture, Vector2(0.0f, 100.0f), Vector2(100.0f, 260.0f),
			Vector2::Zero, 9, 0.1f);

		NPCAnimator->PlayAnimation(L"JudgementIdle", true);

		Justice = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Justice");
		NPCAnimator = Justice->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"JusticeIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"JusticeIdle", true);

		Lucifer = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Lucifer");
		NPCAnimator = Lucifer->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"LuciferIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"LuciferIdle", true);

		Malina = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Malina");
		NPCAnimator = Malina->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"MalinaIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"MalinaIdle", true);

		Modeus = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Modeus");
		NPCAnimator = Modeus->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"ModeusIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"ModeusIdle", true);

		Pandemonica = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Pandemonica");
		NPCAnimator = Pandemonica->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"PandemonicaIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"PandemonicaIdle", true);

		Zdrada = object::Instantiate<NPC>(enums::eLayerType::NPC);

		NPCTexture = Resources::Find<graphcis::Texture>(L"Zdrada");
		NPCAnimator = Zdrada->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"ZdradaIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"ZdradaIdle", true);

		Transform* npctr = Azazel->GetComponent<Transform>();
		npctr->SetPosition(Vector2(400.0f, 200.0f));
		npctr = Cerberus->GetComponent<Transform>();
		npctr->SetPosition(Vector2(500.0f, 200.0f));
		npctr = Judgement->GetComponent<Transform>();
		npctr->SetPosition(Vector2(600.0f, 300.0f));
		npctr = Justice->GetComponent<Transform>();
		npctr->SetPosition(Vector2(600.0f, 500.0f));
		npctr = Lucifer->GetComponent<Transform>();
		npctr->SetPosition(Vector2(700.0f, 300.0f));
		npctr = Malina->GetComponent<Transform>();
		npctr->SetPosition(Vector2(700.0f, 400.0f));
		npctr = Modeus->GetComponent<Transform>();
		npctr->SetPosition(Vector2(600.0f, 400.0f));
		npctr = Pandemonica->GetComponent<Transform>();
		npctr->SetPosition(Vector2(800.0f, 100.0f));
		npctr = Zdrada->GetComponent<Transform>();
		npctr->SetPosition(Vector2(800.0f, 200.0f));
		
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