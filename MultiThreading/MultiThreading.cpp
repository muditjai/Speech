// MultiThreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include<iostream>
int worker()
{
    std::cout << "print from thread";
    return 1;
}
int main()
{
    std::thread t(worker);
    t.join();
    return 0;
}

