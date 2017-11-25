// MultiThreading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <thread>
#include<iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>

using std::cout;
using std::endl;
using std::vector;
using std::chrono::system_clock;
using std::chrono::time_point; 
using std::chrono::duration_cast;
using std::chrono::milliseconds;

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

void getResultAndTime(vector<int>& input)
{
    time_point<system_clock> start, end;
    start = system_clock::now();
    int result = addParallel<int>(input);
    end = system_clock::now();

    std::cout << "Parallel Time taken " << duration_cast<milliseconds>(end - start).count() << std::endl;
    std::cout << "Parallel add " << result << std::endl;

    start = system_clock::now();
    result = std::accumulate(input.begin(), input.end(), 0);
    end = system_clock::now();

    std::cout << "Serial Time taken " << duration_cast<milliseconds>(end - start).count() << std::endl;
    std::cout << "Serial add " << result << std::endl;


}

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

    getResultAndTime(input);
    cout << endl;

    input.resize(0);
    int total_elem = 1e8;
    input.resize(total_elem);
    std::iota(input.begin(), input.end(), 0);
    getResultAndTime(input);
    return 0;
}

