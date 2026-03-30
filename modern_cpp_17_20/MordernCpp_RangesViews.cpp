#include <ranges>
#include<algorithm>
#include <iostream>
#include<vector>
//from Cpp 20, comes ranges and views, 
// ranges and views provide pipline-like style to manipulate object(mostly container)
// check "Range adaptors",
// for more methods to manipulate the range, like filter, transform, etc.



int main()
{   
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::vector<int> v1_new;
    // old way to transform data and put into a new vector
    std::copy_if(v1.begin(), v1.end(), std::back_inserter(v1_new), 
                [](int x){ return x % 2 == 0; }); //1st filter elements
    std::transform(v1_new.begin(), v1_new.end(), v1_new.begin(), 
                                [](int x){return x * 2; });//2nd tranform

    for(auto &e :v1_new)
    {
        std::cout<< e<<" ";
    }
    std::cout<<std::endl;


    // with ranges and views, we can do it in a more elegant way
    auto v1_new2 = v1 | std::views::filter([](int x){ return x % 2 == 0; }) //1st filter elements 
                        | std::views::transform([](int x){ return x * 2; }); //2nd tranform
    for(const auto &e :v1_new2)
    {
        std::cout<< e<<" ";
    }
    std::cout<<std::endl;


    // one step of generate data, filter, and transform and take the first 3 elements
    auto numbers = std::views::iota(1,1000) // generate numbers from 1000 to infinity
                    | std::views::filter([](int x){ return x % 2 == 0; }) // filter even numbers
                    | std::views::transform([](int x){ return x * 2; }) // transform to double
                    | std::views::take(3); // take the first 3 elements
    
    for(const auto &e :numbers)
    {
        std::cout<< e<<" ";
    }
    std::cout<<std::endl;
    return 0;
}


//g++ -std=c++20 .\MordernCpp_RangesViews.cpp -o .\MordernCpp_RangesViews.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_RangesViews.exe }
