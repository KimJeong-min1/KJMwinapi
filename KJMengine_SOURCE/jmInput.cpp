#include "jmInput.h"

namespace jm
{
	std::vector<Input::Key> Input::Keys = {};

	int ASCII[(UINT)eKeyCode::End] =
	{	
		'0','1','2','3','4',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_DOWN, VK_UP
	};
	
	void Input::Initialize()
	{
		// 키를 만드는 함수
		creatKeys();
	}
	void Input::Update()
	{
		// 키를 업데이트하는 함수
		updateKeys();
	}

	void Input::creatKeys()
	{
		// for문을 통하여 내가 명시한 키보드의 키들의
		// 상태나 이름을 벡터자료형 Keys에 삽입한다.
		for (size_t i = 0; i < (UINT)eKeyCode::End; i++)
		{
			Key key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keycode = (eKeyCode)i;

			Keys.push_back(key);
		}
	}
	void Input::updateKeys()
	{
		//Keys의 변수의 처음부터 끝까지를
		//업데이트를 계속해준다.
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				// for문과 비슷하게 Keys변수의 처음부터 끝까지 입력되어있는
				// 키를 인자로 받는다.
				updateKey(key);
			});
	}
	void Input::updateKey(Input::Key& key)
	{
		if (isKeyDown(key.keycode))
		{
			updateKeyDown(key);
		}
		else
		{
			updateKeyUp(key);
		}
	}
	bool Input::isKeyDown(eKeyCode code)
	{
		return GetAsyncKeyState(ASCII[(UINT)code]) & 0x8000;
	}
	void Input::updateKeyDown(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Pressed;
		}
		else
		{
			key.state = eKeyState::Down;
		}

		key.bPressed = true;
	}
	void Input::updateKeyUp(Input::Key& key)
	{
		if (key.bPressed == true)
		{
			key.state = eKeyState::Up;
		}
		else
		{
			key.state = eKeyState::None;
		}

		key.bPressed = false;
	}
}
