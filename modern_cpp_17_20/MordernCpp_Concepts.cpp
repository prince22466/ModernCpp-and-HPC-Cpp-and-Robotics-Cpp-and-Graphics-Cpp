#include <concepts>
#include<string>
#include <iostream>
#include<vector>
//from Cpp 20, comes concepts, 
// simplify SFINAE, which put template constraints, more readable
// most important : Compile-time human-readable error message

template<typename T>
concept addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};


template<typename T>
concept printable = requires(T a, std::ostream& os) {
    { os << a } -> std::same_as<std::ostream&>;
};


template<typename T>
    requires addable<T> && printable<T>// the func needs to meet both concepts
void add_and_print(T a, T b) {
    T result = a + b;
    std::cout << result << std::endl;
}


int main()
{
    add_and_print(3, 4); // works

    add_and_print(std::string("Hello, "), std::string("World!")); // works

    add_and_print(3.5, 4.5); // works

    auto v1=std::vector<int>{1,2,3};
    auto v2 = std::vector<int>{4,5,6};
    add_and_print(v1, v2); // compile error, which clearly says requirements no met

    return 0;
}


//g++ -std=c++20 .\MordernCpp_Concepts.cpp -o .\MordernCpp_Concepts.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Concepts.exe }
