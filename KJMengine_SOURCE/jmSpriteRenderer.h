#pragma once
#include "jmEntity.h"
#include "jmComponent.h"
#include "jmTexture.h"

namespace jm
{
	class SpriteRenderer : public Component
	{
	public:
		SpriteRenderer();
		~SpriteRenderer();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		
		void ImageLoad(const std::wstring& path);
		void SetTexture(graphcis::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }
	private:
		Gdiplus::Image* mImage;
		UINT mWidth;
		UINT mHeight;
		graphcis::Texture* mTexture;
		math::Vector2 mSize;
	};
}

