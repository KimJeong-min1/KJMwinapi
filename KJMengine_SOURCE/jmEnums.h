#pragma once

namespace jm::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Monster,
		NPC,
		Max = 16
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};
}
