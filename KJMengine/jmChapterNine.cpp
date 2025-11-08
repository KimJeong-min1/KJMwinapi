#include "jmChapterNine.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterNine::ChapterNine()
	{
	}
	ChapterNine::~ChapterNine()
	{
	}
	void ChapterNine::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		HPJustice = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp03BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = HPJustice->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"HPJusCh");
		chsr->SetTexture(ch);

		Transform* chtr = HPJustice->GetComponent<Transform>();
		chtr->SetPosition(Vector2(440.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterNine::Update()
	{
		Scene::Update();
	}
	void ChapterNine::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterNine::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterNine::OnEnter()
	{
	}
	void ChapterNine::OnExit()
	{
	}
}