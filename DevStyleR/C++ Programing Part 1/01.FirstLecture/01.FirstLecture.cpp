#include <iostream>

int main() {

    // int  age =35;
    // long distance2 = 32453253646467;

    // float grade = 5.5066f;
    // double distance = 45.67897855465789;

    // int a = 23;
    // int b = 45;

    //   +   -   *   /   &

    /*int c = a + b;

    std::cout << c << std::endl;

    int d = a - b;

    std::cout << d << std::endl;

    int e = a * b;

    std::cout << e << std::endl;

    int f = b / a;

    std::cout << f << std::endl;

    int j = b % a;

    std::cout << j << std::endl;
    std::cout << std::endl;

    int number = 1549;

    int lastNum = number % 10;
    int lastTwo = number % 100;
    int lastThree = number % 1000;

    std::cout << number << std::endl;
    std::cout << lastNum << std::endl;
    std::cout << lastTwo << std::endl;
    std::cout << lastThree << std::endl;

    int firstThree = number / 10;
    int firstTwo = number / 100;
    int firstNum = number / 1000;

    std::cout << std::endl;
    std::cout << firstThree << std::endl;
    std::cout << firstTwo << std::endl;
    std::cout << firstNum << std::endl;

    int last = number / 1 % 10;
    int third = number / 10 % 10;
    int second = number / 100 % 10;
    int first = number / 1000 % 10;

    std::cout << std::endl;
    std::cout << last << std::endl;
    std::cout << third << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;


    std::cout << "First digit is: " << first << " second digit is: " << second << " third digit is: "
        << third << " last " << last << std::endl;*/

        //   >  ,  <  ,  ==  ,   >=  ,  <=  ,  !=  

        /*int age;

        std::cout << "Enter age: " << std::endl;
        std::cin >> age;

        if (age > 30) {
            std::cout << "20 lv. bonus." << std::endl;
        }

        if (age < 30) {
            std::cout << "No bonus." << std::endl;
        }

        if (age == 30) {
            std::cout << "30 lv. bonus." << std::endl;
        }

        if (age != 30) {
            std::cout << "10 lv. bonus." << std::endl;
        }*/

        /*int score;

        std::cout << "Enter score: " << std::endl;
        std::cin >> score;*/

        // 70 - 3  , 80 - 4 , 90 - 5  , 100 - 6
        // 74 - 3  , 86 - 4

        /*switch (score / 10) {
        case 7:
            std::cout << "Your grade is 3." << std::endl;
            break;
        case 8:
            std::cout << "Your grade is 4." << std::endl;
            break;
        case 9:
            std::cout << "Your grade is 5." << std::endl;
            break;
        case 10:
            std::cout << "Your grade is 6." << std::endl;
            break;
        default:
            std::cout << "You must enter score in 70, 80, 90 or 100" << std::endl;
            break;
        }*/

        // §  , || , bool

    int age;
    int exp;
    std::cout << "Enter your age." << std::endl;
    std::cin >> age;
    std::cin >> exp;

    // logical AND
    // a       true    false    true     false    age > 30
    // b       true    true     false    false    exp > 5
    // 
    // resule  true    false    false    false

    if (age > 30 && exp > 5) {
        std::cout << "Bonus 50lv." << std::endl;
    }
    else {
        std::cout << "No bonus." << std::endl;
    }

    std::cout << "Hello World!" << std::endl;

    return 0;
}
