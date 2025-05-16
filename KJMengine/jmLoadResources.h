#pragma once
#include "..\\KJMengine_SOURCE\\jmResources.h"
#include "..\\KJMengine_SOURCE\\jmTexture.h"

namespace jm
{
	void LoadResources()
	{
		Resources::Load<graphcis::Texture>(L"BG01", L"..\\Resources\\Sprite\\chapterBG0001.png");
		Resources::Load<graphcis::Texture>(L"Player", L"..\\Resources\\Sprite\\Helltaker.bmp");
		Resources::Load<graphcis::Texture>(L"BGMenu", L"..\\Resources\\Texture2D\\dialogueBG_abyss.png");
		Resources::Load<graphcis::Texture>(L"BGCutScene01", L"..\\Resources\\Texture2D\\cutscene_0008_Group-5.png");
		Resources::Load<graphcis::Texture>(L"BGDeadScene01", L"..\\Resources\\Texture2D\\dialogueDeathExport0009.png");
		Resources::Load<graphcis::Texture>(L"Azazel", L"..\\Resources\\Sprite\\Azazel.bmp");
		Resources::Load<graphcis::Texture>(L"Monster", L"..\\Resources\\Sprite\\Monster.bmp");
		Resources::Load<graphcis::Texture>(L"Cerberus", L"..\\Resources\\Sprite\\Cerberus.bmp");
		Resources::Load<graphcis::Texture>(L"Judgement", L"..\\Resources\\Sprite\\Judgement.bmp");
		Resources::Load<graphcis::Texture>(L"Justice", L"..\\Resources\\Sprite\\Justice.bmp");
		Resources::Load<graphcis::Texture>(L"Lucifer", L"..\\Resources\\Sprite\\Lucifer.bmp");
		Resources::Load<graphcis::Texture>(L"Malina", L"..\\Resources\\Sprite\\Malina.bmp");
		Resources::Load<graphcis::Texture>(L"Modeus", L"..\\Resources\\Sprite\\Modeus.bmp");
		Resources::Load<graphcis::Texture>(L"Pandemonica", L"..\\Resources\\Sprite\\Pandemonica.bmp");
		Resources::Load<graphcis::Texture>(L"Zdrada", L"..\\Resources\\Sprite\\Zdrada.bmp");
	}
}