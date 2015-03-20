#include <iostream>
#include <chrono>

#include "Vector3f.h"
#include "Common.h"

using namespace std;
using namespace std::chrono;
using namespace KhaosMath;

void printVector(const Vector3f& aVector) {
    cout << "{ " << aVector.x << ", " << aVector.y << ", " << aVector.z << " }" << endl;
}

int main() {
    Vector3f aVector(-1.0f, 4.0f, 0.0f);
    Vector3f bVector(1.0f, 2.0f, 3.0f);
    high_resolution_clock clock;

    cout << "a: ";
    printVector(aVector);
    cout << "b: ";
    printVector(bVector);

    cout << "a dot b: " << aVector.dot(bVector) << endl;
    cout << "magnitude of a: " << aVector.getMagnitude() << endl;
    cout << "magnitude of a squared: " << aVector.getMagnitudeSquared() << endl;
    cout << "sizeof(Vector3f): " << sizeof(Vector3f) << endl;

    float a = aVector | bVector;
    float b = aVector.dot(bVector);
    float c = Vector3f::DotProduct(aVector, bVector);

    char input;
    cin >> input;
    return 0;
}