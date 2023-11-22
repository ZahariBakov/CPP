#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<int> vec1{ 1, 2, 3 };
    std::vector<int> vec2{ 1, 2, 3, 4 };
    std::vector<int> vec3;

    std::vector<std::string> vec4;
    std::vector<std::string> vec5{ "ala", "bala"};

    std::vector<char> vec6;
    std::vector<double> vec7;

    std::cout << sizeof(vec1) << std::endl;
    std::cout << sizeof(vec2) << std::endl;
    std::cout << sizeof(vec3) << std::endl;

    std::cout << sizeof(vec4) << std::endl;
    std::cout << sizeof(vec5) << std::endl;

    std::cout << sizeof(vec6) << std::endl;
    std::cout << sizeof(vec7) << std::endl;

    return 0;
}
