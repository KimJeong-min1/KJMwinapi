#include "jmSceneManager.h"
#include "jmDontDestroyOnLoad.h"

namespace jm
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyOnLoad = nullptr;

	// 내가 원하는Scene을 들고오게 해주는 함수
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		// 만약 활성화된 Scene이 있다면
		// OnExit 함수를 통해 비활성화를 시킨다.
		if (mActiveScene)
			mActiveScene->OnExit();

		// iterator를 선언하여 변수를 만든후 mScene에 담겨진
		// 값들을 name 변수의 값을 통하여 찾게한다.
		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		// 만약 iter변수를통하여 찾을려고 하였는데도 못찾았다면
		// nullptr 을 반환시켜 즉시 빠져나가게 만든다 (방어코드)
		if (iter == mScene.end())
			return nullptr;

		// 만약 찾았다면 현재 활성화된 장면을 뜻하는 mActiveScene 변수에 
		// iter 변수를 통하여 내가 활성화 시킬 원하는 Scene의 정보를 대입하고
		// OnEnter 함수를통해 활성화를 시킨다.
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		// 그리고 iter의 내가 원하는 정보의 Scene을 리턴한다.
		return iter->second;
	}
	
	void SceneManager::Initialize()
	{
		mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}
	void SceneManager::Update()
	{
		// 현재 활성화 되어있는 Scene을 업데이트한다.
		mActiveScene->Update();
		mDontDestroyOnLoad->Update();
	}
	void SceneManager::LateUpdate()
	{
		// 현재 활성화 되어있는 Scene을 레이트업데이트한다.
		mActiveScene->LateUpdate();
		mDontDestroyOnLoad->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		// 현재 활성화 되어있는 Scene을 그린다.
		mActiveScene->Render(hdc);
		mDontDestroyOnLoad->Render(hdc);
	}
	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
	}
}