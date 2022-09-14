#pragma once
#include "Item.h"
#include "DList.h"

class Queue
{
    DList queue;
public:
    Queue() {};
    void push(char value)
    {
        queue.Add(value);
    }

    void pop()
    {
        if (isEmpty())
            return;

        char temp = queue.GetFirst();
        queue.RemoveFirst();
        queue.Add(temp);
    }

    Item* top()
    {
        if (!isEmpty())
            return queue.GetHead();
    }

    bool isEmpty() { return queue.IsEmpty(); }
};
