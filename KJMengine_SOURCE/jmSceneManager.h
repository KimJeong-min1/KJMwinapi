#pragma once
#include "jmScene.h"

namespace jm
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			// 어떠한 자료형의 타입이 들어올지 모르니 template를 이용하여 자료형의 제한을 푼다.
			// 템플릿자료형의 scene을 만들고 동적할당을 이용하여 내가 정해둔 Scene의 이름을
			// 대입하고 현재 활성화된 장면에도 대입을하고 초기화까지 진행한다음
			// map자료형의 mScene에 이름과 템플릿자료형의 scene를 묶어서 대입을한다.
			// 그리고 그 템플릿자료형의 scene을 리턴한다.
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}
		/*static Scene* LoadScene(const std::wstring& name)
		{
			if (mActiveScene)
				mActiveScene->OnExit();
			
			std::map<std::wstring, Scene*>::iterator iter 
				= mScene.find(name);

			if (iter == mScene.end())
				return nullptr;

			mActiveScene = iter->second;
			mActiveScene->OnEnter();

			return iter->second;
		}*/
		static Scene* LoadScene(const std::wstring& name);
		static Scene* GetActiveScene() { return mActiveScene; }

		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
	
	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;
	};
}

