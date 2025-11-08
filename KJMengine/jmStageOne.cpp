#include "jmStageOne.h"
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
#include "jmBoxCollider2D.h"
#include "jmCollisionManager.h"
#include "jmKey.h"
#include "jmTrap.h"
#include "jmKeyBox.h"
#include "jmFire.h"
#include "jmWall.h"

namespace jm
{
	StageOne::StageOne()
	{
	}
	StageOne::~StageOne()
	{
	}
	void StageOne::Initialize()
	{
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mBG = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBG->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.0f, 1.0f));

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		PlayerScript* plscript = mPlayer->AddComponent<PlayerScript>();
		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		collider->Setoffset(Vector2(0.0f, 30.0f));

		graphcis::Texture* HelltakerTexture = Resources::Find<graphcis::Texture>(L"PlayerRight");
		PlayerAnimator = mPlayer->AddComponent<Animator>();
		PlayerAnimator->CreateAnimationByFolder(L"RightIdle", L"..\\Resources\\HelltakerRightIdle", Vector2::Zero, 0.1f);
		PlayerAnimator->PlayAnimation(L"RightIdle", true);

		HelltakerTexture = Resources::Find<graphcis::Texture>(L"PlayerRightKick");
		PlayerAnimator->CreateAnimationByFolder(L"RightKick", L"..\\Resources\\HelltakerRightKick", Vector2::Zero, 0.1f);
		PlayerAnimator->PlayAnimation(L"RightKick", true);
		HelltakerTexture = Resources::Find<graphcis::Texture>(L"PlayerLeft");
		PlayerAnimator->CreateAnimation(L"LeftIdle", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 148.0f),
			Vector2::Zero, 12, 0.1f);
		HelltakerTexture = Resources::Find<graphcis::Texture>(L"PlayerLeftKick");
		PlayerAnimator->CreateAnimation(L"LeftKick", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 148.0f),
			Vector2::Zero, 13, 0.1f);
		HelltakerTexture = Resources::Find<graphcis::Texture>(L"PlayerDeath");
		PlayerAnimator->CreateAnimation(L"PlayerDead", HelltakerTexture, Vector2(0.0f, 0.0f), Vector2(720.0f, 1232.0f),
			Vector2::Half, 18, 0.1f);
		PlayerAnimator->PlayAnimation(L"RightIdle", true);

		PlayerAnimator->GetCompleteEvent(L"RightKick") = std::bind(&PlayerScript::AttackEffect, plscript);

		Transform* pltr = mPlayer->GetComponent<Transform>();
		pltr->SetPosition(Vector2(0.0f, 0.0f));

		mMonster = object::Instantiate<Monster>(enums::eLayerType::Monster);
		mMonster->AddComponent<MonsterScript>();
		BoxCollider2D* moncollider = mMonster->AddComponent<BoxCollider2D>();
		moncollider->Setoffset(Vector2(0.0f, 30.0f));

		graphcis::Texture* MonsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
		MonsterAnimator = mMonster->AddComponent<Animator>();
		MonsterAnimator->CreateAnimation(L"MonsterIdle", MonsterTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 12, 0.1f);
		MonsterAnimator->CreateAnimation(L"Monstergetkicked", MonsterTexture, Vector2(0.0f, 220.0f), Vector2(100.0f, 220.0f),
			Vector2::Zero, 6, 0.1f);

		MonsterAnimator->PlayAnimation(L"MonsterIdle", true);

		Transform* motr = mMonster->GetComponent<Transform>();
		motr->SetPosition(Vector2(200.0f, 100.0f));

		mFire = object::Instantiate<Fire>(enums::eLayerType::Object);
		graphcis::Texture* ObjectTexture = Resources::Find<graphcis::Texture>(L"Fire");
		FireAnimator = mFire->AddComponent<Animator>();
		FireAnimator->CreateAnimationByFolder(L"Fire", L"..\\Resources\\HelltakerFire", Vector2::Zero, 0.1f);
		FireAnimator->PlayAnimation(L"Fire", true);

		mFlamebase0 = object::Instantiate<Fire>(enums::eLayerType::Object);
		SpriteRenderer* Flamesr = mFlamebase0->AddComponent<SpriteRenderer>();
		Flamesr->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase0");
		Flamesr->SetTexture(ObjectTexture);

		Transform* Flametr = mFlamebase0->GetComponent<Transform>();
		Flametr->SetPosition(Vector2(765.0f, 130.0f));

		mFlamebase1 = object::Instantiate<Fire>(enums::eLayerType::Object);
		Flamesr = mFlamebase1->AddComponent<SpriteRenderer>();
		Flamesr->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase1");
		Flamesr->SetTexture(ObjectTexture);

		Flametr = mFlamebase1->GetComponent<Transform>();
		Flametr->SetPosition(Vector2(520.0f, 220.0f));

		mFlamebase2 = object::Instantiate<Fire>(enums::eLayerType::Object);
		Flamesr = mFlamebase2->AddComponent<SpriteRenderer>();
		Flamesr->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase0");
		Flamesr->SetTexture(ObjectTexture);

		Flametr = mFlamebase2->GetComponent<Transform>();
		Flametr->SetPosition(Vector2(430.0f, 465.0f));

		mFlamebase3 = object::Instantiate<Fire>(enums::eLayerType::Object);
		Flamesr = mFlamebase3->AddComponent<SpriteRenderer>();
		Flamesr->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase1");
		Flamesr->SetTexture(ObjectTexture);

		Flametr = mFlamebase3->GetComponent<Transform>();
		Flametr->SetPosition(Vector2(520.0f, 220.0f));

		Pandemonica = object::Instantiate<NPC>(enums::eLayerType::NPC);
		graphcis::Texture* NPCTexture = Resources::Find<graphcis::Texture>(L"Pandemonica");
		NPCAnimator = Pandemonica->AddComponent<Animator>();
		NPCAnimator->CreateAnimation(L"PandemonicaIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f);

		NPCAnimator->PlayAnimation(L"PandemonicaIdle", true);

		Transform* npctr = Pandemonica->GetComponent<Transform>();
		npctr->SetPosition(Vector2(1000.0f, 100.0f));

		Scene::Initialize();
	}
	void StageOne::Update()
	{
		Scene::Update();
	}
	void StageOne::LateUpdate()
	{
		Scene::LateUpdate();

		graphcis::Texture* ObjectTexture = nullptr;
		SpriteRenderer* Wallsr = nullptr;
		SpriteRenderer* Flamesr = nullptr;

		if (Input::GetKeyDown(eKeyCode::U))
		{
			SceneManager::LoadScene(L"MenuScene");
		}
		else if (Input::GetKeyDown(eKeyCode::I))
		{
			SceneManager::LoadScene(L"CutScene");
		}
		else if (Input::GetKeyDown(eKeyCode::O))
		{
			SceneManager::LoadScene(L"BadendScene");
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Load();
		}

		if (Input::GetKeyDown(eKeyCode::One))
		{
			mPickObjectType = eGameObjectType::Wall01;
		}
		else if (Input::GetKeyDown(eKeyCode::Two))
		{
			mPickObjectType = eGameObjectType::Wall03;
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			mPickObjectType = eGameObjectType::Wall04;
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			mPickObjectType = eGameObjectType::Wall08;
		}

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			if (mPickObjectType == eGameObjectType::Wall01)
			{
				mWall = object::Instantiate<Wall>(enums::eLayerType::Object);
				Wallsr = mWall->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall01");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(mWall);
			}
			else if (mPickObjectType == eGameObjectType::Wall03)
			{
				mWall = object::Instantiate<Wall>(enums::eLayerType::Object);
				Wallsr = mWall->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall03");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(mWall);
			}
			else if (mPickObjectType == eGameObjectType::Wall04)
			{
				mWall = object::Instantiate<Wall>(enums::eLayerType::Object);
				Wallsr = mWall->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall04");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(mWall);
			}
			else if (mPickObjectType == eGameObjectType::Wall08)
			{
				mWall = object::Instantiate<Wall>(enums::eLayerType::Object);
				Wallsr = mWall->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall08");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(mWall);
			}
			
			mMousePosition = Input::GetMousePosition();
			int mMousepositionX = 0;
			int mMousepositionY = 0;
			mMousepositionX = mMousePosition.x / 84;
			mMousepositionY = mMousePosition.y / 84;

			mMousePosition.x = mMousepositionX;
			mMousePosition.y = mMousepositionY;

			Transform* Walltr = mWall->GetComponent<Transform>();
			Walltr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84 + 30))));
		}

	}
	void StageOne::Render(HDC hdc)
	{
		Scene::Render(hdc);

		HPEN mPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		HPEN oldpen = (HPEN)SelectObject(hdc, mPen);

		const int cellsize = 84;


		const int width = 1600;
		const int height = 900;

		int startoffsetx = 30;
		int startoffsety = 30;

		for (int x = 0; x <= 1600; x += cellsize)
		{
			MoveToEx(hdc, x, 0, NULL);
			LineTo(hdc, x, height);
		}

		for (int y = startoffsety; y <= 900; y += cellsize)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, width, y);
		}

		DeleteObject(oldpen);
	}
	void StageOne::OnEnter()
	{

	}
	void StageOne::OnExit()
	{

	}
	void StageOne::Save()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (GameObject* gameobj : mObj)
		{
			SpriteRenderer* spr = gameobj->GetComponent<SpriteRenderer>();
			Transform* tr = gameobj->GetComponent<Transform>();

			Vector2 position = tr->GetPosition();

			int x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}
	void StageOne::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int posX = 0;
			int posY = 0;

			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Wall* wall = object::Instantiate<Wall>(eLayerType::Object);
			SpriteRenderer* spr = wall->AddComponent<SpriteRenderer>();
			spr->SetTexture(Resources::Find<graphcis::Texture>(L"wall01"));
			wall->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
			mObj.push_back(wall);
		}
	}
}