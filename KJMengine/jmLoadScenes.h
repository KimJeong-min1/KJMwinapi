#pragma once
#include "..\\KJMengine_SOURCE\\jmSceneManager.h"
#include "jmPlayScene.h"
#include "jmCutScene.h"
#include "jmMenuScene.h"
#include "jmBadendScene.h"
#include "jmDeadScene.h"

namespace jm
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<CutScene>(L"CutScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<BadendScene>(L"BadendScene");
		SceneManager::CreateScene<BadendScene>(L"DeadScene");
		SceneManager::LoadScene(L"MenuScene");
	}
}

