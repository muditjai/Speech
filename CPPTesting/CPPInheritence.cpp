// CPPInheritence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Base {
public:
    virtual void virtPublicBase() { cout << "Virtual public base" << endl; }
protected:
    virtual void virtProtectedBase() { cout << "Virtual protected base" << endl; }
};

class Derived : public Base
{
    protected:
    virtual void virtPublicBase() { cout << "Virtual public Derived" << endl; }
};
int main()
{
    Base* b = new Derived();
    b->virtPublicBase();
    
    Derived* d = new Derived();
    //d->virtPublicBase();

    int a;
    cin >> a;

    delete b;
    return 0;
    
}

