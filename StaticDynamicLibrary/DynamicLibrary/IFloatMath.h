#pragma once

#ifdef _WIN32
#ifdef DYNAMICLIBRARY_EXPORTS  
#define DYNAMICLIBRARY_API __declspec(dllexport)
#else
#define DYNAMICLIBRARY_API __declspec(dllimport)
#endif

#endif // _WIN32
class IFloatMath {
public:
    virtual float divide(float, float) = 0;
    virtual int modulo(float, float) = 0;

    virtual void Release(void) = 0;

protected:
    //disallow delete through here.
    virtual ~IFloatMath();
    
};

extern "C" DYNAMICLIBRARY_API IFloatMath* GetMathClass();