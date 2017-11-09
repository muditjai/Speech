
#include "FloatMath.h"
#include <math.h>
#include <iostream>

float FloatMath::divide(float a, float b)
{
    return a / b;
}

float FloatMath::multiply(float a, float b)
{
    return a * b;
}

int FloatMath::modulo(float a, float b)
{
    return this->ceil(a) % this->ceil(b);
}


int FloatMath::ceil(float a)
{
    return static_cast<int>(::ceil(a));
}

void FloatMath::Release(void)
{
    std::cout << "Release called " << std::endl;
    delete this;
}

extern "C" DYNAMICLIBRARY_API IFloatMath* GetMathClass()
{
    return new FloatMath();
}