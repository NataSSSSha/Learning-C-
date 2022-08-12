#pragma once
#include <iostream>
using namespace std;

struct Student
{
    string name;
    string phoneNumber;
    string adress;

    Student() {}

    Student(string name, string phoneNumber, string adress) :
        name{ name }, phoneNumber{ phoneNumber }, adress{ adress } {}

    void Print()
    {
        cout << name << ' ' << phoneNumber << ' ' << adress << endl;
    }
};

