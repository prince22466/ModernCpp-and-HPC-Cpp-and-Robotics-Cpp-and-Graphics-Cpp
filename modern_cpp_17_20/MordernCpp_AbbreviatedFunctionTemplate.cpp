#include<compare>
#include<iostream>
//from Cpp 20, comes Abbreviated Function Template,
// usage of 'auto' on steriods
// big change on template writing

namespace{
    auto get_sum(auto a, auto b) {//compiler will generate the template for this
        return a + b;
    }

    template <typename T>
    concept concept1 = std::is_integral_v<T> || std::is_floating_point_v<T>;
    
    template<typename T>
    concept concept2 = std::is_floating_point_v<T>;

    auto get_sum2(concept1 auto a, concept2 auto b) {// work together with concepts
        return a + b;
    }
}

int main()
{
    std::cout << "Sum: " << get_sum(6, 8) << std::endl; // 14
    std::cout << "Sum: " << get_sum(6, 8.8) << std::endl; //14.8
    //std::cout << "Sum2: " << get_sum2(6, 8) << std::endl; // compiler error
    std::cout << "Sum2: " << get_sum2(6, 8.8) << std::endl; // 14.8

    return 0;
}


//g++ -std=c++20 .\MordernCpp_AbbreviatedFunctionTemplate.cpp -o .\MordernCpp_AbbreviatedFunctionTemplate.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_AbbreviatedFunctionTemplate.exe }
