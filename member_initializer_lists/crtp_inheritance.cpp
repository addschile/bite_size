#include <iostream>

template<typename Derived>
struct Base {
    int n;
    Base(int n) : n{n} {};
    void print() {
        std::cout << n << " ";
        this->print_impl();
    }

    virtual void print_impl() {}
};

template<typename T>
struct Derived : public Base<Derived<T>> {
    T x;
    T y;

    Derived(T n) :
        Base<Derived<T>>(n),
        x{2*n},
        y{3*n}
    {}

    void print_impl(){
        std::cout << x << " " << y << " " << std::endl;
    }
};

int main() {

    Derived<int> my_derived{4};
    my_derived.print();
    return 0;
}
