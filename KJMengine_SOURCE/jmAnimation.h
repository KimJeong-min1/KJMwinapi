#pragma once
#include "jmResource.h"
#include "jmMath.h"
#include "jmTexture.h"

namespace jm
{
	class Animation : public Resource
	{
	public:
		struct Sprite
		{
			Vector2 lefttop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				:lefttop(Vector2::Zero)
				,size(Vector2::Zero)
				,offset(Vector2::Zero)
				,duration(0.0f)

			{

			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name,
			graphcis::Texture* spriteSheet,
			Vector2 lefttop,
			Vector2 Size,
			Vector2 offset,
			UINT spriteLength,
			float duration);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }
		
	private:
		class Animator* mAnimator;
		graphcis::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
	};
}

