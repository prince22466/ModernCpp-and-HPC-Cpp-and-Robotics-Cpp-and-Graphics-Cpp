#include<iostream>
#include <any>
#include<string>
#include <typeinfo>
//from Cpp 17, comes fold expression, 

template<typename... Args>
std::string concatenate(Args&&... args) {
    return (std::string{} + ... + std::forward<Args>(args));//concatenate all the arguments into a single string
}

//similar function can be used 
//1. to calculate the sum of several numbers,
//2. call multiple functions
//3. initiate multiple objects
//4. lock multiple mutexes
//5. release multiple mutexes
// etc
int main()
{
    std::cout<< concatenate('a', "bc", " ",std::string("def"))<<std::endl;//"abcdef"

    return 0;
}


//g++ -std=c++20 .\MordernCpp_FoldExpression.cpp -o .\MordernCpp_FoldExpression.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_FoldExpression.exe }
