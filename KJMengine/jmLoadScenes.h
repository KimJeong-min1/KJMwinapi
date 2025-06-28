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
		// CreateScene 함수를 통하여 Scene을 내가 명시한 이름대로 만든다
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<CutScene>(L"CutScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<BadendScene>(L"BadendScene");
		SceneManager::CreateScene<BadendScene>(L"DeadScene");
		// LoadScene 함수를 통하여 내가 처음에 화면에 불러올 Scene을 정한다
		SceneManager::LoadScene(L"PlayScene");
	}
}

