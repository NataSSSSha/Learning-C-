#pragma once
#include "Item.h"
using namespace std;

class DList
{
    Item* head;
    Item* tail;
    int size;
public:
    DList()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Add(char value, int prior = 1);

    void Print();

    bool IsEmpty() { return size == 0; }

    void Insert(int index, int value, int prior = 1);

    void RemoveLast();

    void RemoveFirst();

    Item* GetHead() { return head; }
    int GetSize() { return size; }
    int& GetLast() { return tail->value; }
    int& GetFirst() { return head->value; }

    int& Get(int index);

    void Set(int index, int value);

    void Clear();
};

