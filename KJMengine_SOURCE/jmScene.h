#pragma once
#include "jmEntity.h"
#include "jmGameObject.h"
#include "jmLayer.h"
#include "jmEnums.h"

namespace jm
{
	class Scene : public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();
				
	private:
	

	private:
		std::vector<Layer*> mLayers;
	};
}

