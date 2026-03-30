
// from Cpp 17, inline variable comes, 
// it allows to define a variable in .h(header file) without violating ODR, and it can be used in multiple translation units.
// which means any file that has #include "config.h" can use MyConfig::version and MyConfig::access_count as below
// in .h file
/*
struct MyConfig {
   // use inline in .h
    inline static const std::string version = "1.0.0";

    // also works wor non const static
    inline static int access_count = 0;
};
*/

// before C++17, it was done by declaring variable in .h,
// and then defining it in .cpp, which is more verbose and error-prone, and also not thread-safe for non const static variable.

int main()
{
    return 0;
}


//g++ -std=c++20 .\MordernCpp_InlineVariable.cpp -o .\MordernCpp_InlineVariable.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_InlineVariable.exe }
