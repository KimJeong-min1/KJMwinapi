#include "jmAnimator.h"
#include "jmResources.h"
#include "jmTexture.h"

namespace jm
{
	Animator::Animator()
		:Component(enums::eComponentType::Animator)
		, mAnimations{}
		,mActiveAnimation(nullptr)
		,mbLoop(false)
	{
	}
	Animator::~Animator()
	{
		for (auto& iter : mAnimations)
		{
			delete iter.second;
			iter.second = nullptr;
		}

		for (auto& iter : mEvents)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
	void Animator::Initialize()
	{
	}
	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			Events* events = FindEvents(mActiveAnimation->GetName());

			if (mActiveAnimation->IsComplete() == true)
			{
				if (events)
					events->mCompleteEvent();

				if (mbLoop == true)
					mActiveAnimation->Reset();
			}
		}
	}
	void Animator::LateUpdate()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
			mActiveAnimation->Render(hdc);
	}
	void Animator::CreateAnimation(const std::wstring& name, graphcis::Texture* spriteSheet,
		Vector2 lefttop, Vector2 Size, Vector2 offset, UINT spriteLength, float duration, Vector2 scale)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;
		animation = new Animation();
		animation->SetName(name);
		animation->SetScale(scale);
		animation->CreateAnimation(name, spriteSheet, lefttop, Size, offset, spriteLength, duration, scale);

		animation->SetAnimator(this);

		Events* events = new Events();
		mEvents.insert(std::make_pair(name, events));

		mAnimations.insert(std::make_pair(name, animation));
	}
	void Animator::CreateAnimationByFolder(const std::wstring& name, const std::wstring& path, Vector2 offset, float duration, Vector2 scale)
	{
		Animation* animation = nullptr;
		animation = FindAnimation(name);
		if (animation != nullptr)
			return;

		int filecnt = 0;
		std::filesystem::path fs(path);
		std::vector<graphcis::Texture*> images = {};

		for (auto& p : std::filesystem::recursive_directory_iterator(fs))
		{
			std::wstring filename = p.path().filename();
			std::wstring fullname = p.path();

			graphcis::Texture* texture = Resources::Load<graphcis::Texture>(filename, fullname);
			images.push_back(texture);
			filecnt++;
		}

		UINT sheetWidth = images[0]->GetWidth() * filecnt;
		UINT sheetHeight = images[0]->GetHeight();
		graphcis::Texture* spriteSheet = graphcis::Texture::Create(name, sheetWidth, sheetHeight);
		
		UINT imageWidth = images[0]->GetWidth();
		UINT imageHeight = images[0]->GetHeight();
		for (size_t i = 0; i < images.size(); i++)
		{
			BitBlt(spriteSheet->GetHdc(), i * imageWidth, 0
				, imageWidth, imageHeight
				, images[i]->GetHdc(), 0, 0, SRCCOPY);
		}

		CreateAnimation(name, spriteSheet
			, Vector2(0.0f, 0.0f), Vector2(imageWidth, imageHeight)
			, offset, filecnt, duration, scale);
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end())
			return nullptr;
		
		return iter->second;
	}
	void Animator::PlayAnimation(const std::wstring& name, bool loop)
	{
		Animation* animation = FindAnimation(name);
		if (animation == nullptr)
			return;

		if (mActiveAnimation)
		{
			Events* currentEvents = FindEvents(mActiveAnimation->GetName());

			if (currentEvents)
				currentEvents->mEndEvent();
		}

		Events* nextEvents = FindEvents(animation->GetName());

		if (nextEvents)
			nextEvents->mStartEvent();

		mActiveAnimation = animation;
		mActiveAnimation->Reset();
		mbLoop = loop;
	}
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		auto iter = mEvents.find(name);
		if (iter == mEvents.end())
			return nullptr;
		
		return iter->second;
	}
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->mStartEvent.mEvent;
	}
	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->mCompleteEvent.mEvent;
	}
	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Events* events = FindEvents(name);
		return events->mEndEvent.mEvent;
	}
}