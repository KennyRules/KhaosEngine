#pragma once

#include "Common.h"
#include "CommonMath.h"

namespace KhaosMath
{
    // Class representing a 3-dimensional vector defined as 3 floating point numbers.
    // By Drew Diamantoukos
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
            return x * x + y * y + z * z;
        }

        // Returns the dot product of this vector and another vector.
        float dot(const Vector3f& other) const {
           return x * other.x + y * other.y + z * other.z;
        }

        float operator|(const Vector3f& other) const {
           return x * other.x + y * other.y + z * other.z;
        }

        // Returns the dot product between two vectors.
        static float DotProduct(const Vector3f& aVector, const Vector3f& bVector) {
            return aVector.x * bVector.x + aVector.y * bVector.y + aVector.z * bVector.z;
        }

        // Returns the cross product between this and another vector.
        Vector3f crossProduct(const Vector3f& other) const {
            return Vector3f(y * other.z - z * other.y,
                            z * other.x - x * other.z,
                            x * other.y - y * other.x);
        }

        // Returns the cross product between two vectors.
        static Vector3f crossProduct(const Vector3f& aVector, const Vector3f& bVector)  {
            return Vector3f(aVector.y * bVector.z - aVector.z * bVector.y,
                            aVector.z * bVector.x - aVector.x * bVector.z,
                            aVector.x * bVector.y - aVector.y * bVector.x);
        }

        // Linear Interpolation between this vector and another. 
        // Beta will be clamped between [0,1] inclusive.
        Vector3f lerpWith(const Vector3f& other, float beta) const {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            return ((*this) * (1.0f - beta)) + (other * beta);
        }

        // Linear Interpolation between this vector and another. 
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        Vector3f lerpNoClampWith(const Vector3f& other, float beta) const {
            return ((*this) * (1.0f - beta)) + (other * beta);
        }

        // Linear Interpolation between two vectors.
        // Beta will be clamped between [0,1] inclusive.
        static Vector3f Lerp(const Vector3f& aVector, const Vector3f bVector, float beta) {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            return (aVector * (1.0f - beta)) + (bVector * beta);
        }

        // Linear Interpolation between two vectors.
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        static Vector3f LerpNoClamp(const Vector3f& aVector, const Vector3f bVector, float beta) {
            return (aVector * (1.0f - beta)) + (bVector * beta);
        }

        // Changes this vector into the normalized version of itself.
        void setToNormalized() {
            (*this) /= (*this).getMagnitude();
        }

        // Returns a normalized version of this vector. Does not change the original vector.
        Vector3f getNormalized() const {
            return (*this) / (*this).getMagnitude();
        }

        // Returns a normalized vector. Does not change the original vector.
        static Vector3f Normalized(const Vector3f& aVector) {
            return aVector / aVector.getMagnitude();
        }

        // Returns a vector representing the projection of this vector onto target vector. 
        // Target vector must be a unit vector (magnitude == 1.0f) to produce correct result.
        Vector3f projectedOntoUnitVector(const Vector3f& target) const {
            return target * (*this).dot(target);
        }

        // Returns a vector representing the projection of this vector onto target vector. 
        // Normalization calculation will take place for target vector.
        // If you are sure target is a unit vector, call projectedOntoUnitVector.
        Vector3f projectedOnto(const Vector3f& target) const {
            return target.getNormalized() * (*this).dot(target);
        }

        // Returns a vector representing the projection of a source vector onto a target vector. 
        // Target vector must be a unit vector (magnitude == 1.0f) to produce correct result.
        static Vector3f ProjectOntoUnitVector(const Vector3f& source, const Vector3f& target) {
            return target * source.dot(target);
        }

        // Returns a vector representing the projection of a source vector onto a target vector. 
        // Normalization calculation will take place for target vector.
        // If you are sure target is a unit vector, call projectOntoUnitVector.
        static Vector3f ProjectOnto(const Vector3f& source, const Vector3f& target) {
            return target.getNormalized() * source.dot(target);
        }
    };
}