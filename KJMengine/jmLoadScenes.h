#pragma once
#include "..\\KJMengine_SOURCE\\jmSceneManager.h"
#include "jmStageOne.h"
#include "jmStageTwo.h"
#include "jmStageThree.h"
#include "jmStageFour.h"
#include "jmStageFive.h"
#include "jmStageSix.h"
#include "jmStageSeven.h"
#include "jmStageEight.h"
#include "jmStageNine.h"
#include "jmCutScene.h"
#include "jmMenuScene.h"
#include "jmBadendScene.h"
#include "jmDeadScene.h"
#include "jmTestScene.h"
#include "jmChapterOne.h"
#include "jmChapterTwo.h"
#include "jmChapterThree.h"
#include "jmChapterFour.h"
#include "jmChapterFive.h"
#include "jmChapterSix.h"
#include "jmChapterSeven.h"
#include "jmChapterEight.h"
#include "jmChapterNine.h"
namespace jm
{
	void LoadScenes()
	{
		// CreateScene 함수를 통하여 Scene을 내가 명시한 이름대로 만든다
		SceneManager::CreateScene<StageOne>(L"StageOne");
		SceneManager::CreateScene<StageTwo>(L"StageTwo");
		SceneManager::CreateScene<StageThree>(L"StageThree");
		SceneManager::CreateScene<StageFour>(L"StageFour");
		SceneManager::CreateScene<StageFive>(L"StageFive");
		SceneManager::CreateScene<StageSix>(L"StageSix");
		SceneManager::CreateScene<StageSeven>(L"StageSeven");
		SceneManager::CreateScene<StageEight>(L"StageEight");
		SceneManager::CreateScene<StageNine>(L"StageNine");
		SceneManager::CreateScene<CutScene>(L"CutScene");
		SceneManager::CreateScene<MenuScene>(L"MenuScene");
		SceneManager::CreateScene<BadendScene>(L"BadendScene");
		SceneManager::CreateScene<BadendScene>(L"DeadScene");
		SceneManager::CreateScene<ChapterOne>(L"Chapter01");
		SceneManager::CreateScene<ChapterTwo>(L"Chapter02");
		SceneManager::CreateScene<ChapterThree>(L"Chapter03");
		SceneManager::CreateScene<ChapterFour>(L"Chapter04");
		SceneManager::CreateScene<ChapterFive>(L"Chapter05");
		SceneManager::CreateScene<ChapterSix>(L"Chapter06");
		SceneManager::CreateScene<ChapterSeven>(L"Chapter07");
		SceneManager::CreateScene<ChapterEight>(L"Chapter08");
		SceneManager::CreateScene<ChapterNine>(L"Chapter09");
		//SceneManager::CreateScene<TestScene>(L"TestScene");
		// LoadScene 함수를 통하여 내가 처음에 화면에 불러올 Scene을 정한다
		SceneManager::LoadScene(L"StageOne");
	}
}