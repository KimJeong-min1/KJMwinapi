#pragma once
#include "jmEntity.h"
#include "CommonInclude.h"
#include "jmGameObject.h"

namespace jm
{
	class Layer
	{
	public:
		Layer();
		~Layer();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);

	private:
		std::vector<GameObject*> mGameObjects;
	};
}

