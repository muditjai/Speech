// SwigTest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "SwigTest.h"
int add(int a, int b)
{
    return a + b;
}

SigmoidNodeClass::SigmoidNodeClass() :m_sigmoidResult(0)
{

}

double SigmoidNodeClass::doForwardProp(double input)
{
    this->m_sigmoidResult = 1.0 / (1 + exp(-input));
    return this->m_sigmoidResult;
}

double SigmoidNodeClass::doBackProp(double globalGradient)
{
    return this->m_sigmoidResult * (1 - this->m_sigmoidResult) * globalGradient;
}
