#pragma once
#include "jmEntity.h"

namespace jm
{
	class Resource abstract : public Entity // 추상클래스라서 엔티티를 상속받아서 사용
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수

		const std::wstring& Getpath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;

		// 게임에서 사용되는 데이터들의 종류
		// 이미지, 사운드... 등등
		// 저장 게임 플레이데이터 HDD, 클라우드 저장을 해둔다.
		// 이것도 리소스이다.
	};
}

