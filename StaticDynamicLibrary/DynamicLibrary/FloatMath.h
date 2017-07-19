#pragma once

#ifdef DYNAMICLIBRARY_EXPORTS  
#define DYNAMICLIBRARY_API __declspec(dllexport)   
#else  
#define DYNAMICLIBRARY_API __declspec(dllimport)   
#endif  

class FloatMath
{
public:
	float DYNAMICLIBRARY_API divide(float a, float b);

	float DYNAMICLIBRARY_API modulo(float a, float b);
};