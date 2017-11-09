#pragma once
#include<memory>
#include "IFloatMath.h"


/*
With just this class, 
C:\Code\Speech\StaticDynamicLibrary\x64\Debug>dumpbin /EXPORTS DynamicLibrary.lib
shows 
ordinal    name

?divide@FloatMath@@QEAAMMM@Z (public: float __cdecl FloatMath::divide(float,float))
?modulo@FloatMath@@QEAAMMM@Z (public: float __cdecl FloatMath::modulo(float,float))

*/

class /*DYNAMICLIBRARY_API*/ FloatMath : public IFloatMath
{
public:
    //#define DYNAMICLIBRARY_API
    //DYNAMICLIBRARY_API FloatMath(int);
    FloatMath(void) = default;
    virtual void Release(void) override;
    float DYNAMICLIBRARY_API divide(float, float) override;

    int DYNAMICLIBRARY_API modulo(float, float) override;

    float DYNAMICLIBRARY_API multiply(float, float);

    int ceil(float a);

    int ceil_header(float a) { return 100; }
private:
    std::shared_ptr<FloatMath> m_floatPtr;
};


