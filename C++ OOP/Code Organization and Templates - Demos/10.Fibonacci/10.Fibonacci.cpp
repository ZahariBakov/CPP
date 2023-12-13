#include <iostream>
#include <cstddef>

//int fibonacci(int fibNum) {
//    if (fibNum == 0 || fibNum == 1) {
//        return 1;
//    }
//
//    return fibonacci(fibNum - 2) + fibonacci(fibNum - 1);
//}

template<size_t N>
struct Fibonacci {
    enum : size_t {
        value = Fibonacci<N - 2>::value + Fibonacci<N - 1>::value
    };
};

template<>
struct Fibonacci<1> {
    enum : size_t {
        value = 1
    };
};

template<>
struct Fibonacci<0> {
    enum : size_t {
        value = 1
    };
};

int main() {
    //const int fib = fibonacci(42);
    const size_t fib = Fibonacci<52>::value;

    std::cout << fib << std::endl;


    return 0;
}
