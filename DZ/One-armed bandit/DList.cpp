#include <iostream>
#include "DList.h"

using namespace std;

void DList::Add(char value, int prior)
{
    Item* temp = new Item;
    temp->value = value;
    temp->pPrev = nullptr;
    temp->pNext = nullptr;
    if (size == 0)
    {
        head = tail = temp;
    }
    else
    {
        tail->pNext = temp;
        temp->pPrev = tail;
        tail = temp;
    }
    size++;
}

void DList::Print()
{
    Item* ptemp = head;
    while (ptemp != nullptr)
    {
        cout << ptemp->value << " ";
        ptemp = ptemp->pNext;
    }
}

void DList::Insert(int index, int value, int prior)
{
    Item* temp = new Item;
    temp->value = value;

    if (IsEmpty() && index < 0 && index > size)
    {
        cout << "OutOfRange" << endl;
        return;
    }

    if (index == 0)
    {
        temp->pNext = head;
        head->pPrev = temp;
        head = temp;
        size++;

        return;
    }

    if (index == size)
    {
        temp->pPrev = tail;
        tail->pNext = temp;
        tail = temp;
        size++;

        return;
    }

    int i;
    Item* ptemp = nullptr;

    if (index < (size / 2))
    {
        i = 0;
        ptemp = head;
        while (ptemp != nullptr)
        {
            if (i == index)
                break;
            ptemp = ptemp->pNext;
            i++;
        }
    }
    else
    {
        i = size - 1;
        ptemp = tail;
        while (ptemp != nullptr)
        {
            if (i == index - 1)
                break;
            ptemp = ptemp->pPrev;
            i--;
        }
    }

    temp->pPrev = ptemp;
    temp->pNext = ptemp->pNext;
    ptemp->pNext->pPrev = temp;
    ptemp->pNext = temp;
    size++;
}

void DList::RemoveFirst()
{
    if (IsEmpty())
        return;

    Item* ptemp = head;
    Item* temp;

    if (head->pNext == nullptr)
    {
        delete head;
        head = nullptr;
        size--;
        return;
    }

    temp = ptemp->pNext;
    temp->pPrev = nullptr;
    delete ptemp;
    head = temp;
    size--;
}

void DList::RemoveLast()
{
    if (IsEmpty())
        return;

    Item* ptmp = tail;
    Item* tmp;

    if (tail->pPrev == nullptr)
    {
        delete tail;
        tail = nullptr;
        size--;
        return;
    }

    tmp = ptmp->pPrev;
    tmp->pNext = nullptr;
    delete ptmp;
    tail = tmp;
    size--;
}

int& DList::Get(int index)
{
    if (index < 0 && index > size)
    {
        cout << "OutOfRange" << endl;
        return;
    }

    int i;
    Item* ptemp;

    if (index <= (size / 2))
    {
        i = 0;
        ptemp = head;
        while (ptemp != nullptr)
        {
            if (i == index)
                return ptemp->value;
            ptemp = ptemp->pNext;
            i++;
        }
    }

    else
    {
        i = size - 1;
        ptemp = tail;
        while (ptemp != nullptr)
        {
            if (i == index)
                return ptemp->value;
            ptemp = ptemp->pPrev;
            i--;
        }
    }
}

void DList::Set(int index, int value)
{
    if (index >= 0 && index < size)
    {
        Get(index) = value;
    }
    else
    {
        cout << "OutOfRange" << endl;
    }
}

void DList::Clear()
{
    if (!IsEmpty())
    {
        Item* p = head;
        Item* pP = head;
        while (p != nullptr)
        {
            p = p->pNext;
            delete pP;
            pP = p;
        }
        size = 0;
    }
}
