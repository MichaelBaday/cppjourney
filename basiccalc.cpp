#include <iostream>

int main () {
    double num1, num2;
    std::cout << "Input the first number: ";
    std::cin >> num1;
    std:: cout << "Input the second number: ";
    std::cin >> num2;
    
    double sum, diff, prod;
    sum = num1 + num2;
    diff = num1 - num2;
    prod = num1 * num2;

    if (num2 != 0) {
    double quot = num1 / num2;
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Difference = " << diff << std::endl;
    std::cout << "Product = " << prod << std::endl;
    std::cout << "Quotient = " << quot << std::endl;
    } else {
    std::cout << "Sum = " << sum << std::endl;
    std::cout << "Difference = " << diff << std::endl;
    std::cout << "Product = " << prod << std::endl;
    std::cout << "Quotient = Undefined " << std::endl;
    }

    return 0;

}