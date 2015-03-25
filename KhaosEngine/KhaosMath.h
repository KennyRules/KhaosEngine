#pragma once

// KhaosMath.h
// This serves as the central hub for all non-trivial KhaosMath function implementations.
// By Drew Diamantoukos

#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Quaternion.h"
#include "Matrix4x4f.h"

using namespace KhaosMath;

//
// Vector4f function definitions.
//

// Performs vector * matrix multiplication. Vector is treated as a row vector.
Vector4f Vector4f::operator*(const Matrix4x4f& other) const {
    return Vector4f(x * other(0, 0) + y * other(1, 0) + z * other(2, 0) + w * other(3, 0),
        x * other(0, 1) + y * other(1, 1) + z * other(2, 1) + w * other(3, 1),
        x * other(0, 2) + y * other(1, 2) + z * other(2, 2) + w * other(3, 3),
        x * other(0, 3) + y * other(1, 3) + z * other(2, 3) + w * other(3, 3));
}

//
// Matrix4x4f function definitions.
//

Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f& other) const {
    Vector4f rows[4] = { getRowVector(0), getRowVector(1), getRowVector(2), getRowVector(3) };
    Vector4f otherCols[4] = { other.getColVector(0), other.getColVector(1),
                              other.getColVector(2), other.getColVector(3)};
    return Matrix4x4f(
        rows[0].dot(otherCols[0]), rows[0].dot(otherCols[1]),
        rows[0].dot(otherCols[2]), rows[0].dot(otherCols[3]),
        rows[1].dot(otherCols[0]), rows[1].dot(otherCols[1]),
        rows[1].dot(otherCols[2]), rows[1].dot(otherCols[3]),
        rows[2].dot(otherCols[0]), rows[2].dot(otherCols[1]),
        rows[2].dot(otherCols[2]), rows[2].dot(otherCols[3]),
        rows[3].dot(otherCols[0]), rows[3].dot(otherCols[1]),
        rows[3].dot(otherCols[2]), rows[3].dot(otherCols[3]));
}

// Returns a row of this matrix as a vector.
Vector4f Matrix4x4f::getRowVector(K_INT aRow) const {
    return Vector4f(elem[aRow][0], elem[aRow][1],
                    elem[aRow][2], elem[aRow][3]);
}

// Returns a column of this matrix as a vector.
Vector4f Matrix4x4f::getColVector(K_INT aCol) const {
    return Vector4f(elem[0][aCol], elem[1][aCol],
                    elem[2][aCol], elem[3][aCol]);
}