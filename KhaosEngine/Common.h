#pragma once

#include <iostream>

#define ASSERTIONS_ENABLED 1

typedef __int32 K_INT;
typedef __int8	KI_8;
typedef __int16 KI_16;
typedef __int32 KI_32;
typedef __int64 KI_64;

typedef unsigned __int32 K_UINT;
typedef unsigned __int8	 KUI_8;
typedef unsigned __int16 KUI_16;
typedef unsigned __int32 KUI_32;
typedef unsigned __int64 KUI_64;

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