#pragma once
#include "..\\KJMengine_SOURCE\\jmSceneManager.h"
#include "jmPlayScene.h"
#include "jmCutScene.h"
#include "jmMenuScene.h"

namespace jm
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		
		SceneManager::LoadScene(L"PlayScene");
	}
}

