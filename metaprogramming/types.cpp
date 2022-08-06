#include <iostream>
#include <type_traits>

template<typename T>
T add(T x,T y) {
    // C++11
    auto v11 = std::is_floating_point<T>();
    // C++17
    auto v17 = std::is_floating_point_v<T>;
    std::cout << v11.value << " " << v17 << std::endl;
    return x + y;
}

template<typename T>
    requires std::integral<T>
T add_integral(T x,T y)
{
    return x + y;
}

int main()
{
    auto res_float = add(4.0, 5.0);
    auto res_int = add(4, 5);
    auto res_int_concept = add_integral(4, 5);
    // doesn't compile
    // auto res_float_concept = add_integral(4.0, 5.0);
}
