#pragma once
#include "jmEntity.h"

namespace jm
{
	using namespace enums;

		class GameObject;
		class Component : public Entity
		{
		public:
			Component(enums::eComponentType type);
			~Component();

			virtual void Initialize();
			virtual void Update();
			virtual void LateUpdate();
			virtual void Render(HDC hdc);

			void SetOwner(GameObject* owner) { mOwner = owner; };
			GameObject* GetOwner() { return mOwner; }
			enums::eComponentType Gettype() { return mType; }
		private:
			GameObject* mOwner;
			enums::eComponentType mType;
		};
}

