#include "jmChapterEight.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterEight::ChapterEight()
	{
	}
	ChapterEight::~ChapterEight()
	{
	}
	void ChapterEight::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Lusifer = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp02BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Lusifer->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"LusiCh");
		chsr->SetTexture(ch);

		Transform* chtr = Lusifer->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterEight::Update()
	{
		Scene::Update();
	}
	void ChapterEight::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterEight::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterEight::OnEnter()
	{
	}
	void ChapterEight::OnExit()
	{
	}
}