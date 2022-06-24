#include <iostream>
#include <vector>
#include <string>
#include <map>

int main()
{
    auto vec = std::vector<double>(10);
    for (const auto& item : vec) {
        std::cout << item << std::endl;
    }
    double i = 0;
    for (auto& item : vec) {
        item = i;
        i += 1;
        std::cout << item << std::endl;
    }
    std::cout << std::endl;

    auto my_map = std::map<std::string, int>{};
    my_map["dog"] = 1;
    my_map["cat"] = 2;
    my_map["fish"] = 3;
    for (auto&& [key, value] : my_map) {
        std::cout << key << " " << value << std::endl;
    }

    return 0;
}
