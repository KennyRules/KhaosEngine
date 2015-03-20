#pragma once

#include "Common.h"

namespace KhaosMath
{
	class Vector3f
	{
	public:
		float x, y, z;

		// Default constructor will zero all elements.
		Vector3f()
			: x(0), y(0), z(0) {};

		// Constructor to explicitly initialize all elements.
		Vector3f(float aX, float aY, float aZ)
			: x(aX), y(aY), z(aZ) { };

		// Copy constructor.
		Vector3f(const Vector3f& other)
			: x(other.x), y(other.y), z(other.z) { }

		// Move constructor.
		Vector3f(Vector3f&& other)
			: x(std::move(other.x)), y(std::move(other.y)), z(std::move(other.z)) { }

		// Assignment operator.
		Vector3f& operator=(const Vector3f& other) {
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
			return *this;
		}

		// Add two vectors together to create a new vector.
		Vector3f operator+(const Vector3f& other) const {
			return Vector3f(x + other.x, y + other.y, z + other.z);
		}

		// Subtract another vector from this vector to create a new vector;
		Vector3f operator-(const Vector3f& other) const {
			return Vector3f(x - other.x, y - other.y, z - other.z);
		}

		// Create a vector by multiplying each component of this vector.
		Vector3f operator*(float aScalar) const {
			return Vector3f(x * aScalar, y * aScalar, z * aScalar);
		}

		// Create a vector by dividing each component of this vector.
		Vector3f operator/(float aScalar) const {
			ASSERT(aScalar != 0.0f);
			return Vector3f(x / aScalar, y / aScalar, z / aScalar);
		}

		// Add a vector onto this vector, modifying the original vector.
		Vector3f operator+=(const Vector3f& other) {
			this->x += other.x;
			this->y += other.y;
			this->z += other.z;
			return *this;
		}

		// Subtract a vector from this vector, modifying the original vector.
		Vector3f operator-=(const Vector3f& other) {
			this->x -= other.x;
			this->y -= other.y;
			this->z -= other.z;
			return *this;
		}

		// Modify this vector by multiplying each component.
		Vector3f operator*=(float aScalar) {
			this->x *= aScalar;
			this->y *= aScalar;
			this->z *= aScalar;
			return *this;
		}

		// Modify this vector by dividing each component.
		Vector3f operator/=(float aScalar) {
			this->x /= aScalar;
			this->y /= aScalar;
			this->z /= aScalar;
			return *this;
		}

		// Determine if this vector is component-wise equal to another vector.
		bool operator==(const Vector3f& other) const {
			return x == other.x && y == other.y && z == other.z;
		}

		// Determine if this vector is component-wise not equal to another vector.
		bool operator!=(const Vector3f& other) const {
			return !(*this == other);
		}

		// Get the magnitude of this vector.
		float getMagnitude() const {
			return sqrt(x * x + y * y + z * z);
		}

		// Get the magnitude squared of this vector, which does not use a sqrt operation.
		float getMagnitudeSquared() const {
			return this->dot(*this);
		}

		// Get the dot product of this vector with another vector.
		inline float dot(const Vector3f& other) const {
			return x * other.x + y * other.y + z * other.z;
		}

		inline float operator|(const Vector3f other) const {
			return x * other.x + y * other.y + z * other.z;
		}
	};
}