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
        Matrix4x4f();

        // Constructor to explicitly initialize all elem.
        Matrix4x4f(float a, float b, float c, float d,
                   float e, float f, float g, float h,
                   float i, float j, float k, float l,
                   float m, float n, float o, float p);

        float& operator() (K_INT aRow, K_INT aCol);

        float operator() (K_INT aRow, K_INT aCol) const;

        // Add two matrices together to create a new one.
        Matrix4x4f operator+(const Matrix4x4f& other) const;

        // Add two matrices together to create a new one.
        Matrix4x4f operator-(const Matrix4x4f& other) const;

        Matrix4x4f operator*(const Matrix4x4f& other) const;

        Matrix4x4f operator*(const float& aScalar) const;

        Matrix4x4f operator/(const float& aScalar) const;

        Matrix4x4f operator+=(const Matrix4x4f& other);

        Matrix4x4f operator-=(const Matrix4x4f& other);

        Matrix4x4f operator*=(const float& aScalar);

        Matrix4x4f operator/=(const float& aScalar);

        bool operator==(const Matrix4x4f& other);

        bool operator!=(const Matrix4x4f& other);

        // Returns the transpose of this matrix. Does not modify the original matrix.
        Matrix4x4f getTranspose() const;

        // Sets this matrix to its transpose. Original matrix is modified.
        void setToTranspose();

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