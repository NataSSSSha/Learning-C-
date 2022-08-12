#include <iostream>
#include "DvList.h"
#include "List.h"
#include "Student.h"
using namespace std;


int main()
{
    List list;

    DvList dvList;

    Student stud1("Oleg", "856478", "Moscow");
    Student stud2("Denis", "547563", "Izhevsk");

    list.Add(stud1);
    list.Add(stud2);
    list.PrintAll();
    cout << list.GetCount() << endl;
    list.Delete(1);
    cout << list.GetCount() << endl;

    dvList.AddHead(stud1);
    dvList.AddTail(stud2);
    cout << dvList.GetCount() << endl;
    dvList.Delete(1);
    cout << dvList.GetCount() << endl;
}
