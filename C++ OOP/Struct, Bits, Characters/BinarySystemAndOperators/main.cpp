#include <iostream>

int main() {

    // binary numbers
    0000  -> 0
    0001  -> 1
    0010  -> 2
    0011  -> 3
    0100  -> 4
    ...
    1111  -> 15



    // decimal to binary conversion
    234 -> binary?
    234 / 2 = 117
                        234 % 2  = 0
    117 / 2  = 58
                        117 % 2 = 1
    58 / 2 = 29
                        58 % 2 =  0
     29 / 2 = 14
                        29 % 2 = 1
    14 / 2  = 7
                        14 % 2 = 0
     7 / 2 = 3
                        7 % 2 = 1
    3 / 2  = 1
                        3 % 2 = 1
     1 / 2 = 0
                        1 % 2 = 1

    11101010  // starting from the last reminder up to the first


    // binary to decimal conversion
    11101010  -> dec?

    7  6  5  4  3  2  1  0
    1  1  1  0  1  0  1  0
                        0 * 2^0 =  0
                      1 * 2^1   =  2
                   0 * 2^2      =  0
                 1 * 2^3        =  8
              0 * 2^4           =  0
           1 * 2^5              =  32
        1 * 2^6                =  64
    1 * 2^7                    = 128

    0 + 2 + 0 + 8 + 0 + 32  + 64 + 128 =  234

    // binary operators
    &  - bitwise AND
    |  - bitwise OR
    ^  - bitwise XOR
    << - left shift
    >> - right shift
    ~ - bitwise NOT

    // binary operations table
    X     Y      X & Y     X | Y    X ^ Y
    0     0      0          0         0
    0     1      0          1         1
    1     0      0          1         1
    1     1      1          1         0

    // Examples:
    number1 & number2
    1  1  1  0  1  0  1  0   // 234
    0  0  0  1  1  1  0  1   // 29
    ==========================
     0  0  0  0  1  0  0  0   // 8


    1  1  1  0  1  0  1  0  // 234
    number1 << 1
    1  1  0  1  0  1  0  0
    n >> 1
    0 1 1 0 1 0 1 0

    11111111   // 255
    11111011   // 251
    01000001   // 65

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
