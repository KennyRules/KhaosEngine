#pragma once

#include "Common.h"
#include "CommonMath.h"

#include "Vector3f.h"

namespace KhaosMath
{
    // Class representing a 2-dimensional vector defined as 2 floating point numbers.
    // By Drew Diamantoukos
    __declspec(align(8)) class Vector2f
    {
    public:
        float x, y;

        // Default constructor will zero all elements.
        Vector2f()
            : x(0.0f), y(0.0f) { };

        // Constructor to explicitly initialize all elements.
        Vector2f(float aX, float aY)
            : x(aX), y(aY) { };

        // Copy constructor.
        Vector2f(const Vector2f& other)
            : x(other.x), y(other.y) { }

        // Move constructor.
        Vector2f(Vector2f&& other)
            : x(std::move(other.x)), y(std::move(other.y)) { }

        // Assignment operator.
        Vector2f& operator=(const Vector2f& other) {
            this->x = other.x;
            this->y = other.y;
            return *this;
        }

        // Add two vectors together to create a new vector.
        Vector2f operator+(const Vector2f& other) const {
            return Vector2f(x + other.x, y + other.y);
        }

        // Subtract another vector from this vector to create a new vector;
        Vector2f operator-(const Vector2f& other) const {
            return Vector2f(x - other.x, y - other.y);
        }

        // Create a vector by multiplying each component of this vector.
        Vector2f operator*(const float aScalar) const {
            return Vector2f(x * aScalar, y * aScalar);
        }

        // Create a vector by dividing each component of this vector.
        Vector2f operator/(const float aScalar) const {
            ASSERT(aScalar != 0.0f);
            return Vector2f(x / aScalar, y / aScalar);
        }

        // Add a vector onto this vector, modifying the original vector.
        Vector2f operator+=(const Vector2f& other) {
            x += other.x;
            y += other.y;
            return *this;
        }

        // Subtract a vector from this vector, modifying the original vector.
        Vector2f operator-=(const Vector2f& other) {
            x -= other.x;
            y -= other.y;
            return *this;
        }

        // Modify this vector by multiplying each component.
        Vector2f operator*=(const float aScalar) {
            x *= aScalar;
            y *= aScalar;
            return *this;
        }

        // Modify this vector by dividing each component.
        Vector2f operator/=(const float aScalar) {
            x /= aScalar;
            y /= aScalar;
            return *this;
        }

        // Determine if this vector is component-wise equal to another vector.
        bool operator==(const Vector2f& other) const {
            return x == other.x && y == other.y;
        }

        // Determine if this vector is component-wise not equal to another vector.
        bool operator!=(const Vector2f& other) const {
            return !(*this == other);
        }

        // Get the magnitude of this vector.
        float getMagnitude() const {
            return sqrt(x * x + y * y);
        }

        // Get the magnitude squared of this vector, which does not use a sqrt operation.
        float getMagnitudeSquared() const {
            return x * x + y * y;
        }

        // Returns the dot product of this vector and another vector.
        float dot(const Vector2f& other) const {
            return x * other.x + y * other.y;
        }

        float operator|(const Vector2f& other) const {
            return x * other.x + y * other.y;
        }

        // Returns the dot product between two vectors.
        static float DotProduct(const Vector2f& aVector, const Vector2f& bVector) {
            return aVector.x * bVector.x + aVector.y * bVector.y;
        }

        // Returns the cross product between this and another vector.
        Vector3f crossProduct(const Vector2f& other) const {
            return Vector3f(0.0f, 0.0f, x * other.y - y * other.x);
        }

        // Returns the cross product between two vectors.
        static Vector3f crossProduct(const Vector2f& aVector, const Vector2f& bVector)  {
            return Vector3f(0.0f, 0.0f, aVector.x * bVector.y - aVector.y * bVector.x);
        }

        // Linear Interpolation between this vector and another. 
        // Beta will be clamped between [0,1] inclusive.
        Vector2f lerpWith(const Vector2f& other, float beta) const {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            return ((*this) * (1.0f - beta)) + (other * beta);
        }

        // Linear Interpolation between this vector and another. 
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        Vector2f lerpNoClampWith(const Vector2f& other, float beta) const {
            return ((*this) * (1.0f - beta)) + (other * beta);
        }

        // Linear Interpolation between two vectors.
        // Beta will be clamped between [0,1] inclusive.
        static Vector2f Lerp(const Vector2f& aVector, const Vector2f& bVector, float beta) {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            return (aVector * (1.0f - beta)) + (bVector * beta);
        }

        // Linear Interpolation between two vectors.
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        static Vector2f LerpNoClamp(const Vector2f& aVector, const Vector2f& bVector, float beta) {
            return (aVector * (1.0f - beta)) + (bVector * beta);
        }

        // Changes this vector into the normalized version of itself.
        void setToNormalized() {
            (*this) /= (*this).getMagnitude();
        }

        // Returns a normalized version of this vector. Does not change the original vector.
        Vector2f getNormalized() const {
            return (*this) / (*this).getMagnitude();
        }

        // Returns a normalized vector. Does not change the original vector.
        static Vector2f Normalized(const Vector2f& aVector) {
            return aVector / aVector.getMagnitude();
        }

        // Returns a vector representing the projection of this vector onto target vector. 
        // Target vector must be a unit vector (magnitude == 1.0f) to produce correct result.
        Vector2f projectedOntoUnitVector(const Vector2f& target) const {
            return target * (*this).dot(target);
        }

        // Returns a vector representing the projection of this vector onto target vector. 
        // Normalization calculation will take place for target vector.
        // If you are sure target is a unit vector, call projectedOntoUnitVector.
        Vector2f projectedOnto(const Vector2f& target) const {
            return target.getNormalized() * (*this).dot(target);
        }

        // Returns a vector representing the projection of a source vector onto a target vector. 
        // Target vector must be a unit vector (magnitude == 1.0f) to produce correct result.
        static Vector2f ProjectOntoUnitVector(const Vector2f& source, const Vector2f& target) {
            return target * source.dot(target);
        }

        // Returns a vector representing the projection of a source vector onto a target vector. 
        // Normalization calculation will take place for target vector.
        // If you are sure target is a unit vector, call projectOntoUnitVector.
        static Vector2f ProjectOnto(const Vector2f& source, const Vector2f& target) {
            return target.getNormalized() * source.dot(target);
        }
    };
}