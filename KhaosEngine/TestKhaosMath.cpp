#include <iostream>

#include "Vector3f.h"
#include "Common.h"

using namespace std;
using namespace KhaosMath;

void printVector(const Vector3f& aVector) {
	cout << "{ " << aVector.x << ", " << aVector.y << ", " << aVector.z << " }" << endl;
}

int main() {
	Vector3f aVector(-1.0f, 4.0f, 0.0f);
	Vector3f bVector(1.0f, 2.0f, 3.0f);

	cout << "Vector a: ";
	printVector(aVector);
	cout << "Vector b: ";
	printVector(bVector);
	cout << "Vector a+b: ";
	printVector(aVector + bVector);

	ASSERT(aVector.x == 1.0f);
	return 0;
}