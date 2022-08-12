#pragma once
#include "Student.h"

struct DvNode
{
    DvNode() {}
    Student student;
    DvNode* prev;
    DvNode* next;
};

struct Node
{
    Node() {}
    Student student;
    Node* next;
};

