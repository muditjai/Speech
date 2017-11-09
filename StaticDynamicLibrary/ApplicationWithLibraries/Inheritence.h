#pragma once
#include<iostream>
#include<memory>
using namespace std;

class Base {
private:
    shared_ptr<Base> m_base;
public:
    Base(int i)
    {
        cout << "Base int i constructor" << endl;
    }
   void  Base1()
    {
        cout << "Base constructor" << endl;
    }

     virtual ~Base()
    {
        cout << "Base destructor" << endl;
    }

    virtual void func()
    {
        cout << "Base func" << endl;
    }
};

class Derived: public Base {

public:
    Derived():Base(0)
    {
        //Base(0);
        cout << "Derived constructor" << endl;
    }

    ~Derived()
    {
        cout << "Derived destructor" << endl;
    }

    virtual void func() override
    {
        cout << "Derived func" << endl;
    }
};

class HasaBase {
private :
    Base b;
    //Base b2;
public:
    HasaBase():b(1)
    {
        cout << "HasaBase constructor" << endl;
        b = 1;
    }
};