#include "jmChapterThree.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterThree::ChapterThree()
	{
	}
	ChapterThree::~ChapterThree()
	{
	}
	void ChapterThree::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Cerberus = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Cerberus->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"CerCh");
		chsr->SetTexture(ch);

		Transform* chtr = Cerberus->GetComponent<Transform>();
		chtr->SetPosition(Vector2(340.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterThree::Update()
	{
		Scene::Update();
	}
	void ChapterThree::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterThree::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterThree::OnEnter()
	{
	}
	void ChapterThree::OnExit()
	{
	}
}