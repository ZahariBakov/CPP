#include <iostream>
#include <memory>

int main() {
    const int size = 2;
    std::unique_ptr<int[]> arr1D;
    arr1D.reset(new int [size] {});

    std::unique_ptr<std::unique_ptr<int[]>[]> arr2D;
    arr2D.reset(new std::unique_ptr<int[]>[size]);

    for (int i = 0; i < size; ++i) {
        const int innerSize = 5;
        arr2D[i].reset(new int[innerSize]);

        for (int j = 0; j < innerSize; ++j) {
            arr2D[i][j] = j;
            std::cout << arr2D[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
