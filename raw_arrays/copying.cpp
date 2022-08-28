#include <iostream>

template<typename Numeric>
void print(const int size, const Numeric* const a)
{
    auto aptr = a;
    while (aptr != a + size){
        std::cout << *aptr << std::endl;
        aptr++;
    }
}

template<typename Numeric>
void ones(const int size, Numeric* a){
    auto aptr = a;
    while (aptr != a + size){
        (*aptr) = static_cast<Numeric>(1);
        aptr++;
    }

}

int main(){

    int size = 10;
    double* a = new double[size];
    std::cout << "making a\n";
    print(size, a);
    ones(size, a);
    print(size, a);
    std::cout << "\n\n";

    std::cout << "making b\n";
    double* b = new double[size];
    print(size, b);
    std::copy(a, a+size, b);
    print(size, b);
    delete [] a;
    delete [] b;
}
