#include<iostream>
#include <any>
#include<string>
#include <typeinfo>
//from Cpp 17, comes std::any, which is container for single values of any type
// it works in runtime, aka, variable type can change during program running
// it is a type safer version of *void
// void* is type unsafe in C++(void* represents a memory address without any type information), 



int main()
{
    std::any a = 42;        // a holds an int, but type is std::any
    if (a.type() == typeid(int)) {//std::any is type-erased, need to cast to a concrete type before printing.
        std::cout << std::any_cast<int>(a) << '\n';
    } else if (a.type() == typeid(double)) {
        std::cout << std::any_cast<double>(a) << '\n';
    } else if (a.type() == typeid(std::string)) {
        std::cout << std::any_cast<std::string>(a) << '\n';
    } else {
        std::cout << "unsupported type\n";
    }


    a = std::string{"hi"};  // ok, a holds a string now
    if (a.type() == typeid(int)) {
        std::cout << std::any_cast<int>(a) << '\n';
    } else if (a.type() == typeid(double)) {
        std::cout << std::any_cast<double>(a) << '\n';
    } else if (a.type() == typeid(std::string)) {
        std::cout << std::any_cast<std::string>(a) << '\n';
    } else {
        std::cout << "unsupported type\n";
    }
    


    auto b =42; //auto is compile time defined type, cannot be changed in runtime
    //b = std::string{"hi"};  // error, b is an int, cannot hold a string
    return 0;
}


//g++ -std=c++20 .\MordernCpp_Any.cpp -o .\MordernCpp_Any.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Any.exe }
