// ApplicationWithLibraries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "integermath.h"
#include <iostream>
#include "FloatMath.h"
/*
https://www.codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL
1. __declspec(dllexport) can be used for exporting functions from dll. using other functions in clients will result in linker error. 
2. Full class can be exported using it on class.
3. 3 options. Pure C(without OOP), Full C++(Need same compiler) or best one Abstract interface with C Factory. 
4. dlls functions can be seen using dumpbin /EXPORTS .dll_file or .lib_file. dependency walker can also be used.
5. Non default constructors in cpp also need to explicitly exported. Header functions can be used without export. Default constructors are auto generated in header, so can be used. 
6. Constructor/Destructor/Copy constructor/operator= can be optimized away by compiler if too simple.
7. Exceptions don't cross dll boundary in c/c++ case, but do in c++/c++ case. Each dll has its own C runtime, so manages own memory ie can't free resources outside dll.

*/
int main()
{
    IntegerMath intmath;
    std::cout << intmath.divide(11, 2) << std::endl;
    std::cout << intmath.modulo(11, 2) << std::endl;

    FloatMath floatmath;
    std::cout << floatmath.divide(11, 2) << std::endl;
    std::cout << floatmath.modulo(11, 2) << std::endl;

    std::cout << floatmath.ceil_header(11) << std::endl;

    //error LNK2019: unresolved external symbol "public: float __cdecl FloatMath::ceil(float)" (?ceil@FloatMath@@QEAAMM@Z) referenced in function main
    //std::cout << floatmath.ceil(11) << std::endl;
    // Similarly non default constructor gives link error if non __declspec(dllexport)

}

