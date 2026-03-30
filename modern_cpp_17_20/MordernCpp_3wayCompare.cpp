#include<compare>
#include<iostream>
//from Cpp 20, comes 3way Comparison, <=>
// the result of the 3way comparison is a strong_ordering, weak_ordering, or partial_ordering
// which cannot be converted to bool, or print out 
// but can be compared to 0, or can be used in if statement directly
// and <=> can be overloaded, compare between customized objects

int main()
{
    constexpr auto a = 1;
    constexpr auto b = 1;
    constexpr auto res = a <=> b;
    if constexpr (res == 0)
    {
        std::cout << "a and b are equal" << std::endl;
    }
    else if (res < 0)
    {
        std::cout << "a is less than b" << std::endl;
    }
    else
    {
        std::cout << "a is greater than b" << std::endl;
    }
    return 0;
}


//g++ -std=c++20 .\MordernCpp_3wayCompare.cpp -o .\MordernCpp_3wayCompare.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_3wayCompare.exe }
