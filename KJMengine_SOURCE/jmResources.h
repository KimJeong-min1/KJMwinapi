#pragma once
#include "jmResource.h"
namespace jm
{
	class Resources
	{
	public:
		template <typename T>
		static T* Find(const std::wstring& key)
		{
			// Ű�� �ش��ϴ� ���ҽ��� ã���Ѵ�
			auto iter = mResources.find(key);
			// ���� �����ÿ��� nullptr �� ��ȯ
			if (iter == mResources.end())
				return nullptr;

			// ������ ������ return�Ѵ�. ������ ��ȯ
			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// ���ø��� �̿��Ͽ� �ڷ����� ���Ǹ� ���س����ʰ� �����Ӱ� �̿��Ѵ�.
			// ResourcesŬ������ find �Լ��� ���ڸ� ���� ���ҽ��� �����ϰ�
			// ���� �� ���ҽ������� null�� �ƴ϶�� return�� �ٷ� ���ִ� ��������
			// ����ڵ带 �ۼ��Ѵ�.
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
				return resource;
			
			// ���� null�̶�� new�����ڸ� ���� �����Ҵ��� T������ �Ҵ����ϰ�
			resource = new T();
			// ���� �� ���ҽ��� ��ΰ� �߸��Ǿ� ��ã�´ٸ� ����â�� �߰��Ѵ�.
			if (FAILED(resource->Load(path)))
				assert(false);

			// ������ ������ �̸��� ��θ� �����ϰ� ���� �����ش�.
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			// ���ҽ��� �������ش�.
			return resource;
		}
		static void Release()
		{
			for (auto& iter : mResources)
			{
				delete iter.second;
				iter.second = nullptr;
			}
		}
		static void Insert(const std::wstring& key, Resource* resource)
		{
			if (key == L"")
				return;
			if (resource == nullptr)
				return;

			mResources.insert(std::make_pair(key, resource));
		}
	private:
		static std::map<std::wstring, Resource*> mResources;
	};
}

