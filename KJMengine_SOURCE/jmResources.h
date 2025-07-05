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
			// 키에 해당하는 리소스를 찾게한다
			auto iter = mResources.find(key);
			// 만약 없을시에는 nullptr 을 반환
			if (iter == mResources.end())
				return nullptr;

			// 문제가 없을시 return한다. 포인터 반환
			return dynamic_cast<T*>(iter->second);
		}

		template <typename T>
		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			// 템플릿을 이용하여 자료형의 정의를 정해놓지않고 자유롭게 이용한다.
			// Resources클래스의 find 함수의 인자를 통해 리소스를 대입하고
			// 만약 그 리소스변수가 null이 아니라면 return을 바로 해주는 형식으로
			// 방어코드를 작성한다.
			T* resource = Resources::Find<T>(key);
			if (resource != nullptr)
				return resource;
			
			// 만약 null이라면 new연산자를 통해 동적할당을 T형으로 할당을하고
			resource = new T();
			// 만약 그 리소스의 경로가 잘못되어 못찾는다면 오류창을 뜨게한다.
			if (FAILED(resource->Load(path)))
				assert(false);

			// 문제가 없을시 이름과 경로를 세팅하고 서로 묶어준다.
			resource->SetName(key);
			resource->SetPath(path);
			mResources.insert(std::make_pair(key, resource));

			// 리소스를 리턴해준다.
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

