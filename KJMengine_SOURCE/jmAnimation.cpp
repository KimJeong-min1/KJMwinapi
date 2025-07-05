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
		// 만약 애니메이션이 완료된거라면 반환
		if (mbComplete)
			return;

		// 델타타임을 이용하여 타임을 증강시킴
		mTime += Time::DeltaTime();

		// 만약 델타타임을 이용한 시간이 애니메이션시트의 n번째 인덱스의 듀레이션보다 빠르다면
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			// 다시 mtime을 초기화시킨다
			mTime = 0.0f;
			// 만약 index가 sheet의 사이즈에서 -1 뺀거보다 작다면 증가를 시켜준다
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			// 아니면 컴플리트에 트루를 대입한다
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

		//gameobj 변수에 mAnimator의 포인터형으로 대입
		GameObject* gameObj = mAnimator->GetOwner();
		// tr 변수에 transform 즉 위치정보를 포인터형으로 대입
		Transform* tr = gameObj->GetComponent<Transform>();
		// pos 변수에 tr의 포지션을 가져와서 대입
		Vector2 pos = tr->GetPosition();

		/*if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);*/

		// 이미지 혼합 작업을 제어하는데 사용되는 구조체
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		// Sprite자료형의 변수에 나의 현재 애니메이션의 n번째 프레임을 대입
		Sprite sprite = mAnimationSheet[mIndex];
		// 텍스쳐의 핸들을 대입
		HDC imgHdc = mTexture->GetHdc();

		/*AlphaBlend(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, func);*/
		// 특정크기만큼 이 색을 제외한 모든 곳을 그려주는 함수
		TransparentBlt(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, RGB(255, 0, 255));
	}
	// 애니메이션을 만들어주는 함수
	void Animation::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, 
		Vector2 lefttop, Vector2 Size, Vector2 offset, UINT spriteLength, float duration)
	{
		// graphcis 라이브러리를 이용한 Texture포인터에 지금 내가 만들 시트를 대입
		mTexture = spriteSheet;

		// 반복문을 돌리면서 그 시트의 길이만큼 반복하여 각 1프레임씩
		// 애니메이션을 만들어준다
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.lefttop.x = lefttop.x + (Size.x * i);
			sprite.lefttop.y = lefttop.y;
			sprite.size = Size;
			sprite.offset = offset;
			sprite.duration = duration;

			// 위의 정보를 다 대입한후 나의 애니메이션시트에 대입
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

