#include <cmath>
#include <iostream>

namespace mylib {

template<typename Derived>
struct Vector {

    Vector() {}

    auto operator+(const Derived& other) const noexcept {
        auto& self = *static_cast<const Derived*>(this);

        if constexpr(requires{self.z;}) {
            return Derived {self.x + other.x, self.y + other.y, self.z + other.z};
        } else {
            return Derived {self.x + other.x, self.y + other.y};
        }
    }

    friend auto norm(const Derived& self) noexcept {
        auto norm_sq = self.x * self.x + self.y * self.y;
        if constexpr(requires{self.z;}) {
            norm_sq += self.z * self.z;
        }
        return std::sqrt(norm_sq);
    }

    auto norm() const noexcept {
        auto& self = *static_cast<const Derived*>(this);
        auto norm_sq = self.x * self.x + self.y * self.y;
        if constexpr(requires{self.z;}) {
            norm_sq += self.z * self.z;
        }
        return std::sqrt(norm_sq);
    }
};

struct Vector2f : Vector<Vector2f> {
    float x;
    float y;

    Vector2f(float x, float y) :
        Vector<Vector2f>(),
        x{x},
        y{y}
    {}

};

struct Vector3i : Vector<Vector3i> {
    int x;
    int y;
    int z;

    Vector3i(int x, int y, int z) :
        Vector<Vector3i>(),
        x{x},
        y{y},
        z{z}
    {}

};

} // mylib

int main() {

    mylib::Vector2f v1{1, 0};
    mylib::Vector2f v2{0, 1};
    mylib::Vector2f v3 = v1 + v2;
    std::cout << v3.norm() << std::endl;
    std::cout << norm(v3) << std::endl;

    mylib::Vector3i v4{1, 0, 0};
    mylib::Vector3i v5{0, 1, 1};
    mylib::Vector3i v6 = v4 + v5;
    std::cout << v6.norm() << std::endl;
    std::cout << norm(v6) << std::endl;

}
