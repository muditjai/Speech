// ApplicationWithLibraries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "integermath.h"
#include <iostream>
#include "IFloatMath.h"
#include <memory>
#include "Inheritence.h"
#include <Windows.h>
/*
https://www.codeproject.com/Articles/28969/HowTo-Export-C-classes-from-a-DLL
1. __declspec(dllexport) can be used for exporting functions from dll. using other functions in clients will result in linker error. 
2. Full class can be exported using it on class.
3. 3 options. Pure C(without OOP), Full C++(Need same compiler) or best one Abstract interface with C Factory. 
4. dlls functions can be seen using dumpbin /EXPORTS .dll_file or .lib_file. dependency walker can also be used.
5. Non default constructors in cpp also need to explicitly exported. Header functions can be used without export. Default constructors are auto generated in header, so can be used. 
6. Constructor/Destructor/Copy constructor/operator= can be optimized away by compiler if too simple.
7. Exceptions don't cross dll boundary in c/c++ case, but do in c++/c++ case. Each dll has its own C runtime, so manages own memory ie can't free resources outside dll.
8. Side issue - Virtual for using object's vtable implementation instead of static linking and allow derived to do this. 
Pure virtual - force derived to implement this. Can provide a default implementation. Implementation needed when called or for destructors since they are eventually called. Use virtual for destructors.
9. LoadLibrary() and GetProcAddress() can be used for manual load of dll and C style function.
*/
int main()
{
    // Static library and dynamic class library
    {
        IntegerMath intmath;
        std::cout << intmath.divide(11, 2) << std::endl;
        std::cout << intmath.modulo(11, 2) << std::endl;

        /*
        FloatMath floatmath;
        std::cout << floatmath.divide(11, 2) << std::endl;
        std::cout << floatmath.modulo(11, 2) << std::endl;

        std::cout << floatmath.ceil_header(11) << std::endl;
        */

        //error LNK2019: unresolved external symbol "public: float __cdecl FloatMath::ceil(float)" (?ceil@FloatMath@@QEAAMM@Z) referenced in function main
        //std::cout << floatmath.ceil(11) << std::endl;
        // Similarly non default constructor gives link error if non __declspec(dllexport)
    }

    // Clean dll design. Using declspec(dllimport) and interface. 
    {
        std::cout << std::endl;

        //typedef std::unique_ptr<IFloatMath, IFloatMath::Release> IFloatMathPtr;
        IFloatMath* floatPtr = GetMathClass();
        shared_ptr<IFloatMath> IFloatMathPtr(floatPtr, [](IFloatMath* ptr) {ptr->Release(); cout << "Shared ptr release" << endl; });
        shared_ptr<IFloatMath> IFloatMathPtr2 = IFloatMathPtr;

        std::cout << floatPtr->modulo(10, 3) << std::endl;
        //floatPtr->Release(); done through lambda in shared_ptr
        //delete floatPtr; disallowed 
    }

    // Manual library loading 
    {
        std::cout << std::endl;
        HINSTANCE dll = ::LoadLibrary(L"DynamicLibrary.dll");
        if (!dll)
        {
            cout << "Unable to load dll" << endl;
            return 1;
        }

        typedef IFloatMath* (*GetMathClassPtr) (void);

        GetMathClassPtr funcPtr = reinterpret_cast<GetMathClassPtr>(::GetProcAddress(dll, "GetMathClass"));
        if (!funcPtr)
        {
            cout << "Unable to load dll function" << endl;
            return 1;
        }

        shared_ptr<IFloatMath> floatMathPtr(funcPtr(), [](IFloatMath* ptr) {ptr->Release(); cout << "Shared ptr released load lib" << endl; });
        cout << floatMathPtr->divide(7, 6) << endl;

        ::FreeLibrary(dll);
    }

    // Inheritance and initializer list
    {
        std::cout << std::endl;

        Base* bPtr = new Derived();
        bPtr->func();
        delete bPtr;

        std::cout << std::endl;

        Base* bPtr1 = new Base(0);
        bPtr1->func();
        delete bPtr1;

        std::cout << std::endl;

        HasaBase* bPtr2 = new HasaBase();
    }

    //type def test of different types.
    {
        std::cout << std::endl;
        typedef unsigned int UINT_1;
        typedef double UINT_2;

        auto uint1Func = [](UINT_1 i) {cout << "uint 1 function " << i << endl; };
        auto uint2Func = [](UINT_2 i) {cout << "uint 2 function " << i << endl; };

        UINT_1 u1 = 10;
        UINT_2 u2 = 10;
        uint1Func(u1);
        //uint1Func(u2);
        uint2Func(u1);
        uint2Func(u2);
    }
}

