#include "Complex.h"

std::ostream& operator<<(std::ostream& output, const Complex& complex)
{
    if (complex._imaginaryNumber == 0)
        output << complex._realNumber << std::endl;
    else
        output << complex._realNumber << "+" << complex._imaginaryNumber << "i" << std::endl;
    return output;
}

Complex operator+ (const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1._realNumber + complex2._realNumber, complex1._imaginaryNumber + complex2._imaginaryNumber);
}

Complex operator- (const Complex& complex1, const Complex& complex2)
{
    return Complex(complex1._realNumber - complex2._realNumber, complex1._imaginaryNumber - complex2._imaginaryNumber);
}

Complex operator* (const Complex& complex1, const Complex& complex2)
{
    double newReal = complex1._realNumber * complex2._realNumber - complex1._imaginaryNumber * complex2._imaginaryNumber;
    double newImage = complex1._realNumber * complex2._imaginaryNumber + complex1._imaginaryNumber * complex2._realNumber;
    return Complex(newReal, newImage);
}

Complex operator/ (const Complex& complex1, const Complex& complex2)
{
    double denominator = complex2._realNumber * complex2._realNumber + complex2._imaginaryNumber * complex2._imaginaryNumber;
    double newReal = (complex1._realNumber * complex2._realNumber + complex1._imaginaryNumber * complex2._imaginaryNumber) / denominator;
    double newImage = (complex2._realNumber * complex1._imaginaryNumber - complex1._realNumber * complex2._imaginaryNumber) / denominator;
    return Complex(newReal, newImage);
}
