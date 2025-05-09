#pragma once
#include "CommonInclude.h"

namespace jm
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		std::wstring& GetName() { return mName; }
		void SetName(const std::wstring& name) { mName = name; }
	private:
		std::wstring mName;
	};
}

