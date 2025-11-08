#include "jmChapterFour.h"
#include "jmBackGround.h"
#include "jmCharacter.h"
#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmObject.h"
#include "jmResources.h"
#include "jmTransform.h"
namespace jm
{
	ChapterFour::ChapterFour()
	{
	}
	ChapterFour::~ChapterFour()
	{
	}
	void ChapterFour::Initialize()
	{
		BG = object::Instantiate<BackGround>
			(enums::eLayerType::BackGround);
		Malina = object::Instantiate<Character>
			(enums::eLayerType::Character);

		SpriteRenderer* bgsr = BG->AddComponent<SpriteRenderer>();
		graphcis::Texture* bg = Resources::Find<graphcis::Texture>(L"Cp01BG");
		bgsr->SetTexture(bg);

		SpriteRenderer* chsr = Malina->AddComponent<SpriteRenderer>();
		graphcis::Texture* ch = Resources::Find<graphcis::Texture>(L"MaliCh");
		chsr->SetTexture(ch);

		Transform* chtr = Malina->GetComponent<Transform>();
		chtr->SetPosition(Vector2(640.0f, 100.0f));

		Scene::Initialize();
	}
	void ChapterFour::Update()
	{
		Scene::Update();
	}
	void ChapterFour::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void ChapterFour::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void ChapterFour::OnEnter()
	{
	}
	void ChapterFour::OnExit()
	{
	}
}