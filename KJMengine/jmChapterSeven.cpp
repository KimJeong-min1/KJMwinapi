#include "jmChapterSeven.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterSeven::ChapterSeven()
	{
	}
	ChapterSeven::~ChapterSeven()
	{
	}
	void ChapterSeven::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Justice = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Justice->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"JusCh");
		chsr->SetTexture(ch);

		Transform* chtr = Justice->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterSeven::Update()
	{
		Scene::Update();
	}
	void ChapterSeven::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterSeven::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterSeven::OnEnter()
	{
	}
	void ChapterSeven::OnExit()
	{
	}
}