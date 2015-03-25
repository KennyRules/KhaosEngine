#pragma once

#include "Common.h"
#include "CommonMath.h"
 
#include "Vector3f.h"

namespace KhaosMath
{
    // Class representing a Quaternion defined as 4 floating point numbers.
    // By Drew Diamantoukos
    __declspec(align(16)) class Quaternion
    {
    public:
        float x, y, z, w;

        // Default constructor will zero all elements.
        Quaternion()
            : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { };

        // Constructor to explicitly initialize all elements.
        Quaternion(float aX, float aY, float aZ, float aW)
            : x(aX), y(aY), z(aZ), w(aW) { };

        // Constructor to explicitly initialize all elements.
        Quaternion(const Vector3f aVector, float aW)
            : x(aVector.x), y(aVector.y), z(aVector.z), w(aW) { };

        // Copy constructor.
        Quaternion(const Quaternion& other)
            : x(other.x), y(other.y), z(other.z), w(other.w) { }

        // Move constructor.
        Quaternion(Quaternion&& other)
            : x(std::move(other.x)), y(std::move(other.y)), 
              z(std::move(other.z)), w(std::move(other.w)) { }

        // Assignment operator.
        Quaternion& operator=(const Quaternion& other) {
            this->x = other.x;
            this->y = other.y;
            this->z = other.z;
            this->w = other.w;
            return *this;
        }

        // Create a vector by adding each component of this quaternion.
        Quaternion operator+(const Quaternion& other) const {
            return Quaternion(x + other.x, y + other.y, z + other.z, w + other.w);
        }

        // Create a quaternion by multiplying each component of this quaternion.
        Quaternion operator*(const float aScalar) const {
            return Quaternion(x * aScalar, y * aScalar, z * aScalar, w * aScalar);
        }

        // Create a quaternion by dividing each component of this vector.
        Quaternion operator/(const float aScalar) const {
            ASSERT(aScalar != 0.0f);
            return Quaternion(x / aScalar, y / aScalar, z / aScalar, w /aScalar);
        }

        // Returns the Grassman product between this Quaternion and another.
        Quaternion operator*(const Quaternion& other) const {
            const Vector3f vectorA = this->getVectorPart();
            const Vector3f vectorB = other.getVectorPart();
            Vector3f vectorPart = (vectorB * w) + vectorA * other.w +
                                   vectorA.crossProduct(vectorB);

            float scalarPart = w * other.w - vectorA.dot(vectorB);
            return Quaternion(vectorPart, scalarPart);
        }

        // Modify this quaternion by adding each component.
        Quaternion operator+=(const Quaternion& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;
            return *this;
        }

        // Modify this quaternion by multiplying each component.
        Quaternion operator*=(const float aScalar) {
            x *= aScalar;
            y *= aScalar;
            z *= aScalar;
            w *= aScalar;
            return *this;
        }

        // Modify this quaternion by dividing each component.
        Quaternion operator/=(const float aScalar) {
            this->x /= aScalar;
            this->y /= aScalar;
            this->z /= aScalar;
            this->w /= aScalar;
            return *this;
        }

        // Determine if this quaternion is component-wise equal to another quaternion.
        bool operator==(const Quaternion& other) const {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        // Determine if this quaternion is component-wise not equal to another quaternion.
        bool operator!=(const Quaternion& other) const {
            return !(*this == other);
        }

        operator __m128() const {
            return _mm_set_ps(x, y, z, w);
        }

        // Returns the dot product of this quaternion and another quaternion.
        float dot(const Quaternion& other) const {
            return x * other.x + y * other.y + z * other.z + w * other.w;
        }

        // Returns the dot product between two vectors.
        static float DotProduct(const Quaternion& aQuat, const Quaternion& bQuat) {
            return aQuat.x * bQuat.x + aQuat.y * bQuat.y +
                   aQuat.z * bQuat.z + aQuat.w * bQuat.w;
        }

        // Get the magnitude of this vector.
        float getMagnitude() const {
            return sqrt(x * x + y * y + z * z + w * w);
        }

        // Get the magnitude squared of this vector, which does not use a sqrt operation.
        float getMagnitudeSquared() const {
            return x * x + y * y + z * z + w * w;
        }

        // Returns the vector part of this quaternion.
        Vector3f getVectorPart() const {
            return Vector3f(x, y, z);
        }

        // Returns the conjugate of this quaternion.
        Quaternion getConjugate() const {
            return Quaternion(-x, -y, -z, w);
        }

        // Returns the inverse of this unit quaternion.
        Quaternion getUnitInverse() const {
            return Quaternion(-x, -y, -z, w);
        }

        // Returns the inverse of this quaternion.
        Quaternion getInverse() const {
            return getConjugate() / getMagnitudeSquared();
        }

        // Spherical Linear Interpolation between two quaternions.
        // Beta will be clamped between [0,1] inclusive.
        Quaternion slerpWith(const Quaternion& other, float beta) const {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            float theta = acosf((*this).dot(other));
            float sinTeta = sinf(theta);
            float omegaFirst = sinf(1 - beta) * theta / sinTeta;
            float omegaSecond = sinf(beta * theta) / sinTeta;

            return ((*this) * omegaFirst) + (other * omegaSecond);
        }

        // Spherical Linear Interpolation between two quaternions.
        // Beta will be clamped between [0,1] inclusive.
        static Quaternion Slerp(const Quaternion& aQuat, const Quaternion& bQuat, float beta) {
            beta = ClampInclusive(beta, 0.0f, 1.0f);
            float theta = acosf(aQuat.dot(bQuat));
            float sinTeta = sinf(theta);
            float omegaFirst = sinf(1 - beta) * theta / sinTeta;
            float omegaSecond = sinf(beta * theta) / sinTeta;

            return (aQuat * omegaFirst) + (bQuat * omegaSecond);
        }

        // Spherical Linear Interpolation between two quaternions.
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        Quaternion slerpNoClampWith(const Quaternion& other, float beta) const {
            float theta = acosf((*this).dot(other));
            float sinTeta = sinf(theta);
            float omegaFirst = sinf(1 - beta) * theta / sinTeta;
            float omegaSecond = sinf(beta * theta) / sinTeta;

            return ((*this) * omegaFirst) + (other * omegaSecond);
        }

        // Spherical Linear Interpolation between two quaternions.
        // Beta must be clamped between [0,1], inclusive, before calling to ensure correct result.
        static Quaternion SlerpNoClamp(const Quaternion& aQuat,
                                       const Quaternion& bQuat, float beta) {
            float theta = acosf(aQuat.dot(bQuat));
            float sinTeta = sinf(theta);
            float omegaFirst = sinf(1 - beta) * theta / sinTeta;
            float omegaSecond = sinf(beta * theta) / sinTeta;

            return (aQuat * omegaFirst) + (bQuat * omegaSecond);
        }
    };
}