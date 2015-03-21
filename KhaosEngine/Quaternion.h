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

        // Create a vector by multiplying each component of this vector.
        Quaternion operator*(const float aScalar) const {
            return Quaternion(x * aScalar, y * aScalar, z * aScalar, w * aScalar);
        }

        // Create a vector by dividing each component of this vector.
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

        // Modify this quaternion by multiplying each component.
        Quaternion operator*=(const float aScalar) {
            this->x *= aScalar;
            this->y *= aScalar;
            this->z *= aScalar;
            this->w *= aScalar;
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

        Quaternion getConjugate() const {
            return Quaternion(-x, -y, -z, w);
        }

        Quaternion getInverse() const {
            return getConjugate() / getMagnitudeSquared();
        }
    };
}