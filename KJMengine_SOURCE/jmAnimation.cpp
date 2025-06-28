#include "jmAnimation.h"
#include "jmTime.h"
#include "jmTransform.h"
#include "jmGameObject.h"
#include "jmAnimator.h"
#include "jmRenderer.h"
#include "jmCamera.h"

namespace jm
{
	Animation::Animation()
		:Resource(enums::eResourceType::Animation)
		,mAnimator(nullptr)
		,mTexture(nullptr)
		,mAnimationSheet{}
		,mIndex(-1)
		,mTime(0.0f)
		,mbComplete(false)
	{
	}
	Animation::~Animation()
	{
	}
	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}
	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc)
	{
		// 애니메이션을 그려주는 함수
		// 만약 텍스쳐가 null이면 그냥 반환 방어코드
		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		/*if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);*/

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();

		/*AlphaBlend(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, func);*/
		// 특정크기만큼 이색을 제외한 모든 곳을 그려주는 함수
		TransparentBlt(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, RGB(255, 0, 255));
	}
	// 애니메이션을 만들어주는 함수
	void Animation::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, 
		Vector2 lefttop, Vector2 Size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;

		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.lefttop.x = lefttop.x + (Size.x * i);
			sprite.lefttop.y = lefttop.y;
			sprite.size = Size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		// 애니메이션이 처음부터 끝까지 작동되었을 때
		// 다시 처음으로 돌려주는 함수
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}

