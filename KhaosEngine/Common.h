#pragma once

#include <iostream>

#define ASSERTIONS_ENABLED 1

inline void reportAssertionFailure(const char* aMsg, const char* aFile, const int& aLine) {
	std::cerr << "Khaos Engine Assertion Failure: " << aMsg << " in file " << aFile << " on line " << aLine << std::endl;
}

#if ASSERTIONS_ENABLED

#define debugBreak() __asm { int 3 }

#define ASSERT(expr) \
	if (expr) { } \
	else \
	{ \
		reportAssertionFailure(#expr, __FILE__, __LINE__); \
		debugBreak(); \
	}

#else

#define ASSERT(expr)

#endif