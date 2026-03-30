#include<iostream>
#include<optional>
#include<string>
//from Cpp 17, comes std::optional
// std::optional is a wrapper that contains either a value or nothing (std::nullopt).
// very useful as a return value of funtions that may fail or may not return a value, 
// instead of returning a pointer or throwing an exception, we can return an std::optional

std::optional<std::string> get_string(bool return_value)
{
    if (return_value)
        return "get_string ";
    else
        return std::nullopt; // or simply return {}; 
}

int main()
{
    std::optional<std::string> s_novalue;
    std::optional<std::string> s("string value");
    std::cout<< s.value_or("empty") << std::endl; // print string value
    std::cout<< s_novalue.value_or("empty") << std::endl; // print empty

    std::cout<< get_string(1).value_or("empty") << std::endl; // print get_string
    std::cout<<get_string(0).value_or("empty") << std::endl; // print empty
    return 0;
}


//g++ -std=c++20 .\MordernCpp_Optional.cpp -o .\MordernCpp_Optional.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Optional.exe }
