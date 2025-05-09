#pragma once
#include "jmEntity.h"

namespace jm
{
	class Resource : public Entity // 추상클래스라서 엔티티를 상속받아서 사용
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring path) = 0; // 순수가상함수

		const std::wstring& Getpath() { return mPath; }
		void SetPath(const std::wstring path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

