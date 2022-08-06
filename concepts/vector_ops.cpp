#include <type_traits>
#include <concepts>

template<class Vec>
concept Scalar = std::decay<decltype(Vec()[0])>::type;

template<typename T>
concept Euclidean = std::is_floating_point_v<T>;


template<typename T>
    requires Euclidean<T>
T norm(


template<typename Numeric>
struct Point2D
{
    Numeric x, y;

    Numeric
}
