#pragma once
#include <algorithm>
#include <cmath>

namespace jm::math
{
#define PI 3.141592f

	static float ConverDegree(float radian) { return (radian * (180 / PI)); }

	struct Vector2
	{
		Vector2 Rotate(Vector2 vector, float degree)
		{
			float radian = (degree / 180.f) * PI;
			vector.normalize();
			float x = cosf(radian) * vector.x - sinf(radian) * vector.y;
			float y = sinf(radian) * vector.x - cosf(radian) * vector.y;

			return Vector2(x, y);
		}

		float Dot(Vector2& v1, Vector2 v2)
		{
			return v1.x * v2.x + v1.y * v2.y;
		}

		float Cross(Vector2 v1, Vector2 v2)
		{
			return v1.x * v2.y - v1.y * v2.x;
		}
		
		static Vector2 One;
		static Vector2 Zero;
		static Vector2 Half;
		static Vector2 Right;
		static Vector2 Left;
		static Vector2 Up;
		static Vector2 Down;


		// 선형보간 함수 이다. 이는 a 와 b사이의 거리를 부드럽게 움직이게 해주는 효과가있다.
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
		Vector2 operator+=(Vector2 other)
		{
			
			x += other.x;
			y += other.y;
		}
		Vector2 operator-(Vector2 other)
		{
			return Vector2(x - other.x, y - other.y);
		}

		Vector2 operator/(float value)
		{
			return Vector2(x / value, y / value);
		}

		Vector2 operator*(float value)
		{
			return Vector2(x * value, y * value);
		}
		Vector2 operator*(Vector2 v)
		{
			return Vector2(x*v.x, y*v.y);
		}
		void clear()
		{
			x = 0.0f;
			y = 0.0f;
		}

		float length()
		{
			return sqrtf(x * x + y * y);
		}

		Vector2 normalize()
		{
			float len = length();
			x /= len;
			y /= len;

			return *this;
		}
	};

	
}

