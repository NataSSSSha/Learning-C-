// FractionDZ.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Fraction.h"
#include "Complex.h"


int main()
{
    Fraction frac1(5, 2);
    Fraction frac2(6, 3);
    std::cout << frac1 + frac2 << frac1 - frac2 << frac1*frac2 << frac1/frac2;

    Complex complex1(2);
    Complex complex2(5, 3);
    Complex complex3(4.5, 2);
    std::cout << complex1 << complex2;
    std::cout << complex1 + complex3;
    std::cout << complex2 - complex3;
    std::cout << complex3 * complex2;
    std::cout << Complex(3, 1) / Complex(2, -3);
}


