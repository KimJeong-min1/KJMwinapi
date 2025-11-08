#include "jmTestScene.h"
#include "jmGameObject.h"
#include "jmTransform.h"
#include "jmSpriteRenderer.h"
#include "jmInput.h"
#include "jmTime.h"
#include "jmObject.h"
#include "jmTexture.h"
#include "jmResources.h"
#include "jmRenderer.h"
#include "jmBackGround.h"
#include "jmAnimator.h"
#include "jmBoxCollider2D.h"
#include "jmCollisionManager.h"
#include "jmKey.h"

namespace jm
{
	TestScene::TestScene()
	{
	}
	TestScene::~TestScene()
	{
	}
	void TestScene::Initialize()
	{

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mBG = object::Instantiate<BackGround>(enums::eLayerType::BackGround);
		SpriteRenderer* bgsr = mBG->AddComponent<SpriteRenderer>();
		bgsr->SetSize(Vector2(1.0f, 1.0f));

		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"BG01");
		bgsr->SetTexture(bg);

		mKey = object::Instantiate<Key>(enums::eLayerType::Object);
		graphcis::Texture* ObjectTexture = Resources::Find<graphcis::Texture>(L"Key");
		KeyAnimator = mKey->AddComponent<Animator>();
		KeyAnimator->CreateAnimationByFolder(L"Key", L"..\\Resources\\HelltakerKey", Vector2::Zero, 0.1f);
		KeyAnimator->PlayAnimation(L"Key", true);

		Transform* Keytr = mKey->AddComponent<Transform>();
		Keytr->SetPosition(Vector2(100.0f, 100.0f));

		Scene::Initialize();
	}
	void TestScene::Update()
	{
		Scene::Update();
	}
	void TestScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void TestScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void TestScene::OnEnter()
	{

	}
	void TestScene::OnExit()
	{

	}
}