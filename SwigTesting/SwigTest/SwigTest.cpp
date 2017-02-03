// SwigTest.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

#include "SwigTest.h"
int add(int a, int b)
{
    return a + b;
}
/*
SigmoidNode::SigmoidNode() :m_sigmoidResult(0)
{

}

double SigmoidNode::doForwardProp(double input)
{
    this->m_sigmoidResult = 1.0 / (1 + exp(-input));
    return this->m_sigmoidResult;
}

double SigmoidNode::doBackProp(double globalGradient)
{
    return this->m_sigmoidResult * (1 - this->m_sigmoidResult) * globalGradient;
}

int main(int argc, char* argv[])
{
    SigmoidNode n;
    std::cout << n.doForwardProp(0) << std::endl;
    std::cout << n.doBackProp(1) << std::endl;
}

*/

int main()
{
    return 0;
}