#include<iostream>
#include <execution>
#include <vector>
#include <algorithm>
#include<chrono>
// from Cpp 17, comes std::execution, it aims to make parrel algorithms easier to write and more efficient. 
// It provides 3 execution policies,
// execution::seq(sequential), execution::par(parallel), execution::par_unseq(parallel and vectorized).
// execution works with below algo
// std::for_each
// std::transform
// std::sort
// std::find
// std::count
// std::reduce
// std::exclusive_scan
// std::inclusive_scan
// usage in data process, graphic programming, hpc, etc


int main()
{
    std::vector<int> vec(300000000); // large enough to show the multithread effect
    std::iota(vec.begin(), vec.end(), 0); // fill with 0,1,2,...,999999
    std::vector<int> result1(vec.size());
    std::vector<int> result2(vec.size());
    std::vector<int> result3(vec.size());

    auto lambda = [](int x) {return  x = 2 + x + 0.01; };

    // sequential execution, and time being consumed
    auto start = std::chrono::steady_clock::now();
    std::transform(std::execution::seq, vec.begin(), vec.end(), result1.begin(),
                    lambda);
    auto end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;



    // parallel execution
    start = std::chrono::steady_clock::now();
    std::transform(std::execution::par, vec.begin(), vec.end(), result2.begin(),
                    lambda);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;


    // parallel and vectorized execution
    start = std::chrono::steady_clock::now();
    std::transform(std::execution::par_unseq, vec.begin(), vec.end(), result3.begin(),
                    lambda);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;


    return 0;
}


//g++ -std=c++20 .\MordernCpp_Execution.cpp -o .\MordernCpp_Execution.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Execution.exe }
