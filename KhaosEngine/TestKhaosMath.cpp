#include <iostream>
#include <chrono>

#include "KhaosMath.h"

using namespace std;
using namespace std::chrono;
using namespace KhaosMath;

void printVector(const Vector3f& aVector) {
    cout << "{ " << aVector.x << ", " << aVector.y << ", " << aVector.z << " }" << endl;
}

void printMatrix(Matrix4x4f& aMat) {
    cout << "[ " <<
    aMat(0,0) << " " << aMat(0,1) << " " << aMat(0,2) << " " << aMat(0,3) << endl <<
    aMat(1, 0) << " " << aMat(1, 1) << " " << aMat(1, 2) << " " << aMat(1, 3) << endl <<
    aMat(2, 0) << " " << aMat(2, 1) << " " << aMat(2, 2) << " " << aMat(2, 3) << endl <<
    aMat(3, 0) << " " << aMat(3, 1) << " " << aMat(3, 2) << " " << aMat(3, 3) << endl << 
    " ]" << endl;
}

int main() {
    high_resolution_clock clock;

    Matrix4x4f aMatrix(1.0f, 2.0f, 3.0f, 4.0f,
                       5.0f, 6.0f, 7.0f, 8.0f,
                       9.0f, 10.0f, 11.0f, 12.0f,
                       13.0f, 14.0f, 15.0f, 16.0f );

    Matrix4x4f bMatrix(17.0f, 18.0f, 19.0f, 20.0f,
                       21.0f, 22.0f, 23.0f, 24.0f,
                       25.0f, 26.0f, 27.0f, 28.0f,
                       29.0f, 30.0f, 31.0f, 32.0f);

    Vector4f a{ 0.0f, 0.0f, 0.0f, 0.0f };
    Vector4f b{ 2.0f, 4.0f, 8.0f, 16.0f };
    
    __m128 ma = a;
    __m128 mb = b;
    
    _mm_add_ps(ma, mb);
    a + b;
    _mm_add_ps(a, b);

    char input;
    cin >> input;
    return 0;
}