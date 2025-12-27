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

		// 파일경로를 인자로 하여 이미지를 로드해오는 함수
		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		// 애니메이션을 만들어주는 함수
		void CreateAnimation(const std::wstring& name,
			graphcis::Texture* spriteSheet,
			Vector2 lefttop,
			Vector2 Size,
			Vector2 offset,
			UINT spriteLength,
			float duration);
		// 애니메이션 재생이 끝났음으로 다시 처음으로 돌려주는 함수
		void Reset();
		// 애니메이션 재생이 끝났는지 구분해주는 함수
		bool IsComplete() { return mbComplete; }
		// 애니메이션 세팅
		void SetAnimator(class Animator* animator) { mAnimator = animator; }
		Vector2 GetScale() { return mScale; }
		void SetScale(Vector2 scale) { mScale = scale; }
	private:
		class Animator* mAnimator;
		graphcis::Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;
		Vector2 mScale;
	};
}

