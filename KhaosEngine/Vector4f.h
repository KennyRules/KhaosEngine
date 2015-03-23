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
        Vector4f();

        // Constructor to explicitly initialize all elements.
        Vector4f(float aX, float aY, float aZ, float aW);

        // Copy constructor.
        Vector4f(const Vector4f& other);

        // Move constructor.
        Vector4f(Vector4f&& other);

        // Assignment operator.
        Vector4f& operator=(const Vector4f& other);

        // Add two vectors together to create a new vector.
        Vector4f operator+(const Vector4f& other) const;

        // Subtract another vector from this vector to create a new vector;
        Vector4f operator-(const Vector4f& other) const;

        // Create a vector by multiplying each component of this vector.
        Vector4f operator*(const float aScalar) const;

        Vector4f operator*(const Matrix4x4f& other) const;

        // Create a vector by dividing each component of this vector.
        Vector4f operator/(const float aScalar) const;

        // Add a vector onto this vector, modifying the original vector.
        Vector4f operator+=(const Vector4f& other);

        // Subtract a vector from this vector, modifying the original vector.
        Vector4f operator-=(const Vector4f& other);

        // Modify this vector by multiplying each component.
        Vector4f operator*=(const float aScalar);

        // Modify this vector by dividing each component.
        Vector4f operator/=(const float aScalar);

        // Determine if this vector is component-wise equal to another vector.
        bool operator==(const Vector4f& other) const;

        // Determine if this vector is component-wise not equal to another vector.
        bool operator!=(const Vector4f& other) const;

        // Get the magnitude of this vector.
        float getMagnitude() const;

        // Get the magnitude squared of this vector, which does not use a sqrt operation.
        float getMagnitudeSquared() const;

        // Returns the dot product of this vector and another vector.
        float dot(const Vector4f& other) const;

        float operator|(const Vector4f& other) const;

        // Returns the dot product between two vectors.
        static float DotProduct(const Vector4f& aVector, const Vector4f& bVector) {
            return aVector.x * bVector.x + aVector.y * bVector.y +
                   aVector.z * bVector.z + aVector.w * bVector.w;
        }

        // Changes this vector into the normalized version of itself.
        void setToNormalized();

        // Returns a normalized version of this vector. Does not change the original vector.
        Vector4f getNormalized() const;

        // Returns a normalized vector. Does not change the original vector.
        static Vector4f Normalized(const Vector4f& aVector) {
            return aVector / aVector.getMagnitude();
        }
    };
}