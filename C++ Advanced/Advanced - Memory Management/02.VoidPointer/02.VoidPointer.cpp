#include <iostream>
#include <string>

void print(int n) {
    std::cout << n << std::endl;
}

void processData(void* data, const std::string& dataType) {
    if (dataType == "int") {
        int* internalData = (int*)data;
        std::cout << *internalData << std::endl;
    }
}

int main() {
    int number = 42;
    processData(&number, "int");

    char cStr[] = "I'm a C-String";
    const char* otherCStr = "I'm another C-String";

    int* numberPtr = &number;
    const void* p;

    p = numberPtr;
    std::cout << p << std::endl;

    p = &number;
    std::cout << p << std::endl;

    p = cStr;
    std::cout << cStr << " " << p << std::endl;
    // cStr will be printed as a string, p as an address

    p = otherCStr;
    std::cout << otherCStr << " " << p << std::endl;
    // otherCStr will be printed as a string, p as an address

    return 0;
}
