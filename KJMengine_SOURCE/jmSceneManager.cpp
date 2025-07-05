#include "jmSceneManager.h"

namespace jm
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;

	// ���� ���ϴ�Scene�� ������ ���ִ� �Լ�
	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		// ���� Ȱ��ȭ�� Scene�� �ִٸ�
		// OnExit �Լ��� ���� ��Ȱ��ȭ�� ��Ų��.
		if (mActiveScene)
			mActiveScene->OnExit();

		// iterator�� �����Ͽ� ������ ������ mScene�� �����
		// ������ name ������ ���� ���Ͽ� ã���Ѵ�.
		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		// ���� iter���������Ͽ� ã������ �Ͽ��µ��� ��ã�Ҵٸ�
		// nullptr �� ��ȯ���� ��� ���������� ����� (����ڵ�)
		if (iter == mScene.end())
			return nullptr;

		// ���� ã�Ҵٸ� ���� Ȱ��ȭ�� ����� ���ϴ� mActiveScene ������ 
		// iter ������ ���Ͽ� ���� Ȱ��ȭ ��ų ���ϴ� Scene�� ������ �����ϰ�
		// OnEnter �Լ������� Ȱ��ȭ�� ��Ų��.
		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		// �׸��� iter�� ���� ���ϴ� ������ Scene�� �����Ѵ�.
		return iter->second;
	}
	
	void SceneManager::Initialize()
	{
	}
	void SceneManager::Update()
	{
		// ���� Ȱ��ȭ �Ǿ��ִ� Scene�� ������Ʈ�Ѵ�.
		mActiveScene->Update();
	}
	void SceneManager::LateUpdate()
	{
		// ���� Ȱ��ȭ �Ǿ��ִ� Scene�� ����Ʈ������Ʈ�Ѵ�.
		mActiveScene->LateUpdate();
	}
	void SceneManager::Render(HDC hdc)
	{
		// ���� Ȱ��ȭ �Ǿ��ִ� Scene�� �׸���.
		mActiveScene->Render(hdc);
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