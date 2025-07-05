#include "jmTexture.h"
#include "jmApplication.h"
#include "jmResources.h"

extern jm::Application application;

namespace jm::graphcis
{
	Texture* Texture::Create(const std::wstring& name, UINT width, UINT height)
	{
		Texture* image = Resources::Find<Texture>(name);
		if (image)
			return image;

		image = new Texture();
		image->SetName(name);
		image->SetWidth(width);
		image->SetHeight(height);

		HDC hdc = application.GetHdc();
		HWND hwnd = application.GetHwnd();

		image->mBitmap = CreateCompatibleBitmap(hdc, width, height);
		image->mHdc = CreateCompatibleDC(hdc);

		HBITMAP oldbitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldbitmap);

		Resources::Insert(name + L"Image", image);

		return image;
	}
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
		, mbAlpha(false)
	{

	}
	Texture::~Texture()
	{

	}
	// 리소스들을 로드할때 실행이 되는 함수이다.
	HRESULT Texture::Load(const std::wstring& path)
	{
		// ext의 변수에 끝에 bmp인지 png인지 구분하기 위해서 대입을한다.
		std::wstring ext
			= path.substr(path.find_last_of(L".") + 1);

		//bmp 일때
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitmap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE |
				LR_CREATEDIBSECTION);

			if (mBitmap == nullptr)
				return S_FALSE;

			BITMAP info = {};
			GetObject(mBitmap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = application.GetHdc();
			mHdc = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
			DeleteObject(oldBitmap);
		}
		// png일때
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImage = Gdiplus::Image::FromFile(path.c_str());
			
			if (mImage == nullptr)
				return S_FALSE;

			mWidth = mImage->GetWidth();
			mHeight = mImage->GetHeight();
		}

		return S_OK;
	}
}
