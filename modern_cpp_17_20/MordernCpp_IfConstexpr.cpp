
#include<cmath>
#include<iostream>

//from Cpp 17, comes if constexpr, a compile-time condition
// it is simple version of SFINAE(Substitution Failure Is Not An Error) for metaprogramming
// at compile time, it evaluates conditions and then it eleminates the code that will not work in runtime
// its syntax is easier than SFINAE, and complier faster
// SFINAE can work in more scenarios, but it is more complex and harder to read


class Circle
{
public:
    void drawCircle() {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Rectangle
{
public:
    void drawRectangle() {
        std::cout << "Drawing a Rectangle" << std::endl;
    }
};

class Square
{
public:
    void drawSquare() {
        std::cout << "Drawing a Square" << std::endl;
    }
};


template <typename Shape>
void drawShape(Shape& shape) {//when compiling,
    if constexpr (std::is_same_v<Shape, Circle>) {
        shape.drawCircle();
    } else if constexpr (std::is_same_v<Shape, Rectangle>) {
        shape.drawRectangle();
    } else {
        static_assert(false, "Unsupported shape");//compile-time check, may give compile error
    }
}



/// another example ///
template <typename T>
void process1(T value) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "square of integar:" << value * value << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "square root of float: " << std::sqrt(value) << std::endl;
    } else {
        std::cout << "non numeric" << std::endl;
    }
}


// template <typename T>
// void process2(T value) {
//     if (std::is_integral_v<T>) {// using if, it gives compile error
//         std::cout << "square of integar:" << value * value << std::endl;
//     } else if constexpr (std::is_floating_point_v<T>) {
//         std::cout << "square root of float: " << std::sqrt(value) << std::endl;
//     } else {
//         std::cout << "non numeric" << std::endl;
//     }
// }




int main()
{
    process1(5); // 输出：整数的平方：25
    process1(3.14); // 输出：浮点数的平方根：1.77245
    process1("hello"); // 输出：非整数类型

    //process2("hello"); // process2 gives compile error

    Rectangle re;
    drawShape(re);

    //Square sq;  
    //drawShape(sq); // static_assert gives a compile failure   
    return 0;
}


//g++ -std=c++20 .\MordernCpp_IfConstexpr.cpp -o .\MordernCpp_IfConstexpr.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_IfConstexpr.exe }
