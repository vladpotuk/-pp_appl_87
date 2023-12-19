#include "fraction.h"

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int num, int den) : numerator(num), denominator(den) {
    if (denominator == 0) {
        std::cerr << "Error: Denominator cannot be zero." << std::endl;
        exit(1);
    }

    
    int commonFactor = gcd(numerator, denominator);
    numerator /= commonFactor;
    denominator /= commonFactor;

    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
        denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        std::cerr << "Error: Division by zero." << std::endl;
        exit(1);
    }
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    os << fraction.numerator;
    if (fraction.denominator != 1) {
        os << '/' << fraction.denominator;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& fraction) {
    char slash;
    is >> fraction.numerator;

    
    if (is.peek() == '/') {
        is >> slash >> fraction.denominator;

        
        if (fraction.denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(1);
        }
    }
    else {
        fraction.denominator = 1; 
    }

    return is;
}
