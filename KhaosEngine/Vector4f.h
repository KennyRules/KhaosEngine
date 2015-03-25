#pragma once

#include "CommonMath.h"

#include "Matrix4x4f.h"

namespace KhaosMath
{
    class Matrix4x4f; // Forward deceleration.

    // Class representing a 4-dimensional vector defined as 4 floating point numbers.
    // By Drew Diamantoukos
    __declspec(align(16)) class Vector4f
    {
    public:
        float x, y, z, w;

        // Default constructor will zero all elements.
        Vector4f()
            : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { };

        // Constructor to explicitly initialize all elements.
        Vector4f(float aX, float aY, float aZ, float aW)
            : x(aX), y(aY), z(aZ), w(aW) { };

        // Copy constructor.
        Vector4f(const Vector4f& other)
            : x(other.x), y(other.y), z(other.z), w(other.w) { }

        // Move constructor.
        Vector4f(Vector4f&& other)
            : x(std::move(other.x)), y(std::move(other.y)),
            z(std::move(other.z)), w(std::move(other.w)) { }

        // Assignment operator.
        Vector4f& operator=(const Vector4f& other) {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->w = other.w;
            return *this;
        }

        // Add two vectors together to create a new vector.
        Vector4f operator+(const Vector4f& other) const {
            return Vector4f(x + other.x, y + other.y, z + other.z, w + other.w);
        }

        // Subtract another vector from this vector to create a new vector;
        Vector4f operator-(const Vector4f& other) const {
            return Vector4f(x - other.x, y - other.y, z - other.z, w - other.w);
        }

        Vector4f operator*(const Matrix4x4f& other) const;

        // Create a vector by multiplying each component of this vector.
        Vector4f operator*(const float aScalar) const {
            return Vector4f(x * aScalar, y * aScalar, z * aScalar, w * aScalar);
        }

        // Create a vector by dividing each component of this vector.
        Vector4f operator/(const float aScalar) const {
            ASSERT(aScalar != 0.0f);
            return Vector4f(x / aScalar, y / aScalar, z / aScalar, w / aScalar);
        }

        // Add a vector onto this vector, modifying the original vector.
        Vector4f operator+=(const Vector4f& other) {
            this->x += other.x;
            this->y += other.y;
            this->z += other.z;
            this->w += other.w;
            return *this;
        }

        // Subtract a vector from this vector, modifying the original vector.
        Vector4f operator-=(const Vector4f& other) {
            this->x -= other.x;
            this->y -= other.y;
            this->z -= other.z;
            this->w -= other.w;
            return *this;
        }

        // Modify this vector by multiplying each component.
        Vector4f operator*=(const float aScalar) {
            this->x *= aScalar;
            this->y *= aScalar;
            this->z *= aScalar;
            this->w *= aScalar;
            return *this;
        }

        // Modify this vector by dividing each component.
        Vector4f operator/=(const float aScalar) {
            this->x /= aScalar;
            this->y /= aScalar;
            this->z /= aScalar;
            this->w /= aScalar;
            return *this;
        }

        // Determine if this vector is component-wise equal to another vector.
        bool operator==(const Vector4f& other) const {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        // Determine if this vector is component-wise not equal to another vector.
        bool operator!=(const Vector4f& other) const {
            return !(*this == other);
        }

        operator __m128() const {
            return _mm_set_ps(x, y, z, w);
        }

        // Get the magnitude of this vector.
        float getMagnitude() const {
            return sqrt(x * x + y * y + z * z + w * w);
        }

        // Get the magnitude squared of this vector, which does not use a sqrt operation.
        float getMagnitudeSquared() const {
            return x * x + y * y + z * z + w * w;
        }

        // Returns the dot product of this vector and another vector.
        float dot(const Vector4f& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }


        // Returns the dot product between two vectors.
        static float DotProduct(const Vector4f& aVector, const Vector4f& bVector) {
            return aVector.x * bVector.x + aVector.y * bVector.y +
                aVector.z * bVector.z + aVector.w * bVector.w;
        }
        float operator|(const Vector4f& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        // Changes this vector into the normalized version of itself.
        void setToNormalized() {
            (*this) /= (*this).getMagnitude();
        }

        // Returns a normalized version of this vector. Does not change the original vector.
        Vector4f getNormalized() const {
            return (*this) / (*this).getMagnitude();
        }

        // Returns a normalized vector. Does not change the original vector.
        static Vector4f Normalized(const Vector4f& aVector) {
            return aVector / aVector.getMagnitude();
        }
    };
}