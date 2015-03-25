#pragma once

// CommonMath.h
// All non-class math class related functions and macros are contained in here.
// By Drew Diamantoukos

#include "Common.h"
#include <xmmintrin.h>

// The following SSE macros are adapted from Game Engine Architecture 2nd edition.

// Pseudo SSE multiply and add instruction.
#define _mm_madd_ps(a, b, c) \
    _mm_add_ps(_mm_mul_ps((a), (b)), (c))

#define SHUFFLE_PARAM(x, y, z, w) \
    ((x) | ((y) << 2) | ((z) << 4) | ((w) << 6))

#define _mm_replicate_x_ps(v) \
    _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(0, 0, 0, 0))

#define _mm_replicate_y_ps(v) \
    _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(1, 1, 1, 1))

#define _mm_replicate_z_ps(v) \
    _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(2, 2, 2, 2))

#define _mm_replicate_w_ps(v) \
    _mm_shuffle_ps((v), (v), SHUFFLE_PARAM(3, 3, 3, 3))

namespace KhaosMath
{
    // Clamp a value between minValue and maxValue, inclusive.
    static float ClampInclusive(float aValue, float minValue, float maxValue) {
        if (aValue < minValue)
            return minValue;
        if (aValue > maxValue)
            return maxValue;
        return aValue;
    }
}