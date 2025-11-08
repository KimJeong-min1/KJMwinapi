#include "jmChapterTwo.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterTwo::ChapterTwo()
	{
	}
	ChapterTwo::~ChapterTwo()
	{
	}
	void ChapterTwo::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Modeus = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Modeus->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"ModeCh");
		chsr->SetTexture(ch);

		Transform* chtr = Modeus->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterTwo::Update()
	{
		Scene::Update();
	}
	void ChapterTwo::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterTwo::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterTwo::OnEnter()
	{
	}
	void ChapterTwo::OnExit()
	{
	}
}