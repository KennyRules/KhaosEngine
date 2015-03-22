#pragma once

#include "Common.h"

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