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
		// Ű�� ����� �Լ�
		creatKeys();
	}
	void Input::Update()
	{
		// Ű�� ������Ʈ�ϴ� �Լ�
		updateKeys();
	}

	void Input::creatKeys()
	{
		// for���� ���Ͽ� ���� ����� Ű������ Ű����
		// ���³� �̸��� �����ڷ��� Keys�� �����Ѵ�.
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
		//Keys�� ������ ó������ ��������
		//������Ʈ�� ������ش�.
		std::for_each(Keys.begin(), Keys.end(),
			[](Key& key) -> void
			{
				// for���� ����ϰ� Keys������ ó������ ������ �ԷµǾ��ִ�
				// Ű�� ���ڷ� �޴´�.
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
