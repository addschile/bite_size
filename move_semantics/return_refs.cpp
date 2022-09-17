#include <iostream>
int x;
int& getRef()
{
    return x;
}

const int& getConstRef()
{
    return x;
}

int main(){
    getRef() = 4;
    std::cout << "x is at address " << &x << " with value " << x << "\n";
    getRef() = 6;
    std::cout << "x is at address " << &x << " with value " << x << "\n";

    auto y = getRef(); // copies x into y
    y = 7;
    std::cout << "x is at address " << &x << " with value " << x << "\n";
    std::cout << "y is at address " << &y << " with value " << y << "\n";

    auto& z = getRef(); // copies reference of x to z (they are the same)
    z = 7;
    std::cout << "x is at address " << &x << " with value " << x << "\n";
    std::cout << "z is at address " << &z << " with value " << z << "\n";

    auto& w = getConstRef(); // copies reference of x to w, but it has to be const
    // w = 12; // Error
}
