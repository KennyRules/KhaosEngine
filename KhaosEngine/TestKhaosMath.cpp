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

	auto start = clock.now();
	for (K_INT i = 0; i < 1000000; i++)
		aVector | bVector;
	
	auto end = clock.now();
	auto operatorTime = duration_cast<nanoseconds>(end - start).count();

	start = clock.now();
	for (K_INT i = 0; i < 1000000; i++)
		aVector.dot(bVector);
	end = clock.now();

	auto methodTime = duration_cast<nanoseconds>(end - start).count();

	cout << "Operand method took: " << operatorTime << endl;
	cout << "Dot method took: " << methodTime << endl;

	char input;
	cin >> input;
	return 0;
}