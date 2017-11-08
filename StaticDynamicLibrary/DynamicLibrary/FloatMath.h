#pragma once
#include<memory>
#ifdef _WIN32
#ifdef DYNAMICLIBRARY_EXPORTS  
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif
#endif // _WIN32

/*
With just this class, 
C:\Code\Speech\StaticDynamicLibrary\x64\Debug>dumpbin /EXPORTS DynamicLibrary.lib
shows 
ordinal    name

?divide@FloatMath@@QEAAMMM@Z (public: float __cdecl FloatMath::divide(float,float))
?modulo@FloatMath@@QEAAMMM@Z (public: float __cdecl FloatMath::modulo(float,float))

*/

class /*DYNAMICLIBRARY_API*/ FloatMath
{
public:
    //#define DYNAMICLIBRARY_API
    //DYNAMICLIBRARY_API FloatMath(int);
    FloatMath(void) = default;
    float DYNAMICLIBRARY_API divide(float a, float b);

    int DYNAMICLIBRARY_API modulo(float a, float b);

    float DYNAMICLIBRARY_API multiply(float a, float b);

    int ceil(float a);

    int ceil_header(float a) { return 100; }
private:
    std::shared_ptr<FloatMath> m_floatPtr;
};