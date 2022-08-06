#include <cmath>
#include <iostream>
#include <type_traits>

template<typename T>
struct Point2D
{
    T x,y;

    auto norm() {return std::sqrt(x*x + y*y);}
};

int main()
{
    int i = 0;
    std::cout << std::is_same_v<decltype(i), int> << std::endl;

    auto point_int = Point2D<int>{1,2};
    auto point_float = Point2D<float>{1,2};
    std::cout << std::is_same_v<decltype(point_int.x), int> << std::endl;
    std::cout << std::is_same_v<decltype(point_float.x), int> << std::endl;
    std::cout << point_int.norm() << " " << point_float.norm() << std::endl;
}
