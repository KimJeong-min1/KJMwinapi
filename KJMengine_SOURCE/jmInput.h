#pragma once
#include "CommonInclude.h"

namespace jm
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Zero, One, Two, Three, Four,
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		Left, Right, Down, Up,
		End
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keycode;
			eKeyState state;
			bool bPressed;
		};

		static void Initialize();
		static void Update();

		__forceinline static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		__forceinline static bool GetKeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; }
		__forceinline static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; }
		//__forceinline static math::Vector2 GetMousePosition() { return mMousePosition; }
	private:
		static void creatKeys();
		static void updateKeys();
		static void updateKey(Input::Key& key);
		static bool isKeyDown(eKeyCode code);
		static void updateKeyDown(Input::Key& key);
		static void updateKeyUp(Input::Key& key);

	private:
		static std::vector<Key> Keys;
		static math::Vector2 mMousePosition;
	};
}

