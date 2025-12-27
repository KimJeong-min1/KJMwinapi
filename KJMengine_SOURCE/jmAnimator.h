#pragma once
#include "jmComponent.h"
#include "jmAnimation.h"

namespace jm
{
	class Animator : public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};
		
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
			float duration,
			Vector2 scale = Vector2::One);
		void CreateAnimationByFolder(const std::wstring& name, const std::wstring& path
			, Vector2 offset, float duration, Vector2 scale = Vector2::One);
		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);
		bool IsCoplete() { return mActiveAnimation->IsComplete(); }
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
		std::map<std::wstring, Events*> mEvents;
	};
}

