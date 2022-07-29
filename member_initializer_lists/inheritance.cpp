#include <iostream>

template<typename T>
struct Base {
    T n;
    Base(T n) : n{n} {};
};

template<typename T>
struct Derived : public Base<T> {
    T x;
    T y;

    Derived(T n) :
        Base<T>(n),
        x{2*n},
        y{3*n}
    {}

    void print(){
        std::cout << this->n << " " << x << " " << y << " " << std::endl;
    }
};

int main() {

    Derived<int> my_derived{4};
    my_derived.print();
    return 0;
}
