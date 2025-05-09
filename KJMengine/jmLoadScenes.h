#pragma once
#include "..\\KJMengine_SOURCE\\jmSceneManager.h"
#include "jmPlayScene.h"
#include "jmCutScene.h"
#include "jmMenuScene.h"
#include "jmDeadScene.h"

namespace jm
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<CutScene>(L"CutScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<DeadScene>(L"DeadScene");
		
		SceneManager::LoadScene(L"MenuScene");
	}
}

