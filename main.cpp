#include "fraction.h"

int main() {
    Fraction frac1, frac2;
    std::cout << "Enter the first fraction (numerator/denominator): ";
    std::cin >> frac1;

    std::cout << "Enter the second fraction (numerator/denominator): ";
    std::cin >> frac2;

    Fraction sum = frac1 + frac2;
    Fraction difference = frac1 - frac2;
    Fraction product = frac1 * frac2;
    Fraction quotient = frac1 / frac2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    return 0;
}
