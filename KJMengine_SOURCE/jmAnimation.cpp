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
		// ���� �ִϸ��̼��� �Ϸ�ȰŶ�� ��ȯ
		if (mbComplete)
			return;

		// ��ŸŸ���� �̿��Ͽ� Ÿ���� ������Ŵ
		mTime += Time::DeltaTime();

		// ���� ��ŸŸ���� �̿��� �ð��� �ִϸ��̼ǽ�Ʈ�� n��° �ε����� �෹�̼Ǻ��� �����ٸ�
		if (mAnimationSheet[mIndex].duration < mTime)
		{
			// �ٽ� mtime�� �ʱ�ȭ��Ų��
			mTime = 0.0f;
			// ���� index�� sheet�� ������� -1 ���ź��� �۴ٸ� ������ �����ش�
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			// �ƴϸ� ���ø�Ʈ�� Ʈ�縦 �����Ѵ�
			else
				mbComplete = true;
		}
	}
	void Animation::Render(HDC hdc)
	{
		// �ִϸ��̼��� �׷��ִ� �Լ�
		// ���� �ؽ��İ� null�̸� �׳� ��ȯ ����ڵ�
		if (mTexture == nullptr)
			return;

		//gameobj ������ mAnimator�� ������������ ����
		GameObject* gameObj = mAnimator->GetOwner();
		// tr ������ transform �� ��ġ������ ������������ ����
		Transform* tr = gameObj->GetComponent<Transform>();
		// pos ������ tr�� �������� �����ͼ� ����
		Vector2 pos = tr->GetPosition();

		/*if (renderer::mainCamera)
			pos = renderer::mainCamera->CaluatePosition(pos);*/

		// �̹��� ȥ�� �۾��� �����ϴµ� ���Ǵ� ����ü
		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		// Sprite�ڷ����� ������ ���� ���� �ִϸ��̼��� n��° �������� ����
		Sprite sprite = mAnimationSheet[mIndex];
		// �ؽ����� �ڵ��� ����
		HDC imgHdc = mTexture->GetHdc();

		/*AlphaBlend(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, func);*/
		// Ư��ũ�⸸ŭ �� ���� ������ ��� ���� �׷��ִ� �Լ�
		TransparentBlt(hdc, pos.x, pos.y, sprite.size.x, sprite.size.y, imgHdc, sprite.lefttop.x, sprite.lefttop.y,
			sprite.size.x, sprite.size.y, RGB(255, 0, 255));
	}
	// �ִϸ��̼��� ������ִ� �Լ�
	void Animation::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet, 
		Vector2 lefttop, Vector2 Size, Vector2 offset, UINT spriteLength, float duration)
	{
		// graphcis ���̺귯���� �̿��� Texture�����Ϳ� ���� ���� ���� ��Ʈ�� ����
		mTexture = spriteSheet;

		// �ݺ����� �����鼭 �� ��Ʈ�� ���̸�ŭ �ݺ��Ͽ� �� 1�����Ӿ�
		// �ִϸ��̼��� ������ش�
		for (size_t i = 0; i < spriteLength; i++)
		{
			Sprite sprite = {};
			sprite.lefttop.x = lefttop.x + (Size.x * i);
			sprite.lefttop.y = lefttop.y;
			sprite.size = Size;
			sprite.offset = offset;
			sprite.duration = duration;

			// ���� ������ �� �������� ���� �ִϸ��̼ǽ�Ʈ�� ����
			mAnimationSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
		// �ִϸ��̼��� ó������ ������ �۵��Ǿ��� ��
		// �ٽ� ó������ �����ִ� �Լ�
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}

