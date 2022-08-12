#include "String.h"
#include <iostream>
#include <cassert>

String::String()
{
    len = 80;
    newString = new char[len];
}

String::String(char* str)
{
    len = strlen(str);
    newString = new char[len + 1];
    strcpy_s(this->newString, len + 1, str);
}

String::String(const String& string1)
{
    len = strlen(string1.newString);
    newString = new char[len + 1];
    strcpy_s(newString, len + 1, string1.newString);
}

String::String(const String&& string1)
{
    newString = string1.newString;

}

void String::Print()
{
    std::cout << newString << std::endl;
}

char String::operator[](int index) const
{
    assert(index >= 0 and index < len and "Index is out of range!");
    return newString[index];
}

int String::operator()(char symbol)
{
    bool IsFound = 0;
    for (int i = 0; i < len; i++)
    {
        if (newString[i] == symbol)
        {
            IsFound = true;
            return i;
        }
    }
    if (!IsFound)
        return -1;
}

String::operator int() const { return len; }
