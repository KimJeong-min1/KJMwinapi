#include "jmStageTwo.h"
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
namespace jm
{
	StageTwo::StageTwo()
	{
	}
	StageTwo::~StageTwo()
	{
	}
	void StageTwo::Initialize()
	{
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mBG = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBG->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.0f, 1.0f));

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG02");
		bgsr->SetTexture(bg);
		
		Scene::Initialize();
	}
	void StageTwo::Update()
	{
		Scene::Update();
	}
	void StageTwo::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::One))
		{
			SceneManager::LoadScene(L"StageOne");
		}
		else if (Input::GetKeyDown(eKeyCode::Three))
		{
			SceneManager::LoadScene(L"StageThree");
		}
		else if (Input::GetKeyDown(eKeyCode::Four))
		{
			SceneManager::LoadScene(L"StageFour");
		}
		else if (Input::GetKeyDown(eKeyCode::Five))
		{
			SceneManager::LoadScene(L"StageThree");
		}
		else if (Input::GetKeyDown(eKeyCode::Six))
		{
			SceneManager::LoadScene(L"StageSix");
		}
		else if (Input::GetKeyDown(eKeyCode::Seven))
		{
			SceneManager::LoadScene(L"StageSeven");
		}
		else if (Input::GetKeyDown(eKeyCode::Eight))
		{
			SceneManager::LoadScene(L"StageEight");
		}
		else if (Input::GetKeyDown(eKeyCode::Nine))
		{
			SceneManager::LoadScene(L"StageNine");
		}
	}
	void StageTwo::Render(HDC hdc)
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

		/*MoveToEx(hdc, 0, startoffsety, NULL);
		LineTo(hdc, width, startoffsety);*/

		for (int y = startoffsety; y <= 900; y += cellsize)
		{
			MoveToEx(hdc, 0, y, NULL);
			LineTo(hdc, width, y);
		}

		DeleteObject(oldpen);
	}
	void StageTwo::OnEnter()
	{
	}
	void StageTwo::OnExit()
	{
	}
}