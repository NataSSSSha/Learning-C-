#pragma once
#include <iostream>

class Complex
{
    double _realNumber;
    double _imaginaryNumber;

public:

    Complex(double real, double image) : _realNumber{ real }, _imaginaryNumber{ image }{}
    Complex() : Complex(0, 0) {}
    Complex(double real) : Complex(real, 0) {}

    friend std::ostream& operator<<(std::ostream& output, const Complex& complex);

    friend Complex operator+ (const Complex& complex1, const Complex& complex2);

    friend Complex operator- (const Complex& complex1, const Complex& complex2);

    friend Complex operator* (const Complex& complex1, const Complex& complex2);

    friend Complex operator/ (const Complex& complex1, const Complex& complex2);
};

