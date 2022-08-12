#include <iostream>
#include <cassert>
#include "String.h"

int main()
{
    char temp[] = "Hello";
    String someString(temp);

    String smString(someString);

    someString.Print();
    smString.Print();

    std::cout << someString[3] << std::endl;
    char i = 'l';
    std::cout << smString(i) << std::endl;

    int a = someString;
    std::cout << a;

}
