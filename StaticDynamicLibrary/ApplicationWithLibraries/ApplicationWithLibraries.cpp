// ApplicationWithLibraries.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "integermath.h"
#include <iostream>
#include "FloatMath.h"

int main()
{
	IntegerMath intmath;
	std::cout << intmath.divide(11, 2) << std::endl;
	std::cout << intmath.modulo(11, 2) << std::endl;

	FloatMath floatmath;
	std::cout << floatmath.divide(11, 2) << std::endl;
	std::cout << floatmath.modulo(11, 2) << std::endl;

}

