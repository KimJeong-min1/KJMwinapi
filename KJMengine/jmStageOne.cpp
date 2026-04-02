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
	StageOne::StageOne()
	{
		mMapdata.resize(8, std::vector<GameObject*>(9, nullptr));
	}
	StageOne::~StageOne()
	{
	}
	void StageOne::Initialize()
	{
		Scene::Initialize();
		
		StageSetup();
	}
	void StageOne::Update()
	{
		Scene::Update();
	}
	void StageOne::LateUpdate()
	{
		Scene::LateUpdate();

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
	void StageOne::StageSetup()
	{
		BackGround* bg = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgSR = bg->AddComponent<SpriteRenderer>();
		graphcis::Texture* bgTexture = Resources::Find<graphcis::Texture>(L"BG01");
		bgSR->SetTexture(bgTexture);
		bgSR->SetSize(Vector2(1.0f, 1.0f));


		char mapsetting[8][10] =
		{
			"#########",
			"##### !##",
			"##  $  ##",
			"## % ^###",
			"#  ######",
			"# 1  8 ##",
			"# 3 4  @#",
			"#########",
		};
		int Xpixel = 84;
		int Ypixel = 84;
		int StartXpos = Xpixel * 5;
		int StartYpos = Ypixel * 1;
		for (int y = 0; y < 8; y++)
		{
			for (int x = 0; x < 10; x++)
			{
				if (mapsetting[y][x] == '!')
				{
					mPlayer = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(0, 0));
					mPlayer->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y)));
					mPlayer->AddComponent<Animator>();
					Animator* playerAnimator = mPlayer->GetComponent<Animator>();
					playerAnimator->CreateAnimationByFolder(L"RightIdle", L"..\\Resources\\HelltakerRightIdle", Vector2::Zero, 0.05f);
					playerAnimator->CreateAnimationByFolder(L"RightKick", L"..\\Resources\\HelltakerRightKick", Vector2::Zero, 0.05f);
					playerAnimator->CreateAnimationByFolder(L"LeftIdle", L"..\\Resources\\HelltakerLeftIdle", Vector2::Zero, 0.05f);
					playerAnimator->CreateAnimationByFolder(L"RightMove", L"..\\Resources\\HelltakerRightMove", Vector2::Zero, 1.0f);
					playerAnimator->CreateAnimationByFolder(L"LeftMove", L"..\\Resources\\HelltakerLeftMove", Vector2::Zero, 1.0f);
					playerAnimator->PlayAnimation(L"LeftIdle", true);
					mMapdata[y][x] = mPlayer;
					mPlayer->AddComponent<PlayerScript>();
					mPlayer->GetComponent<PlayerScript>()->SetMapData(mMapdata);
					//mPlayer->AddComponent<TileType>();
					//mPlayer->GetComponent<TileType>()->SetType(TileType::Player);
				}
				if (mapsetting[y][x] == '1')
				{
					Wall* wall01 = object::Instantiate<Wall>(enums::eLayerType::Object);
					wall01->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					graphcis::Texture* wallTexture = Resources::Find<graphcis::Texture>(L"wall01");
					SpriteRenderer* wallSR = wall01->AddComponent<SpriteRenderer>();
					wallSR->SetTexture(wallTexture);
					wallSR->SetSize(Vector2(1.0f, 1.0f));
					mMapdata[y][x] = wall01;
				}
				if (mapsetting[y][x] == '8')
				{
					Wall* wall08 = object::Instantiate<Wall>(enums::eLayerType::Object);
					wall08->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					graphcis::Texture* wallTexture = Resources::Find<graphcis::Texture>(L"wall08");
					SpriteRenderer* wallSR = wall08->AddComponent<SpriteRenderer>();
					wallSR->SetTexture(wallTexture);
					wallSR->SetSize(Vector2(1.0f, 1.0f));
					mMapdata[y][x] = wall08;
				}
				if (mapsetting[y][x] == '3')
				{
					Wall* wall03 = object::Instantiate<Wall>(enums::eLayerType::Object);
					wall03->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					graphcis::Texture* wallTexture = Resources::Find<graphcis::Texture>(L"wall03");
					SpriteRenderer* wallSR = wall03->AddComponent<SpriteRenderer>();
					wallSR->SetTexture(wallTexture);
					wallSR->SetSize(Vector2(1.0f, 1.0f));
					mMapdata[y][x] = wall03;
				}
				if (mapsetting[y][x] == '4')
				{
					Wall* wall04 = object::Instantiate<Wall>(enums::eLayerType::Object);
					wall04->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					graphcis::Texture* wallTexture = Resources::Find<graphcis::Texture>(L"wall04");
					SpriteRenderer* wallSR = wall04->AddComponent<SpriteRenderer>();
					wallSR->SetTexture(wallTexture);
					wallSR->SetSize(Vector2(1.0f, 1.0f));
					mMapdata[y][x] = wall04;
				}
				if (mapsetting[y][x] == '$')
				{
					Monster* monster01 = object::Instantiate<Monster>(enums::eLayerType::Monster, Vector2(0, 0));
					monster01->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y)));
					graphcis::Texture* monsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
					Animator* monsterAnimator = monster01->AddComponent<Animator>();
					monsterAnimator->CreateAnimationByFolder(L"MonsterIdle", L"..\\Resources\\MonsterIdle", Vector2::Zero, 0.05f);
					monsterAnimator->PlayAnimation(L"MonsterIdle", true);
					mMapdata[y][x] = monster01;
				}
				if (mapsetting[y][x] == '%')
				{
					Monster* monster02 = object::Instantiate<Monster>(enums::eLayerType::Monster, Vector2(0, 0));
					monster02->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y)));
					graphcis::Texture* monsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
					Animator* monsterAnimator = monster02->AddComponent<Animator>();
					monsterAnimator->CreateAnimationByFolder(L"MonsterIdle", L"..\\Resources\\MonsterIdle", Vector2::Zero, 0.05f);
					monsterAnimator->PlayAnimation(L"MonsterIdle", true);
					mMapdata[y][x] = monster02;
				}
				if (mapsetting[y][x] == '^')
				{
					Monster* monster03 = object::Instantiate<Monster>(enums::eLayerType::Monster, Vector2(0, 0));
					monster03->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y)));
					graphcis::Texture* monsterTexture = Resources::Find<graphcis::Texture>(L"Monster");
					Animator* monsterAnimator = monster03->AddComponent<Animator>();
					monsterAnimator->CreateAnimationByFolder(L"MonsterIdle", L"..\\Resources\\MonsterIdle", Vector2::Zero, 0.05f);
					monsterAnimator->PlayAnimation(L"MonsterIdle", true);
					mMapdata[y][x] = monster03;
				}
				if (mapsetting[y][x] == '@')
				{
					NPC* pandemonica = object::Instantiate<NPC>(enums::eLayerType::NPC, Vector2(0, 0));
					pandemonica->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					graphcis::Texture* pandemonicaTexture = Resources::Find<graphcis::Texture>(L"Pandemonica");
					Animator* pandemonicaAnimator = pandemonica->AddComponent<Animator>();
					pandemonicaAnimator->CreateAnimation(L"PandemonicaIdle", pandemonicaTexture, Vector2(0.0f, 0.0f), Vector2(100.0f, 100.0f),
						Vector2::Zero, 12, 0.05f, Vector2(1.0f, 1.0f));
					pandemonicaAnimator->PlayAnimation(L"PandemonicaIdle", true);
					mMapdata[y][x] = pandemonica;
				}
				if (mapsetting[y][x] == '#')
				{
					ClearWall* clearwall = object::Instantiate<ClearWall>(enums::eLayerType::Object);
					clearwall->GetComponent<Transform>()->SetPosition(Vector2(StartXpos + (Xpixel * x), StartYpos + (Ypixel * y) + 30));
					mMapdata[y][x] = clearwall;
				}
			}
		}

		Fire* fire01 = object::Instantiate<Fire>(enums::eLayerType::Fire);
		graphcis::Texture* ObjectTexture = Resources::Find<graphcis::Texture>(L"Fire");
		FireAnimator = fire01->AddComponent<Animator>();
		FireAnimator->CreateAnimationByFolder(L"Fire", L"..\\Resources\\HelltakerFire", Vector2::Zero, 0.05f, Vector2(0.5f, 0.5f));
		FireAnimator->PlayAnimation(L"Fire", true);

		Transform* fireTransform = fire01->GetComponent<Transform>();
		fireTransform->SetPosition(Vector2(530.0f, 200.0f));

		Fire* fire02 = object::Instantiate<Fire>(enums::eLayerType::Fire);
		ObjectTexture = Resources::Find<graphcis::Texture>(L"Fire");
		FireAnimator = fire02->AddComponent<Animator>();
		FireAnimator->CreateAnimationByFolder(L"Fire", L"..\\Resources\\HelltakerFire", Vector2::Zero, 0.05f, Vector2(0.5f, 0.5f));
		FireAnimator->PlayAnimation(L"Fire", true);

		fireTransform = fire02->GetComponent<Transform>();
		fireTransform->SetPosition(Vector2(1030.0f, 410.0f));

		Fire* flamebase01 = object::Instantiate<Fire>(enums::eLayerType::Object);
		SpriteRenderer* flameSR = flamebase01->AddComponent<SpriteRenderer>();
		flameSR->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase0");
		flameSR->SetTexture(ObjectTexture);

		Transform* flameTR = flamebase01->GetComponent<Transform>();
		flameTR->SetPosition(Vector2(765.0f, 130.0f));

		Fire* flamebase02 = object::Instantiate<Fire>(enums::eLayerType::Object);
		flameSR = flamebase02->AddComponent<SpriteRenderer>();
		flameSR->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase1");
		flameSR->SetTexture(ObjectTexture);

		flameTR = flamebase02->GetComponent<Transform>();
		flameTR->SetPosition(Vector2(520.0f, 220.0f));

		flamebase02 = object::Instantiate<Fire>(enums::eLayerType::Object);
		flameSR = flamebase02->AddComponent<SpriteRenderer>();
		flameSR->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase0");
		flameSR->SetTexture(ObjectTexture);

		flameTR = flamebase02->GetComponent<Transform>();
		flameTR->SetPosition(Vector2(430.0f, 465.0f));

		Fire* flamebase03 = object::Instantiate<Fire>(enums::eLayerType::Object);
		flameSR = flamebase03->AddComponent<SpriteRenderer>();
		flameSR->SetSize(Vector2(1.0f, 1.0f));
		ObjectTexture = Resources::Find<graphcis::Texture>(L"flamebase1");
		flameSR->SetTexture(ObjectTexture);

		flameTR = flamebase03->GetComponent<Transform>();
		flameTR->SetPosition(Vector2(1020.0f, 430.0f));
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
				MonsterScript* moscript = Monster01->AddComponent<MonsterScript>();
				moscript->SetMapData(mMapdata);
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