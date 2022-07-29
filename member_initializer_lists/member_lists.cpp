#include <iostream>

template<typename T>
struct Point3D {
    T x, y, z;

    Point3D(T, T, T);
    Point3D(): x((T)0), y((T)0), z((T)0) {};

    void print_point();
};

template<typename T>
Point3D<T>::Point3D(T x, T y, T z): x{x}, y{y}, z{z} {}

template<typename T>
void Point3D<T>::print_point() {
    std::cout << x << " " << y << " " << z << std::endl;
}

template<typename T>
struct ExplicitPoint3D {
    T x, y, z;

    explicit ExplicitPoint3D(T, T, T);
    explicit ExplicitPoint3D(): x((T)0), y((T)0), z((T)0) {};

    void print_point();
};

template<typename T>
ExplicitPoint3D<T>::ExplicitPoint3D(T x, T y, T z): x{x}, y{y}, z{z} {}

template<typename T>
void ExplicitPoint3D<T>::print_point() {
    std::cout << x << " " << y << " " << z << std::endl;
}

int main(){

    /*
    auto int_point = Point3D<int>(3, 4, 5);
    auto float_point = Point3D<float>(4, 6, 9);

    std::cout << "My int_point\n";
    int_point.print_point();
    std::cout << "\n\nMy float_point\n";
    float_point.print_point();

    auto zero_int_point = Point3D<int>();
    auto zero_float_point = Point3D<float>();

    std::cout << "\n\nMy zero_int_point\n";
    zero_int_point.print_point();
    std::cout << "\n\nMy zero_float_point\n";
    zero_float_point.print_point();
    */

    /* copy-list-initialization
    Point3D<int> int_point = {3, 4, 5};
    Point3D<float> float_point = {4, 6, 9};

    std::cout << "My int_point\n";
    int_point.print_point();
    std::cout << "\n\nMy float_point\n";
    float_point.print_point();
    */

    /* Explicit construction example
    ExplicitPoint3D<int> int_point = (ExplicitPoint3D<int>){3, 4, 5};
    ExplicitPoint3D<float> float_point = (ExplicitPoint3D<float>){4, 6, 9};

    std::cout << "My int_point\n";
    int_point.print_point();
    std::cout << "\n\nMy float_point\n";
    float_point.print_point();
    */

    ExplicitPoint3D<int> int_point{3, 4, 5};
    ExplicitPoint3D<float> float_point{4, 6, 9};

    std::cout << "My int_point\n";
    int_point.print_point();
    std::cout << "\n\nMy float_point\n";
    float_point.print_point();
    return 0;
}
