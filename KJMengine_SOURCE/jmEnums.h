#pragma once

namespace jm::enums
{
	enum class eGameObjectType
	{
		None,
		Player,
		Monster,
		NPC,
		Wall01,
		Wall03,
		Wall04,
		Wall08,
		Niddle,
		Max = 128
	};
	
	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Monster,
		NPC,
		Object,
		Fire,
		Character,
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

	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};

	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		Collider,
		End,
	};
}
