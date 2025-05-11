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
	}
}