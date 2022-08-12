#pragma once
#include "Student.h"
#include "Node.h"

class DvList
{
private:
    DvNode* head;
    DvNode* tail;
    int count;

public:
    DvList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    void AddHead(Student student);

    void AddTail(Student student);

    void Delete(int pos);

    int GetCount() { return count; }
};

