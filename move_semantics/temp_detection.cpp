#include <iostream>
#include <string>

std::string getName()
{
    return "Addison";
}

void print(const std::string& str)
{
    std::cout << "lvalue\n";
    std::cout << str << "\n";
}

void print(std::string&& str)
{
    std::cout << "rvalue\n";
    std::cout << str << "\n";
}

int main()
{
    std::string&& name = getName();
    print(name); // lvalue
    print(getName()); // rvalue
}
