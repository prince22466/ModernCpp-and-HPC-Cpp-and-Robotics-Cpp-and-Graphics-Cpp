#include<iostream>
#include <string_view>
//from Cpp 17, comes std::string_view
// string_view is light weight std::string
// it only has two has two data, a pointer( point to the string), and size
// so it can only see, and make checking string faster
// and it has several pitfall for bugs, shown below
// 

std::string_view make_view_bad() {
    return std::string("temp"); // temporary value, after return, the temporary value will be destroyed, 
                                //and the string_view will point to a invalid memory address, so it will print nothing
}


void quick_check(std::string_view v) {
    //using string_view for quick check, it is quicker than string
    for(char c : v) {
        if (c == 'a') {
            std::cout << "found a" <<std::endl;
            return;
        }
    }
    std::cout <<"string(view) size "<< v.size() <<std::endl;//
}


int main()
{
    std::cout << make_view_bad() <<std::endl;// print nothing

    auto s = std::string("Non_temp");
    std::string_view v =s ;
    std::cout << v <<std::endl;// print Non_temp
    
    
    quick_check(s);
    quick_check("good a example.");

    return 0;
}


//g++ -std=c++20 .\MordernCpp_StringView.cpp -o .\MordernCpp_StringView.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_StringView.exe }
