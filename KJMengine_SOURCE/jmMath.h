#pragma once
#include <algorithm>

namespace jm::math
{
	struct Vector2
	{
		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Half;

		static Vector2 Lerp(const Vector2& a, const Vector2& b, float t)
		{
			t = std::clamp(t, 0.0f, 1.0f);

			return
			{
				a.x + (b.x - a.x) * t,
				a.y + (b.y - a.y) * t,
			};
		}

		float x;
		float y;

		Vector2()
			: x(0.0f)
			, y(0.0f)
		{

		}

		Vector2(float _x, float _y)
			: x(_x)
			, y(_y)
		{

		}

		Vector2 operator+(Vector2 other)
		{
			return Vector2(x + other.x, y + other.y);
		}

		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}
	};
}

