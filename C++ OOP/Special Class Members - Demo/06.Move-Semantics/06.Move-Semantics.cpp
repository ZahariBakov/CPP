#include <iostream>
#include <vector>
#include <utility>

class VectorWraper {
public:
    VectorWraper(const std::vector<int>& data) : _data(data) {}

    VectorWraper(VectorWraper&& other) : _data(std::move(other._data)) {
        std::cout << "Invoking Move Ctor" << std::endl;
    }

    VectorWraper& operator=(VectorWraper&& other) {
        std::cout << "Invoking Move Assigment operator" << std::endl;

        if (this != &other) {
            _data = std::move(other._data);
        }

        return *this;
    }

    void print() const {
        if (_data.empty()) {
            std::cout << "Data is empty" << std::endl;
        }

        for (const auto elem : _data) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }

    void clearData() {
        _data.clear();
    }

private:
    std::vector<int> _data;
};

int main() {
    const std::vector<int> data = { 1, 2, 3 };
    VectorWraper first(data);
    first.print();

    //compilation error - copy ctor invoked
    //VectorWraper secodn(first);

    VectorWraper second(std::move(first));
    second.print();

    first.clearData();
    first.print();
    first = std::move(second);
    first.print();

    return 0;
}
