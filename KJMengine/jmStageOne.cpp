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
#include "jmClearWall.h"

namespace jm
{
	StageOne::mMapdata;

	StageOne::StageOne()
	{
		mMapdata.resize(8, std::vector<GameObject*>(9, nullptr));
	}
	StageOne::~StageOne()
	{
	}
	void StageOne::Initialize()
	{
		char mapsetting[8][10] =
		{
			"#########",
			"#####  ##",
			"##     ##",
			"##    ###",
			"#  ######",
			"#      ##",
			"#########",
		};

		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (mapsetting[y][x] == '#')
				{
					mMapdata[y][x] = mClearWall = 
					object::Instantiate<ClearWall>(enums::eLayerType::Object, Vector2(0, 0));
				}
			}
		}

		mMapdata[1][6] = mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mBG = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBG->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.0f, 1.0f));

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);

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
		pltr->SetPosition(Vector2(924.0f, 168.0f));
		
		mFire01 = object::Instantiate<Fire>(enums::eLayerType::Fire);
		graphcis::Texture* ObjectTexture = Resources::Find<graphcis::Texture>(L"Fire");
		FireAnimator = mFire01->AddComponent<Animator>();
		FireAnimator->CreateAnimationByFolder(L"Fire", L"..\\Resources\\HelltakerFire", Vector2::Zero, 0.1f, Vector2(0.5f, 0.5f));
		FireAnimator->PlayAnimation(L"Fire", true);

		Transform* Firetr = mFire01->GetComponent<Transform>();
		Firetr->SetPosition(Vector2(530.0f, 200.0f));

		mFire02 = object::Instantiate<Fire>(enums::eLayerType::Fire);
		ObjectTexture = Resources::Find<graphcis::Texture>(L"Fire");
		FireAnimator = mFire02->AddComponent<Animator>();
		FireAnimator->CreateAnimationByFolder(L"Fire", L"..\\Resources\\HelltakerFire", Vector2::Zero, 0.1f,Vector2(0.5f, 0.5f));
		FireAnimator->PlayAnimation(L"Fire", true);

		Firetr = mFire02->GetComponent<Transform>();
		Firetr->SetPosition(Vector2(1030.0f, 410.0f));

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
		Flametr->SetPosition(Vector2(1020.0f, 430.0f));

		Pandemonica = object::Instantiate<NPC>(enums::eLayerType::NPC);
		graphcis::Texture* NPCTexture = Resources::Find<graphcis::Texture>(L"Pandemonica");
		NPCAnimator = Pandemonica->AddComponent<Animator>();
		collider = Pandemonica->AddComponent<BoxCollider2D>();
		collider->Setoffset(Vector2(0.0f, 0.0f));
		NPCAnimator->CreateAnimation(L"PandemonicaIdle", NPCTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
			Vector2::Zero, 12, 0.1f, Vector2(1.0f,1.0f));

		NPCAnimator->PlayAnimation(L"PandemonicaIdle", true);

		Transform* npctr = Pandemonica->GetComponent<Transform>();
		npctr->SetPosition(Vector2(1000.0f, 600.0f));

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
			mPickObjectType = PickGameObjectType::Wall01;
		}
		else if (Input::GetKeyDown(eKeyCode::Two))
		{
			mPickObjectType = PickGameObjectType::Wall03;
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			mPickObjectType = PickGameObjectType::Wall04;
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			mPickObjectType = PickGameObjectType::Wall08;
		}
		else if (Input::GetKeyDown(eKeyCode::Five))
		{
			mPickObjectType = PickGameObjectType::Monster;
		}
		
		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			if (mPickObjectType == PickGameObjectType::Wall01)
			{
				Wall01 = object::Instantiate<Wall>(enums::eLayerType::Object);
				eGameObjectType Wall01Type = enums::eGameObjectType::Wall01;
				Wall01->SetGameObjectType(Wall01Type);
				Wallsr = Wall01->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall01");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(Wall01);
			}
			else if (mPickObjectType == PickGameObjectType::Wall03)
			{
				Wall03 = object::Instantiate<Wall>(enums::eLayerType::Object);
				eGameObjectType Wall03Type = enums::eGameObjectType::Wall03;
				Wall03->SetGameObjectType(Wall03Type);
				Wallsr = Wall03->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall03");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(Wall03);
			}
			else if (mPickObjectType == PickGameObjectType::Wall04)
			{
				Wall04 = object::Instantiate<Wall>(enums::eLayerType::Object);
				eGameObjectType Wall04Type = enums::eGameObjectType::Wall04;
				Wall04->SetGameObjectType(Wall04Type);
				Wallsr = Wall04->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall04");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(Wall04);
			}
			else if (mPickObjectType == PickGameObjectType::Wall08)
			{
				Wall08 = object::Instantiate<Wall>(enums::eLayerType::Object);
				eGameObjectType Wall08Type = enums::eGameObjectType::Wall08;
				Wall08->SetGameObjectType(Wall08Type);
				Wallsr = Wall08->AddComponent<SpriteRenderer>();
				Wallsr->SetSize(Vector2(1.0f, 1.0f));
				ObjectTexture = Resources::Find<graphcis::Texture>(L"wall08");
				Wallsr->SetTexture(ObjectTexture);
				mObj.push_back(Wall08);
			}
			else if (mPickObjectType == PickGameObjectType::Monster)
			{
				mMonster = object::Instantiate<Monster>(enums::eLayerType::Monster);
				mMonster->AddComponent<MonsterScript>();
				BoxCollider2D* moncollider = mMonster->AddComponent<BoxCollider2D>();
				moncollider->Setoffset(Vector2(0.0f, 30.0f));

				ObjectTexture = Resources::Find<graphcis::Texture>(L"Monster");
				MonsterAnimator = mMonster->AddComponent<Animator>();
				MonsterAnimator->CreateAnimation(L"MonsterIdle", ObjectTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 220.0f),
					Vector2::Zero, 12, 0.1f);
				MonsterAnimator->CreateAnimation(L"Monstergetkicked", ObjectTexture, Vector2(0.0f, 220.0f), Vector2(100.0f, 220.0f),
					Vector2::Zero, 6, 0.1f);

				MonsterAnimator->PlayAnimation(L"MonsterIdle", true);
				mObj.push_back(mMonster);
			}
			
			mMousePosition = Input::GetMousePosition();
			int mMousepositionX = 0;
			int mMousepositionY = 0;
			mMousepositionX = mMousePosition.x / 84;
			mMousepositionY = mMousePosition.y / 84;

			mMousePosition.x = mMousepositionX;
			mMousePosition.y = mMousepositionY;
			if (mPickObjectType == PickGameObjectType::Wall01)
			{
				Transform* Walltr = Wall01->GetComponent<Transform>();
				Walltr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84 + 30))));
			}
			if (mPickObjectType == PickGameObjectType::Wall03)
			{
				Transform* Walltr = Wall03->GetComponent<Transform>();
				Walltr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84 + 30))));
			}
			if (mPickObjectType == PickGameObjectType::Wall04)
			{
				Transform* Walltr = Wall04->GetComponent<Transform>();
				Walltr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84 + 30))));
			}
			if (mPickObjectType == PickGameObjectType::Wall08)
			{
				Transform* Walltr = Wall08->GetComponent<Transform>();
				Walltr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84 + 30))));
			}
			if (mPickObjectType == PickGameObjectType::Monster)
			{
				Transform* Montr = mMonster->GetComponent<Transform>();
				Montr->SetPosition(Vector2((mMousePosition.x * 84), ((mMousePosition.y * 84))));
			}
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
			eGameObjectType gameobjtype = gameobj->GetObjectType();
			Vector2 position = tr->GetPosition();


			int type = (int)gameobjtype;
			fwrite(&type, sizeof(int), 1, pFile);
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
			int type = -1;
			int posX = 0;
			int posY = 0;
			if (fread(&type, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			switch ((eGameObjectType)type)
			{
			case enums::eGameObjectType::Wall01:
			{
				Wall* wall = object::Instantiate<Wall>(eLayerType::Object);
				SpriteRenderer* spr = wall->AddComponent<SpriteRenderer>();
				spr->SetTexture(Resources::Find<graphcis::Texture>(L"wall01"));
				wall->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
				mObj.push_back(wall);
				break;
			}
			case enums::eGameObjectType::Wall03:
			{
				Wall* wall = object::Instantiate<Wall>(eLayerType::Object);
				SpriteRenderer* spr = wall->AddComponent<SpriteRenderer>();
				spr->SetTexture(Resources::Find<graphcis::Texture>(L"wall03"));
				wall->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
				mObj.push_back(wall);
				break;
			}
			case enums::eGameObjectType::Wall04:
			{
				Wall* wall = object::Instantiate<Wall>(eLayerType::Object);
				SpriteRenderer* spr = wall->AddComponent<SpriteRenderer>();
				spr->SetTexture(Resources::Find<graphcis::Texture>(L"wall04"));
				wall->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
				mObj.push_back(wall);
				break;
			}
			case enums::eGameObjectType::Wall08:
			{
				Wall* wall = object::Instantiate<Wall>(eLayerType::Object);
				SpriteRenderer* spr = wall->AddComponent<SpriteRenderer>();
				spr->SetTexture(Resources::Find<graphcis::Texture>(L"wall08"));
				wall->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
				mObj.push_back(wall);
				break;
			}
			case enums::eGameObjectType::Monster:
			{
				Monster* monster = object::Instantiate<Monster>(enums::eLayerType::Monster);
				monster->AddComponent<MonsterScript>();
				BoxCollider2D* moncollider = monster->AddComponent<BoxCollider2D>();
				moncollider->Setoffset(Vector2(0.0f, 30.0f));

				graphcis::Texture* ObjectTexture = Resources::Find<graphcis::Texture>(L"Monster");
				MonsterAnimator = monster->AddComponent<Animator>();
				MonsterAnimator->CreateAnimation(L"MonsterIdle", ObjectTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 220.0f),
					Vector2::Zero, 12, 0.1f);
				MonsterAnimator->CreateAnimation(L"Monstergetkicked", ObjectTexture, Vector2(0.0f, 220.0f), Vector2(100.0f, 220.0f),
					Vector2::Zero, 6, 0.1f);

				MonsterAnimator->PlayAnimation(L"MonsterIdle", true);
				monster->GetComponent<Transform>()->SetPosition(Vector2(posX, posY));
				mObj.push_back(monster);
				break;
			}
			}
		}
	}
}