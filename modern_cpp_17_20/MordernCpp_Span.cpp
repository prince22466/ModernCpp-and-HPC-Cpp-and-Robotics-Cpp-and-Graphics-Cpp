#include <span>
#include <iostream>
#include<vector>
//from Cpp 20, comes std::span, which is like the vector(c-array, std::array) version of string_view
// it only works with contiguous memory objects(vector, arrays)
// not owning object itself,
// do not manage memory
// its initialization and destruction dont effect the underlying data
// very lightweight, good for performance
// it provides interface for vector, array, c-array, no need to write 3 functions 


//old way to process data
void process_data(std::vector<int> &data)
{
    for(auto &e : data)
    {
        std::cout<< e * 2<<" ";
    }
}

void process_data(const int* data, std::size_t size) //c-style array
{
    for(std::size_t i = 0; i < size; ++i)
    {
        std::cout<< data[i] * 2<<" ";
    }
    std::cout<<std::endl;
}

void process_data(std::array<int,5> &data)
{   
    for(auto &e : data)
    {
        std::cout<< e * 2<<" ";
    }
}


//the span way, much easier
void process_data_span(std::span<int> data)
{
    for(auto &e : data)
    {
        std::cout<< e * 2<<" ";
    }
    std::cout<<std::endl;
}



int main()
{   
    std::vector<int> v1 {1, 2, 3, 4, 5};
    std::array<int,5> a1 {1, 2, 3, 4, 5};
    int c_array[5] = {1, 2, 3, 4, 5};
    process_data(v1);
    process_data(a1);
    process_data(c_array,5);


    process_data_span(v1);
    process_data_span(a1);
    process_data_span(c_array);

    return 0;
}


//g++ -std=c++20 .\MordernCpp_Span.cpp -o .\MordernCpp_Span.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_Span.exe }
