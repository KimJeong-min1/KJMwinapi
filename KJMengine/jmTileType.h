#pragma once
#include "..\\KJMengine_SOURCE\\jmComponent.h"
namespace jm
{
	enum class eTileType
	{
		None,
		Player,
		Monster,
		NPC,
		Wall,
		Niddle,
		ClearWall,
	};
	
	class TileType : public Component
	{
	public:
		TileType();
		~TileType();

		void SetTileType(eTileType type) { mTileType = type; }
		eTileType GetTileType() { return mTileType; }

	private:
		eTileType mTileType = eTileType::None;
	};
}

