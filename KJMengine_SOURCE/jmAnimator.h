#pragma once
#include "jmComponent.h"
#include "jmAnimation.h"

namespace jm
{
	class Animator : public Component
	{
	public:
		Animator();
		~Animator();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void CreateAnimation(const std::wstring& name,
			graphcis::Texture* spriteSheet,
			Vector2 lefttop,
			Vector2 Size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);

	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
	};
}

