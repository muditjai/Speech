#include "stdafx.h"
#include<vector>
#include<algorithm>
#include<thread>
#include<iostream>
#include<future>
#include<numeric>

using std::cout;
using std::endl;
using std::vector;
using std::future;
using std::async;

template <typename T>
T addParallel(vector<T> input)
{   
    size_t min_block_size = 5;

    if (input.size() < min_block_size)
    {
        return std::accumulate(input.begin(), input.end(), T());
    }

    int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0)
    {
        num_threads = 2;
    }

    num_threads = std::min(num_threads, static_cast<int>(input.size() / min_block_size));
    //num_threads = 0;

    size_t actual_block_size = input.size() / num_threads;

    cout << "Actual block size " << actual_block_size << " Input size " << input.size() << " num_threads " << num_threads << endl;

    vector<future<T>> results;
    
    vector<T>::iterator start = input.begin();
    vector<T>::iterator end = start;
    for (int i = 0; i < num_threads; i++)
    {
        end = start + actual_block_size;
        
        results.push_back(std::async(std::launch::async, [start, end] {return std::accumulate(start, end, T()); }));
        start = end;
    }
    if (end != input.end())
    {
        //main thread completes remainining work. 
        end = input.end();
        results.push_back(std::async(std::launch::async, [start, end] {return std::accumulate(start, end, T()); }));
    }

    T result = std::accumulate(results.begin(), results.end(), T(), [](T left, future<T>& right) {return left + right.get(); });
    return result;
}

template int addParallel(vector<int> input);
