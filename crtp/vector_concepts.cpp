#include <concepts>
#include <cmath>
#include <iostream>

namespace mylib {

template<typename T>
inline constexpr bool is_vector = false;

template<typename T>
concept vector2d = requires(T vec){
    {vec.x};
    {vec.y};
};

template<typename T>
concept vector3d = requires(T vec){
    {vec.x};
    {vec.y};
    {vec.z};
};

template<typename T>
concept vector = is_vector<T> && (vector2d<T> || vector3d<T>);

template<vector Vector>
auto operator+(const Vector& self, const Vector& other) noexcept {
    if constexpr(requires{self.z;}) {
        return Vector {self.x + other.x, self.y + other.y, self.z + other.z};
    } else {
        return Vector {self.x + other.x, self.y + other.y};
    }
}

auto norm(const vector auto& self) noexcept {
    auto norm_sq = self.x * self.x + self.y * self.y;
    if constexpr(requires{self.z;}) {
        norm_sq += self.z * self.z;
    }
    return std::sqrt(norm_sq);
}

struct Vector2f {
    float x;
    float y;
};

struct Vector3i {
    int x;
    int y;
    int z;
};

template<> inline constexpr bool is_vector<Vector2f> = true;
template<> inline constexpr bool is_vector<Vector3i> = true;

} // mylib

#define IMPORT_VECTOR_FUNCTIONS() \
    using ::mylib::norm; \
    using ::mylib::operator+

namespace userlib {
struct Vector3f {float x, y, z;};
IMPORT_VECTOR_FUNCTIONS();
}

template<> inline constexpr bool mylib::is_vector<userlib::Vector3f> = true;

int main() {

    mylib::Vector2f v1{1, 0};
    mylib::Vector2f v2{0, 1};
    mylib::Vector2f v3 = v1 + v2;
    std::cout << norm(v3) << std::endl;

    mylib::Vector3i v4{1, 0, 0};
    mylib::Vector3i v5{0, 1, 1};
    mylib::Vector3i v6 = v4 + v5;
    std::cout << norm(v6) << std::endl;

    userlib::Vector3f v7{1, 0, 1};
    std::cout << norm(v7) << std::endl;
    auto v8 = v7 + v7;
    std::cout << norm(v8) << std::endl;
}
