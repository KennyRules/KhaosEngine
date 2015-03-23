#include "Vector4f.h"

typedef KhaosMath::Vector4f Vector4f;

// Default constructor will zero all elements.
Vector4f::Vector4f()
    : x(0.0f), y(0.0f), z(0.0f), w(0.0f) { };

// Constructor to explicitly initialize all elements.
Vector4f::Vector4f(float aX, float aY, float aZ, float aW)
    : x(aX), y(aY), z(aZ), w(aW) { };

// Copy constructor.
Vector4f::Vector4f(const Vector4f& other)
    : x(other.x), y(other.y), z(other.z), w(other.w) { }

// Move constructor.
Vector4f::Vector4f(Vector4f&& other)
    : x(std::move(other.x)), y(std::move(other.y)),
    z(std::move(other.z)), w(std::move(other.w)) { }

// Assignment operator.
Vector4f& Vector4f::operator=(const Vector4f& other) {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
}

// Add two vectors together to create a new vector.
Vector4f Vector4f::operator+(const Vector4f& other) const {
    return Vector4f(x + other.x, y + other.y, z + other.z, w + other.w);
}

// Subtract another vector from this vector to create a new vector;
Vector4f Vector4f::operator-(const Vector4f& other) const {
    return Vector4f(x - other.x, y - other.y, z - other.z, w - other.w);
}

// Create a vector by multiplying each component of this vector.
Vector4f Vector4f::operator*(const float aScalar) const {
    return Vector4f(x * aScalar, y * aScalar, z * aScalar, w * aScalar);
}

Vector4f Vector4f::operator*(const Matrix4x4f& other) const {
    return Vector4f(x * other(0, 0) + y * other(1, 0) + z * other(2, 0) + w * other(3, 0),
                    x * other(0, 1) + y * other(1, 1) + z * other(2, 1) + w * other(3, 1),
                    x * other(0, 2) + y * other(1, 2) + z * other(2, 2) + w * other(3, 3),
                    x * other(0, 3) + y * other(1, 3) + z * other(2, 3) + w * other(3, 3));
}

// Create a vector by dividing each component of this vector.
Vector4f Vector4f::operator/(const float aScalar) const {
    ASSERT(aScalar != 0.0f);
    return Vector4f(x / aScalar, y / aScalar, z / aScalar, w / aScalar);
}

// Add a vector onto this vector, modifying the original vector.
Vector4f Vector4f::operator+=(const Vector4f& other) {
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
    return *this;
}

// Subtract a vector from this vector, modifying the original vector.
Vector4f Vector4f::operator-=(const Vector4f& other) {
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
    return *this;
}

// Modify this vector by multiplying each component.
Vector4f Vector4f::operator*=(const float aScalar) {
    this->x *= aScalar;
    this->y *= aScalar;
    this->z *= aScalar;
    this->w *= aScalar;
    return *this;
}

// Modify this vector by dividing each component.
Vector4f Vector4f::operator/=(const float aScalar) {
    this->x /= aScalar;
    this->y /= aScalar;
    this->z /= aScalar;
    this->w /= aScalar;
    return *this;
}

// Determine if this vector is component-wise equal to another vector.
bool Vector4f::operator==(const Vector4f& other) const {
    return x == other.x && y == other.y && z == other.z && w == other.w;
}

// Determine if this vector is component-wise not equal to another vector.
bool Vector4f::operator!=(const Vector4f& other) const {
    return !(*this == other);
}

// Get the magnitude of this vector.
float Vector4f::getMagnitude() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

// Get the magnitude squared of this vector, which does not use a sqrt operation.
float Vector4f::getMagnitudeSquared() const {
    return x * x + y * y + z * z + w * w;
}

// Returns the dot product of this vector and another vector.
float Vector4f::dot(const Vector4f& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

float Vector4f::operator|(const Vector4f& other) const {
    return x * other.x + y * other.y + z * other.z + w * other.w;
}

// Changes this vector into the normalized version of itself.
void Vector4f::setToNormalized() {
    (*this) /= (*this).getMagnitude();
}

// Returns a normalized version of this vector. Does not change the original vector.
Vector4f Vector4f::getNormalized() const {
    return (*this) / (*this).getMagnitude();
}