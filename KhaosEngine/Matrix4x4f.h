#pragma once

#include "Common.h"
#include "CommonMath.h"

namespace KhaosMath
{
    // Class representing a 4x4 matrix comprised of 16 floats.
    // By Drew Diamantoukos
    __declspec(align(16)) class Matrix4x4f
    {
    public:
        float elements[4][4];

        // Default constructor that zeros all elements.
        Matrix4x4f() {
            memset(elements, 0, sizeof(elements[0][0]) * 16);
        }

        // Constructor to explicitly initialize all elements.
        Matrix4x4f(float a, float b, float c, float d,
                   float e, float f, float g, float h,
                   float i, float j, float k, float l,
                   float m, float n, float o, float p) { 
            elements[0][0] = a; elements[0][1] = b; elements[0][2] = c; elements[0][3] = d;
            elements[1][0] = e; elements[1][1] = f; elements[1][2] = g; elements[1][3] = h;
            elements[2][0] = i; elements[2][1] = j; elements[2][2] = k; elements[2][3] = l;
            elements[3][0] = m; elements[3][1] = n; elements[3][2] = o; elements[3][3] = p;
        }

        float* operator[](const K_INT index) {
            return elements[index];
        }

        // Add two matrices together to create a new one.
        Matrix4x4f operator+(const Matrix4x4f& other) const {
            return Matrix4x4f(
                elements[0][0] + other.elements[0][0], elements[0][1] + other.elements[0][1],
                elements[0][2] + other.elements[0][2], elements[0][3] + other.elements[0][3],
                elements[1][0] + other.elements[1][0], elements[1][1] + other.elements[1][1],
                elements[1][2] + other.elements[1][2], elements[1][3] + other.elements[1][3],
                elements[2][0] + other.elements[2][0], elements[2][1] + other.elements[2][1],
                elements[2][2] + other.elements[2][2], elements[2][3] + other.elements[2][3],
                elements[3][0] + other.elements[3][0], elements[3][1] + other.elements[3][1],
                elements[3][2] + other.elements[3][2], elements[3][3] + other.elements[3][3]);
        }

        // Add two matrices together to create a new one.
        Matrix4x4f operator-(const Matrix4x4f& other) const {
            return Matrix4x4f(
                elements[0][0] - other.elements[0][0], elements[0][1] - other.elements[0][1],
                elements[0][2] - other.elements[0][2], elements[0][3] - other.elements[0][3],
                elements[1][0] - other.elements[1][0], elements[1][1] - other.elements[1][1],
                elements[1][2] - other.elements[1][2], elements[1][3] - other.elements[1][3],
                elements[2][0] - other.elements[2][0], elements[2][1] - other.elements[2][1],
                elements[2][2] - other.elements[2][2], elements[2][3] - other.elements[2][3],
                elements[3][0] - other.elements[3][0], elements[3][1] - other.elements[3][1],
                elements[3][2] - other.elements[3][2], elements[3][3] - other.elements[3][3]);
        }

        Matrix4x4f operator*(const float& aScalar) const {
            return Matrix4x4f(
                elements[0][0] * aScalar, elements[0][1] * aScalar, 
                elements[0][2] * aScalar, elements[0][3] * aScalar, 
                elements[1][0] * aScalar, elements[1][1] * aScalar, 
                elements[1][2] * aScalar, elements[1][3] * aScalar, 
                elements[2][0] * aScalar, elements[2][1] * aScalar, 
                elements[2][2] * aScalar, elements[2][3] * aScalar,
                elements[3][0] * aScalar, elements[3][1] * aScalar, 
                elements[3][2] * aScalar, elements[3][3] * aScalar);
        }

        Matrix4x4f operator/(const float& aScalar) const {
            return Matrix4x4f(
                elements[0][0] / aScalar, elements[0][1] / aScalar,
                elements[0][2] / aScalar, elements[0][3] / aScalar,
                elements[1][0] / aScalar, elements[1][1] / aScalar,
                elements[1][2] / aScalar, elements[1][3] / aScalar,
                elements[2][0] / aScalar, elements[2][1] / aScalar,
                elements[2][2] / aScalar, elements[2][3] / aScalar,
                elements[3][0] / aScalar, elements[3][1] / aScalar,
                elements[3][2] / aScalar, elements[3][3] / aScalar);
        }

        Matrix4x4f operator+=(const Matrix4x4f& other) {
            elements[0][0] += other.elements[0][0]; elements[0][1] += other.elements[0][1],
            elements[0][2] += other.elements[0][2]; elements[0][3] += other.elements[0][3];
            elements[1][0] += other.elements[1][0]; elements[1][1] += other.elements[1][1];
            elements[1][2] += other.elements[1][2]; elements[1][3] += other.elements[1][3];
            elements[2][0] += other.elements[2][0]; elements[2][1] += other.elements[2][1];
            elements[2][2] += other.elements[2][2]; elements[2][3] += other.elements[2][3];
            elements[3][0] += other.elements[3][0]; elements[3][1] += other.elements[3][1];
            elements[3][2] += other.elements[3][2]; elements[3][3] += other.elements[3][3];
            return *this;
        }

        Matrix4x4f operator-=(const Matrix4x4f& other) {
            elements[0][0] -= other.elements[0][0]; elements[0][1] -= other.elements[0][1];
            elements[0][2] -= other.elements[0][2]; elements[0][3] -= other.elements[0][3];
            elements[1][0] -= other.elements[1][0]; elements[1][1] -= other.elements[1][1];
            elements[1][2] -= other.elements[1][2]; elements[1][3] -= other.elements[1][3];
            elements[2][0] -= other.elements[2][0]; elements[2][1] -= other.elements[2][1];
            elements[2][2] -= other.elements[2][2]; elements[2][3] -= other.elements[2][3];
            elements[3][0] -= other.elements[3][0]; elements[3][1] -= other.elements[3][1];
            elements[3][2] -= other.elements[3][2]; elements[3][3] -= other.elements[3][3];
            return *this;
        }

        Matrix4x4f operator*=(const float& aScalar) {
            elements[0][0] *= aScalar; elements[0][1] *= aScalar;
            elements[0][2] *= aScalar; elements[0][3] *= aScalar,
            elements[1][0] *= aScalar; elements[1][1] *= aScalar,
            elements[1][2] *= aScalar; elements[1][3] *= aScalar,
            elements[2][0] *= aScalar; elements[2][1] *= aScalar,
            elements[2][2] *= aScalar; elements[2][3] *= aScalar,
            elements[3][0] *= aScalar; elements[3][1] *= aScalar,
            elements[3][2] *= aScalar; elements[3][3] *= aScalar;
            return *this;
        }

        Matrix4x4f operator/=(const float& aScalar) {
            elements[0][0] /= aScalar; elements[0][1] /= aScalar;
            elements[0][2] /= aScalar; elements[0][3] /= aScalar,
            elements[1][0] /= aScalar; elements[1][1] /= aScalar,
            elements[1][2] /= aScalar; elements[1][3] /= aScalar,
            elements[2][0] /= aScalar; elements[2][1] /= aScalar,
            elements[2][2] /= aScalar; elements[2][3] /= aScalar,
            elements[3][0] /= aScalar; elements[3][1] /= aScalar,
            elements[3][2] /= aScalar; elements[3][3] /= aScalar;
            return *this;
        }

        // Returns the transpose of this matrix. Does not modify the original matrix.
        Matrix4x4f getTranspose() const {
            return Matrix4x4f(elements[0][0], elements[1][0], elements[2][0], elements[3][0],
                              elements[0][1], elements[1][1], elements[2][1], elements[3][1],
                              elements[0][2], elements[1][2], elements[2][2], elements[3][2],
                              elements[0][3], elements[1][3], elements[2][3], elements[3][3]);
        }

        // Sets this matrix to its transpose. Original matrix is modified.
        void setToTranspose() {
            (*this) = Matrix4x4f(elements[0][0], elements[1][0], elements[2][0], elements[3][0],
                                 elements[0][1], elements[1][1], elements[2][1], elements[3][1],
                                 elements[0][2], elements[1][2], elements[2][2], elements[3][2],
                                 elements[0][3], elements[1][3], elements[2][3], elements[3][3]);
        }
    };
}