#include "jmChapterFive.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterFive::ChapterFive()
	{
	}
	ChapterFive::~ChapterFive()
	{
	}
	void ChapterFive::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Zdrada = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Zdrada->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"ZdraCh");
		chsr->SetTexture(ch);

		Transform* chtr = Zdrada->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterFive::Update()
	{
		Scene::Update();
	}
	void ChapterFive::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterFive::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterFive::OnEnter()
	{
	}
	void ChapterFive::OnExit()
	{
	}
}