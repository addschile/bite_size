#include <iostream>

struct Point {
    Point() {}
    Point(double, double) {}
    explicit Point(int, int) {}
    void print() {std::cout << "hello\n";}
};

struct foo {
    foo() {}
    foo(int) {}
    explicit foo(double);
    foo(int, int) {}
    void print() {std::cout << "hello\n";}
};

template<typename T>
void bar(T x) {
    x.print();
    return;
}

int main() {
    bar<foo>(foo());
    bar<foo>(10);
    bar<foo>(2.0);
    bar<Point>(Point());
    //bar<Point>({10, 10});
    bar<Point>({2.0, 2.0});
    return 0;
}
