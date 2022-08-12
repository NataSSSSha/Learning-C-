#pragma once
#include <iostream>


template <class T>
class Array
{
public:
    T* _array;
    int _size;
    bool IsSort = false;
public:
    Array(T* array, int size) : _array{ new T[size] }, _size{ size }
    {
        for (int i = 0; i < _size; i++)
        {
            _array[i] = array[i];
        }
    }

    T GetSize()
    {
        return _size;
    }

    void sortArr()
    {
        for (int k = _size - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (_array[j] > _array[j + 1])
                {
                    std::swap(_array[j], _array[j + 1]);
                }
            }
        }
        for (int i = 0; i < _size; i++)
        {
            std::cout << _array[i] << " ";
        }
        std::cout << std::endl;
        IsSort = true;
    }

    T Min()
    {
        if (!IsSort)
            sortArr();
        return _array[0];
    }

    T Max()
    {
        if (!IsSort)
            sortArr();
        return _array[_size - 1];
    }

    T BinarySearch(T key)
    {
        bool flag = false;
        int left = 0;
        int right = _size - 1;
        int mid;

        if (!IsSort)
            sortArr();

        while ((left <= right) && (flag != true)) {
            mid = (left + right) / 2;

            if (_array[mid] == key) flag = true;
            if (_array[mid] > key) right = mid - 1;
            else left = mid + 1;
        }

        if (flag)
            return mid;
        else return -1;
    }

    void Change(T key, T value)
    {
        if (BinarySearch(key) != -1)
            _array[BinarySearch(key)] = value;
        else
            std::cout << "Error";
    }
};


