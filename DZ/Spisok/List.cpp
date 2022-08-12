#include "List.h"
#include "Student.h"
#include "Node.h"

using namespace std;

void List::Add(Student student)
{

    if (head == nullptr)
    {
        Node* current = new Node;
        current->student = student;
        current->next = nullptr;
        head = current;
        count++;
        return;
    }
    Node* current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    Node* newNode = new Node();
    newNode->student = student;
    newNode->next = nullptr;

    current->next = newNode;

    count++;
}

void List::Delete(int pos)
{
    if (pos < 1 || pos > count)
    {
        cout << "Incorrect position" << endl;
        return;
    }

    int i = 1;

    Node* delNode = head;

    while (i < pos)
    {
        delNode = delNode->next;
        i++;
    }

    Node* AfterDel = delNode->next;

    if (pos == 1)
        head = AfterDel;

    delete delNode;

    count--;
}

void List::PrintAll()
{
    Node* current = head;

    head->student.Print();

    while (current->next != nullptr)
    {
        current = current->next;
        current->student.Print();
    }
}
