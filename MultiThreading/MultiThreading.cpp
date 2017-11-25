// MultiThreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include<iostream>
#include <vector>
#include <algorithm>

using std::vector;

class thread_guard
{
    std::thread m_t;
public:
    thread_guard(thread_guard const&) = delete;
    thread_guard& operator=(thread_guard const&) = delete;

    thread_guard(std::thread& t):m_t(std::move(t))
    {
        
    }
    
    ~thread_guard()
    {
        if (m_t.joinable())
        {
            m_t.join();
        }
    }

};

int genArg(int i)
{
    std::cout << i << " genArg thread " << std::this_thread::get_id() << std::endl;
    return 1;
}

int worker(int j)
{
    std::cout << "worker thread" << std::this_thread::get_id() << std::endl;
    for (int i = 0; i < 10; i++)
    {
        std::cout << "print from thread" << i << std::endl;
    }
    return 1;
}

class ClassWorker
{
public:
    void operator()()
    {        
        for (int i = 0; i < 10; i++)
        std::cout << "printing from classworker" << i << std::endl;
    }
};
using std::mem_fn;
void runMultileThreads()
{
    std::vector<std::thread> threadVec;
    for (int i = 0; i < 10; i++)
    {
        threadVec.push_back(std::thread(genArg, i));
    }

    std::for_each(threadVec.begin(), threadVec.end(), mem_fn(&std::thread::join));
}
template <typename T>
T addParallel(vector<T> input);
template int addParallel(vector<int> input);

int main()
{
    //std::cout << "main thread" << std::this_thread::get_id() << " " << std::thread::hardware_concurrency() << std::endl;
    //std::thread t(worker, genArg());  

    //ClassWorker c;
    //std::thread t1(c);

    //t.join();
    //t1.join();
    
    //runMultileThreads();

    std::vector<int> input{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
    int result = addParallel<int>(input);
    std::cout << "Parallel add " << result << std::endl;
    return 0;
}

