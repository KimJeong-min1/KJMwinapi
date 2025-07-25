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
		virtual void Destroy();

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameobj, const enums::eLayerType type);
		Layer* GetLayer(const enums::eLayerType type) { return mLayers[(UINT)type]; }
	
	private:
		void createLayers();
	
	

	private:
		std::vector<Layer*> mLayers;
	};
}

