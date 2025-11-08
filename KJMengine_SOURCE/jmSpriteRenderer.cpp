#include "jmSpriteRenderer.h"
#include "jmGameObject.h"
#include "jmTransform.h"
#include "jmRenderer.h"

namespace jm
{
	SpriteRenderer::SpriteRenderer()
		:Component(enums::eComponentType::SpriteRenderer)
		,mTexture(nullptr)
		,mSize(Vector2::One)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
		// Component 클래스의 업데이트로 인하여 SpriteRenderer클래스의 업데이트를 진행한다.
	}
	void SpriteRenderer::LateUpdate()
	{
		// Component 클래스의 LateUpdate로 인하여 SpriteRenderer클래스의 LateUpdate를 진행한다.
	}
	void SpriteRenderer::Render(HDC hdc)
	{ 
		if (mTexture == nullptr)
			assert(false);
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		/*pos = renderer::mainCamera->CaluatePosition(pos);*/
		
		if (mTexture->GetTexturetype() == graphcis::Texture::eTextureType::Bmp)
		{
			float widthRatio = 0.833333333;
			float heightRatio = 0.833333333;
			TransparentBlt(hdc, pos.x, pos.y,
				mTexture->GetWidth() * mSize.x * widthRatio,
				mTexture->GetHeight() * mSize.y * heightRatio,
				mTexture->GetHdc(), 0, 0, mTexture->GetWidth(),
				mTexture->GetHeight(), RGB(255, 0, 255));
		}
		else if (mTexture->GetTexturetype() == graphcis::Texture::eTextureType::Png)
		{
			float widthRatio = 0.833333333;
			float heightRatio = 0.833333333;
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(),
				Gdiplus::Rect(pos.x, pos.y,
					mTexture->GetWidth() * mSize.x * widthRatio,
					mTexture->GetHeight() * mSize.y * heightRatio));
		}
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImage = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImage->GetWidth();
		mHeight = mImage->GetHeight();
	}
}


