#pragma once
#include <iostream>
class Fraction
{
    int _numerator;
    int _denominator;

public:
    Fraction(int numerator, int denomenator) : _numerator{ numerator }, _denominator{ denomenator } {}

    friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);

    friend Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2);

    friend Fraction operator-(const Fraction& fraction1, const Fraction& fraction2);

    friend Fraction operator* (const Fraction& fraction1, const Fraction& fraction2);

    friend Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2);
    
};

