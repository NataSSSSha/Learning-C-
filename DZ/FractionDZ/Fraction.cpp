#include "Fraction.h"


std::ostream& operator<<(std::ostream& output, const Fraction& fraction)
{
    output << fraction._numerator << "/" << fraction._denominator << std::endl;
    return output;
}

Fraction operator+ (const Fraction& fraction1, const Fraction& fraction2)
{
    int newNumerator = fraction1._numerator * fraction2._denominator + fraction2._numerator * fraction1._denominator;
    int newDenominator = fraction1._denominator * fraction2._denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction operator-(const Fraction& fraction1, const Fraction& fraction2)
{
    int newNumerator = fraction1._numerator * fraction2._denominator - fraction2._numerator * fraction1._denominator;
    int newDenominator = fraction1._denominator * fraction2._denominator;
    return Fraction(newNumerator, newDenominator);
}

Fraction operator* (const Fraction& fraction1, const Fraction& fraction2)
{
    return Fraction(fraction1._numerator * fraction2._numerator, fraction1._denominator * fraction2._denominator);
}

Fraction operator/ (const Fraction& fraction1, const Fraction& fraction2)
{
    return Fraction(fraction1._numerator * fraction2._denominator, fraction1._denominator * fraction2._numerator);
}
