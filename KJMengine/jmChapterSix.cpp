#include "jmChapterSix.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterSix::ChapterSix()
	{
	}
	ChapterSix::~ChapterSix()
	{
	}
	void ChapterSix::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Azazel = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Azazel->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"AzaCh");
		chsr->SetTexture(ch);

		Transform* chtr = Azazel->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterSix::Update()
	{
		Scene::Update();
	}
	void ChapterSix::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterSix::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterSix::OnEnter()
	{
	}
	void ChapterSix::OnExit()
	{
	}
}