#include "DvList.h"
#include "Node.h"
#include "Student.h"

void DvList::AddHead(Student student)
{
    DvNode* current = new DvNode;
    current->prev = 0;
    current->student = student;
    current->next = head;

    if (head != 0)
        head->prev = current;

    if (count == 0)
        head = tail = current;
    else
        head = current;

    count++;
}

void DvList::AddTail(Student student)
{
    DvNode* current = new DvNode;
    current->next = 0;
    current->student = student;
    current->prev = tail;

    if (tail != 0)
        tail->next = current;
    if (count == 0)
        head = tail = current;
    else
        tail = current;

    count++;
}

void DvList::Delete(int pos)
{
    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position" << endl;
        return;
    }

    int i = 1;

    DvNode* delNode = head;

    while (i < pos)
    {
        delNode = delNode->next;
        i++;
    }

    DvNode* PrevDel = delNode->prev;
    DvNode* AfterDel = delNode->next;

    if (PrevDel != 0 && count != 1)
        PrevDel->next = AfterDel;
    if (AfterDel != 0 && count != 1)
        AfterDel->prev = PrevDel;

    if (pos == 1)
        head = AfterDel;
    if (pos == count)
        tail = PrevDel;

    delete delNode;

    count--;
}
