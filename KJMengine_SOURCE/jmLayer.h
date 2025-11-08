#pragma once
#include "jmEntity.h"
#include "CommonInclude.h"
#include "jmGameObject.h"

namespace jm
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);
		virtual void Destroy();

		void AddGameObject(GameObject* gameObject);
		void EraseGameObject(GameObject* eraseGameobj);

		const std::vector<GameObject*> GetGameObjects() { return mGameObjects; }
	private:
		std::vector<GameObject*> mGameObjects;
	};

	typedef std::vector<GameObject*>::iterator GameObjectIter;
}

