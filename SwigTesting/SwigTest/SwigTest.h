#include "cmath"
#include <iostream>

class SigmoidNodeClass
{
    double m_sigmoidResult;
public:
    SigmoidNodeClass();

    double doForwardProp(double input);

    double doBackProp(double globalGradient);

};


extern int add(int a, int b);