#include<vector>
#include <span>
#include <tuple>
#include<string>
#include<map>
#include<iostream>

//from Cpp 17, comes Structured Bindings, it works like python
// it mainly replaces std::get<N>(tuple), std::tie in older Cpp
// it only works if object's structure is known at compile time
// it mainly works with key-value pair, items whose size are know at compile time, static arrays, tuples, structs
// doesnt work with run-time dynamic objects, such as vector, list, 
// it is to read values, not overwrite



int main()
{
    // on tuple
    std::tuple<int, double, std::string> myTuple = {1, 2.2, "example"};
    const auto [x, y, z] = myTuple;// structured bindings, it is to read values, not overwrite
    std::cout << x << ", " << y << ", " << z << std::endl;


    // iterate over map
    //std::map<KeyType, std::tuple<T1, T2, T3>>
    std::map<std::string, std::tuple<int, double, std::string>> myMap;
    myMap["key1"] = {1, 2.2, "example"};
    myMap["key2"] = {3, 4.4, "another example"};
    myMap["key3"] = {5, 6.6, "yet another example"};
    for(auto const [key, value] : myMap)//binding once
    {
        auto const [v1,v2,v3] = value;//binding again
        std::cout << key << ": " << v1 << ", " << v2 << ", " << v3 << std::endl;
    }


    //iterate over vector<vector<int>>, run-time dynamic
    std::vector<std::vector<int>> vec = {{1, 2}, {3, 4}, {5, 6}};
    for(auto const [v1,v2] : vec)// cannot use binding, error
    {
        std::cout << "vector of vector : " << v1 << ", " << v2 << std::endl;
    }
}


//g++ -std=c++20 .\MordernCpp_StructuredBindings.cpp -o .\MordernCpp_StructuredBindings.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_StructuredBindings.exe }
