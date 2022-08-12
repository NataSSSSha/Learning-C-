#include <iostream>
#include "Array.h"

int main()
{
    int IntArray[]{ 6, 7, 8, 5, 3 };
    int size1 = sizeof(IntArray) / sizeof(int);
    Array<int> numberArr(IntArray, size1);
    numberArr.sortArr();

    float fArray[]{ 2.1, 3, 7.8, 6 };
    int size2 = sizeof(fArray) / sizeof(float);
    Array<float> floatArr(fArray, size2);
    std::cout << floatArr.Min() << std::endl;
    std::cout << floatArr.BinarySearch(7.8);
}
