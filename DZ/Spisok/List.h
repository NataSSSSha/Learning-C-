#pragma once
#include "Node.h"
#include "Student.h"

class List
{
private:
    Node* head;
    int count;
public:
    List() {
        head = nullptr;
        count = 0;
    }
    void Add(Student student);

    void Delete(int pos);

    int GetCount() { return count; }

    void PrintAll();
};

