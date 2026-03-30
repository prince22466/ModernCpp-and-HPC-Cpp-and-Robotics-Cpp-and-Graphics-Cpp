
//from Cpp 20, comes Designated Initializers,
// better, convinient way to initialize struct, class, or union
// it can initialize only part of the members, and the rest will be initialized to default value
// no need for sequence, can initialize in any order, and can skip some members
// support embedded initializers

struct Point
{
    int x;
    int y;
    int z;
};

struct Rectangle
{
    double a;
    double b;
    Point p1;
};

struct Combine
{
    int a;
    double b;
    Point p1;
    Rectangle r1;
};


int main()
{
    //partial initialization
    Point p1{ .x = 10, .z = 20 }; // y will be initialized to 0

    //full initialization, with embedded initializer
    Rectangle r1{ .a = 5.0, .b = 10.0, .p1 = { .x = 1, .y = 2, .z = 3 } };

    //partial initialization, with embedded initializer
    Combine c1{ .a = 10, .p1 = { .x = 1, } }; // b will be initialized to 0.0, p1 parital initialized
                                              //r1 will be initialized to default values

    return 0;
}


//g++ -std=c++20 .\MordernCpp_DesignatedInitializers.cpp -o .\MordernCpp_DesignatedInitializers.exe; if ($LASTEXITCODE -eq 0) { .\MordernCpp_DesignatedInitializers.exe }
