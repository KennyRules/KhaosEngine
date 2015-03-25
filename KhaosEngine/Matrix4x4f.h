#pragma once

#include "Common.h"     
#include "CommonMath.h"

#include "Vector4f.h"
 
namespace KhaosMath
{
    class Vector4f; // Forward deceleration.

    // Class representing a 4x4 matrix comprised of 16 floats.
    // By Drew Diamantoukos
    __declspec(align(16)) class Matrix4x4f
    {
    public:
        float elem[4][4];

        // Default constructor that zeros all elem.
        Matrix4x4f() {
            memset(elem, 0, sizeof(elem[0][0]) * 16);
        }

        // Constructor to explicitly initialize all elem.
        Matrix4x4f(float a, float b, float c, float d,
            float e, float f, float g, float h,
            float i, float j, float k, float l,
            float m, float n, float o, float p) {
            elem[0][0] = a; elem[0][1] = b; elem[0][2] = c; elem[0][3] = d;
            elem[1][0] = e; elem[1][1] = f; elem[1][2] = g; elem[1][3] = h;
            elem[2][0] = i; elem[2][1] = j; elem[2][2] = k; elem[2][3] = l;
            elem[3][0] = m; elem[3][1] = n; elem[3][2] = o; elem[3][3] = p;
        }

        float& operator() (K_INT aRow, K_INT aCol) {
            return elem[aRow][aCol];
        }

        float operator() (K_INT aRow, K_INT aCol) const {
            return elem[aRow][aCol];
        }

        // Add two matrices together to create a new one.
        Matrix4x4f operator+(const Matrix4x4f& other) const {
            return Matrix4x4f(
                elem[0][0] + other.elem[0][0], elem[0][1] + other.elem[0][1],
                elem[0][2] + other.elem[0][2], elem[0][3] + other.elem[0][3],
                elem[1][0] + other.elem[1][0], elem[1][1] + other.elem[1][1],
                elem[1][2] + other.elem[1][2], elem[1][3] + other.elem[1][3],
                elem[2][0] + other.elem[2][0], elem[2][1] + other.elem[2][1],
                elem[2][2] + other.elem[2][2], elem[2][3] + other.elem[2][3],
                elem[3][0] + other.elem[3][0], elem[3][1] + other.elem[3][1],
                elem[3][2] + other.elem[3][2], elem[3][3] + other.elem[3][3]);
        }

        // Add two matrices together to create a new one.
        Matrix4x4f operator-(const Matrix4x4f& other) const {
            return Matrix4x4f(
                elem[0][0] - other.elem[0][0], elem[0][1] - other.elem[0][1],
                elem[0][2] - other.elem[0][2], elem[0][3] - other.elem[0][3],
                elem[1][0] - other.elem[1][0], elem[1][1] - other.elem[1][1],
                elem[1][2] - other.elem[1][2], elem[1][3] - other.elem[1][3],
                elem[2][0] - other.elem[2][0], elem[2][1] - other.elem[2][1],
                elem[2][2] - other.elem[2][2], elem[2][3] - other.elem[2][3],
                elem[3][0] - other.elem[3][0], elem[3][1] - other.elem[3][1],
                elem[3][2] - other.elem[3][2], elem[3][3] - other.elem[3][3]);
        }

        Matrix4x4f operator*(const Matrix4x4f& other) const;

        Matrix4x4f multiplyOne(const Matrix4x4f& other) const;
        Matrix4x4f multiplyTwo(const Matrix4x4f& other) const;

        Matrix4x4f operator*(const float aScalar) const {
            return Matrix4x4f(
                elem[0][0] * aScalar, elem[0][1] * aScalar,
                elem[0][2] * aScalar, elem[0][3] * aScalar,
                elem[1][0] * aScalar, elem[1][1] * aScalar,
                elem[1][2] * aScalar, elem[1][3] * aScalar,
                elem[2][0] * aScalar, elem[2][1] * aScalar,
                elem[2][2] * aScalar, elem[2][3] * aScalar,
                elem[3][0] * aScalar, elem[3][1] * aScalar,
                elem[3][2] * aScalar, elem[3][3] * aScalar);
        }

        Matrix4x4f operator/(const float& aScalar) const {
            return Matrix4x4f(
                elem[0][0] / aScalar, elem[0][1] / aScalar,
                elem[0][2] / aScalar, elem[0][3] / aScalar,
                elem[1][0] / aScalar, elem[1][1] / aScalar,
                elem[1][2] / aScalar, elem[1][3] / aScalar,
                elem[2][0] / aScalar, elem[2][1] / aScalar,
                elem[2][2] / aScalar, elem[2][3] / aScalar,
                elem[3][0] / aScalar, elem[3][1] / aScalar,
                elem[3][2] / aScalar, elem[3][3] / aScalar);
        }

        Matrix4x4f operator+=(const Matrix4x4f& other) {
            elem[0][0] += other.elem[0][0]; elem[0][1] += other.elem[0][1],
                elem[0][2] += other.elem[0][2]; elem[0][3] += other.elem[0][3];
            elem[1][0] += other.elem[1][0]; elem[1][1] += other.elem[1][1];
            elem[1][2] += other.elem[1][2]; elem[1][3] += other.elem[1][3];
            elem[2][0] += other.elem[2][0]; elem[2][1] += other.elem[2][1];
            elem[2][2] += other.elem[2][2]; elem[2][3] += other.elem[2][3];
            elem[3][0] += other.elem[3][0]; elem[3][1] += other.elem[3][1];
            elem[3][2] += other.elem[3][2]; elem[3][3] += other.elem[3][3];
            return *this;
        }

        Matrix4x4f operator-=(const Matrix4x4f& other) {
            elem[0][0] -= other.elem[0][0]; elem[0][1] -= other.elem[0][1];
            elem[0][2] -= other.elem[0][2]; elem[0][3] -= other.elem[0][3];
            elem[1][0] -= other.elem[1][0]; elem[1][1] -= other.elem[1][1];
            elem[1][2] -= other.elem[1][2]; elem[1][3] -= other.elem[1][3];
            elem[2][0] -= other.elem[2][0]; elem[2][1] -= other.elem[2][1];
            elem[2][2] -= other.elem[2][2]; elem[2][3] -= other.elem[2][3];
            elem[3][0] -= other.elem[3][0]; elem[3][1] -= other.elem[3][1];
            elem[3][2] -= other.elem[3][2]; elem[3][3] -= other.elem[3][3];
            return *this;
        }

        Matrix4x4f operator*=(const float& aScalar) {
            elem[0][0] *= aScalar; elem[0][1] *= aScalar;
            elem[0][2] *= aScalar; elem[0][3] *= aScalar,
                elem[1][0] *= aScalar; elem[1][1] *= aScalar,
                elem[1][2] *= aScalar; elem[1][3] *= aScalar,
                elem[2][0] *= aScalar; elem[2][1] *= aScalar,
                elem[2][2] *= aScalar; elem[2][3] *= aScalar,
                elem[3][0] *= aScalar; elem[3][1] *= aScalar,
                elem[3][2] *= aScalar; elem[3][3] *= aScalar;
            return *this;
        }

        Matrix4x4f operator/=(const float& aScalar) {
            elem[0][0] /= aScalar; elem[0][1] /= aScalar;
            elem[0][2] /= aScalar; elem[0][3] /= aScalar,
                elem[1][0] /= aScalar; elem[1][1] /= aScalar,
                elem[1][2] /= aScalar; elem[1][3] /= aScalar,
                elem[2][0] /= aScalar; elem[2][1] /= aScalar,
                elem[2][2] /= aScalar; elem[2][3] /= aScalar,
                elem[3][0] /= aScalar; elem[3][1] /= aScalar,
                elem[3][2] /= aScalar; elem[3][3] /= aScalar;
            return *this;
        }

        bool operator==(const Matrix4x4f& other) {
            return elem[0][0] == other.elem[0][0] && elem[0][1] == other.elem[0][1] &&
                elem[0][2] == other.elem[0][2] && elem[0][3] == other.elem[0][3] &&
                elem[1][0] == other.elem[1][0] && elem[1][1] == other.elem[1][1] &&
                elem[1][2] == other.elem[1][2] && elem[1][3] == other.elem[1][3] &&
                elem[2][0] == other.elem[2][0] && elem[2][1] == other.elem[2][1] &&
                elem[2][2] == other.elem[2][2] && elem[2][3] == other.elem[2][3] &&
                elem[3][0] == other.elem[3][0] && elem[3][1] == other.elem[3][1] &&
                elem[3][2] == other.elem[3][2] && elem[3][3] == other.elem[3][3];
        }

        bool operator!=(const Matrix4x4f& other) {
            return !(elem[0][0] == other.elem[0][0] && elem[0][1] == other.elem[0][1] &&
                elem[0][2] == other.elem[0][2] && elem[0][3] == other.elem[0][3] &&
                elem[1][0] == other.elem[1][0] && elem[1][1] == other.elem[1][1] &&
                elem[1][2] == other.elem[1][2] && elem[1][3] == other.elem[1][3] &&
                elem[2][0] == other.elem[2][0] && elem[2][1] == other.elem[2][1] &&
                elem[2][2] == other.elem[2][2] && elem[2][3] == other.elem[2][3] &&
                elem[3][0] == other.elem[3][0] && elem[3][1] == other.elem[3][1] &&
                elem[3][2] == other.elem[3][2] && elem[3][3] == other.elem[3][3]);
        }

        // Returns the transpose of this matrix. Does not modify the original matrix.
        Matrix4x4f getTranspose() const {
            return Matrix4x4f(elem[0][0], elem[1][0], elem[2][0], elem[3][0],
                elem[0][1], elem[1][1], elem[2][1], elem[3][1],
                elem[0][2], elem[1][2], elem[2][2], elem[3][2],
                elem[0][3], elem[1][3], elem[2][3], elem[3][3]);
        }

        // Sets this matrix to its transpose. Original matrix is modified.
        void setToTranspose() {
            (*this) = Matrix4x4f(elem[0][0], elem[1][0], elem[2][0], elem[3][0],
                elem[0][1], elem[1][1], elem[2][1], elem[3][1],
                elem[0][2], elem[1][2], elem[2][2], elem[3][2],
                elem[0][3], elem[1][3], elem[2][3], elem[3][3]);
        }

        // Returns a row of this matrix as a vector.
        Vector4f getRowVector(K_INT aRow) const;

        // Returns a column of this matrix as a vector.
        Vector4f getColVector(K_INT aCol) const;

        // Returns the identity matrix.
        static Matrix4x4f Identity() { 
            return Matrix4x4f(1.0f, 0.0f, 0.0f, 0.0f,
                             0.0f, 1.0f, 0.0f, 0.0f,
                             0.0f, 0.0f, 1.0f, 0.0f,
                             0.0f, 0.0f, 0.0f, 1.0f); 
        }
    };
}