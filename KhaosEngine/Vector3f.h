#pragma once

namespace KhaosMath
{
	class Vector3f
	{
	public:
		float x, y, z;

		Vector3f()
			: x(0), y(0), z(0) {};

		Vector3f(float aX, float aY, float aZ)
			: x(aX), y(aY), z(aZ) { };

		Vector3f& operator=(Vector3f&& other) { return *this; }

		Vector3f operator+(const Vector3f other) {
			return Vector3f(x + other.x, y + other.y, z + other.z);
		}
	};
}