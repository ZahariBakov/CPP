#include <iostream>

void findSeat(int* seats) {
    for (int i = 0; i < 10; ++i) {
        int currSeat;
        std::cout << "Witch seat you want? ";
        std::cin >> currSeat;

        if (seats[currSeat - 1] == 0) {
            seats[currSeat - 1] = 1;
            std::cout << "Your seat is " << currSeat << std::endl;
        }
        else {
            for (int i = 0; i < 10; ++i) {
                if (seats[i] == 0) {
                    seats[i] = 1;
                    std::cout << "Your seat is " << i + 1 << std::endl;
                    break;
                }
            }
        }
    }
}

int main() {
    int seats[10] {};

    findSeat(seats);

    for (int i = 0; i < 10; ++i) {
        std::cout << seats[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
