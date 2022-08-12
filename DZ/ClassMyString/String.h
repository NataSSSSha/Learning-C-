#pragma once
#include <iostream>


class String
{
    char* newString = nullptr;
    int len = 0;


public:
    String();

    String(char* str);

    String(const String& string1);

    String(const String&& string1);

    void Print();

    char operator[](int index) const;

    int operator()(char symbol);

    operator int() const;
};

