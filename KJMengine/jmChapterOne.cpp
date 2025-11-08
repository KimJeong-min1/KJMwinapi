#include "jmChapterOne.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterOne::ChapterOne()
	{
	}
	ChapterOne::~ChapterOne()
	{
	}
	void ChapterOne::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Pandemonica = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Pandemonica->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"PandeCh");
		chsr->SetTexture(ch);

		Transform* chtr = Pandemonica->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterOne::Update()
	{
		Scene::Update();
	}
	void ChapterOne::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterOne::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterOne::OnEnter()
	{
	}
	void ChapterOne::OnExit()
	{
	}
}