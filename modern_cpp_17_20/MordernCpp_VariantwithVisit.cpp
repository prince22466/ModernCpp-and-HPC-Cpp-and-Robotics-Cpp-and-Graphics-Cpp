#include<iostream>
#include <variant>
#include<string>
//from Cpp 17, comes std::variant, which works greatly with std::visit
// std::variant is to replace union and *void, but type safe, 
// and it can hold any type of data, but only one type after compile-time
// std::visit is to take the value of variant and check its type
// std::visit can take a callable object, such as lambda, and apply it to a variant object


struct OperationOverload
{
    void operator()(int i) const
    {
        std::cout << "int: " << i << std::endl;
    }
    void operator()(double d) const
    {
        std::cout << "double: " << d << std::endl;
    }
    void operator()(const std::string& s) const
    {
        std::cout << "string: " << s << std::endl;
    }

};

int main()
{
    std::variant<int, double, std::string> var1,var2,var3;
    var1 = 42;
    std::visit(OperationOverload(), var1);

    var2 = 12.1;
    std::visit(OperationOverload(), var2);

    var3 = "nowstring";
    std::visit(OperationOverload(), var3);


    ///using callable lambda for compile time type check
    /// togehter with if constexpr
    auto lambda = [](auto&& arg)
    {
        using T = std::decay_t<decltype(arg)>;//decltype(arg): get the exact type of arg
                                              // std::decay_t<...>: clean it into a “plain” type
                                              //(removes references
                                              //removes const/volatile
                                              //converts arrays/functions to pointer forms)
                                              // const std::string& will be std::string
        if constexpr (std::is_same_v<T, int>)
        {
            std::cout << "int: " << arg << std::endl;
        }
        else if constexpr (std::is_same_v<T, double>)
        {
            std::cout << "double: " << arg << std::endl;
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            std::cout << "string: " << arg << std::endl;
        }
    };

    std::visit(lambda, var1);
    std::visit(lambda, var2);
    std::visit(lambda, var3);
    return 0;
}


//g++ -std=c++20 .\MordernCpp_VariantwithVisit.cpp -o .\MordernCpp_VariantwithVisit.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_VariantwithVisit.exe }
