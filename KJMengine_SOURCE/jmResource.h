#pragma once
#include "jmEntity.h"

namespace jm
{
	class Resource abstract : public Entity // �߻�Ŭ������ ��ƼƼ�� ��ӹ޾Ƽ� ���
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ�

		const std::wstring& Getpath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;

		// ���ӿ��� ���Ǵ� �����͵��� ����
		// �̹���, ����... ���
		// ���� ���� �÷��̵����� HDD, Ŭ���� ������ �صд�.
		// �̰͵� ���ҽ��̴�.
	};
}

