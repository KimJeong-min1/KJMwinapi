#pragma once
#include "CommonInclude.h"

using namespace jm::math;

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

