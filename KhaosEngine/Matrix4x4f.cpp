#include "Matrix4x4f.h"

#include "Vector4f.h"

typedef KhaosMath::Matrix4x4f Matrix4x4f;
typedef KhaosMath::Vector4f Vector4f;

// Default constructor that zeros all elem.
Matrix4x4f::Matrix4x4f() {
    memset(elem, 0, sizeof(elem[0][0]) * 16);
}

// Constructor to explicitly initialize all elem.
Matrix4x4f::Matrix4x4f(float a, float b, float c, float d,
    float e, float f, float g, float h,
    float i, float j, float k, float l,
    float m, float n, float o, float p) {
    elem[0][0] = a; elem[0][1] = b; elem[0][2] = c; elem[0][3] = d;
    elem[1][0] = e; elem[1][1] = f; elem[1][2] = g; elem[1][3] = h;
    elem[2][0] = i; elem[2][1] = j; elem[2][2] = k; elem[2][3] = l;
    elem[3][0] = m; elem[3][1] = n; elem[3][2] = o; elem[3][3] = p;
}

float& Matrix4x4f::operator() (K_INT aRow, K_INT aCol) {
    return elem[aRow][aCol];
}

float Matrix4x4f::operator() (K_INT aRow, K_INT aCol) const {
    return elem[aRow][aCol];
}

// Add two matrices together to create a new one.
Matrix4x4f Matrix4x4f::operator+(const Matrix4x4f& other) const {
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
Matrix4x4f Matrix4x4f::operator-(const Matrix4x4f& other) const {
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

Matrix4x4f Matrix4x4f::operator*(const Matrix4x4f& other) const {
    return Matrix4x4f(getRowVector(0).dot(other.getColVector(0)),
        getRowVector(0).dot(other.getColVector(1)),
        getRowVector(0).dot(other.getColVector(2)),
        getRowVector(0).dot(other.getColVector(3)),
        getRowVector(1).dot(other.getColVector(0)),
        getRowVector(1).dot(other.getColVector(1)),
        getRowVector(1).dot(other.getColVector(2)),
        getRowVector(1).dot(other.getColVector(3)),
        getRowVector(2).dot(other.getColVector(0)),
        getRowVector(2).dot(other.getColVector(1)),
        getRowVector(2).dot(other.getColVector(2)),
        getRowVector(2).dot(other.getColVector(3)),
        getRowVector(3).dot(other.getColVector(0)),
        getRowVector(3).dot(other.getColVector(1)),
        getRowVector(3).dot(other.getColVector(2)),
        getRowVector(3).dot(other.getColVector(3)));
}

Matrix4x4f Matrix4x4f::operator*(const float& aScalar) const {
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

Matrix4x4f Matrix4x4f::operator/(const float& aScalar) const {
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

Matrix4x4f Matrix4x4f::operator+=(const Matrix4x4f& other) {
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

Matrix4x4f Matrix4x4f::operator-=(const Matrix4x4f& other) {
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

Matrix4x4f Matrix4x4f::operator*=(const float& aScalar) {
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

Matrix4x4f Matrix4x4f::operator/=(const float& aScalar) {
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

bool Matrix4x4f::operator==(const Matrix4x4f& other) {
    return elem[0][0] == other.elem[0][0] && elem[0][1] == other.elem[0][1] &&
        elem[0][2] == other.elem[0][2] && elem[0][3] == other.elem[0][3] &&
        elem[1][0] == other.elem[1][0] && elem[1][1] == other.elem[1][1] &&
        elem[1][2] == other.elem[1][2] && elem[1][3] == other.elem[1][3] &&
        elem[2][0] == other.elem[2][0] && elem[2][1] == other.elem[2][1] &&
        elem[2][2] == other.elem[2][2] && elem[2][3] == other.elem[2][3] &&
        elem[3][0] == other.elem[3][0] && elem[3][1] == other.elem[3][1] &&
        elem[3][2] == other.elem[3][2] && elem[3][3] == other.elem[3][3];
}

bool Matrix4x4f::operator!=(const Matrix4x4f& other) {
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
Matrix4x4f Matrix4x4f::getTranspose() const {
    return Matrix4x4f(elem[0][0], elem[1][0], elem[2][0], elem[3][0],
        elem[0][1], elem[1][1], elem[2][1], elem[3][1],
        elem[0][2], elem[1][2], elem[2][2], elem[3][2],
        elem[0][3], elem[1][3], elem[2][3], elem[3][3]);
}

// Sets this matrix to its transpose. Original matrix is modified.
void Matrix4x4f::setToTranspose() {
    (*this) = Matrix4x4f(elem[0][0], elem[1][0], elem[2][0], elem[3][0],
        elem[0][1], elem[1][1], elem[2][1], elem[3][1],
        elem[0][2], elem[1][2], elem[2][2], elem[3][2],
        elem[0][3], elem[1][3], elem[2][3], elem[3][3]);
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