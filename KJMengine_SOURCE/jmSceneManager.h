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
			// ��� �ڷ����� Ÿ���� ������ �𸣴� template�� �̿��Ͽ� �ڷ����� ������ Ǭ��.
			// ���ø��ڷ����� scene�� ����� �����Ҵ��� �̿��Ͽ� ���� ���ص� Scene�� �̸���
			// �����ϰ� ���� Ȱ��ȭ�� ��鿡�� �������ϰ� �ʱ�ȭ���� �����Ѵ���
			// map�ڷ����� mScene�� �̸��� ���ø��ڷ����� scene�� ��� �������Ѵ�.
			// �׸��� �� ���ø��ڷ����� scene�� �����Ѵ�.
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

