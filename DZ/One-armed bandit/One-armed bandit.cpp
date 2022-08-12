#include <iostream>
#include "Item.h"
#include "DList.h"
#include "Queue.h"


using namespace std;

int main()
{
    srand(time(0));
    Queue first, second, third;
    char f, s, t;
    for (int i = 0; i < 10; i++)
    {
        f = rand() % 4 + 2;
        s = rand() % 4 + 2;
        t = rand() % 4 + 2;
        first.push(f);
        second.push(s);
        third.push(t);
    }
    //Необходимая комбинация
    cout << first.top()->value << " " << second.top()->value << " " << third.top()->value << endl;
    cin.get();
    for (int i = 0; i < rand() % 50; i++)
    {
        first.pop();
    }
    for (int i = 0; i < rand() % 50; i++)
    {
        second.pop();
    }
    for (int i = 0; i < rand() % 50; i++)
    {
        third.pop();
    }
    //Выпавшая комбинация
    cout << first.top()->value << " " << second.top()->value << " " << third.top()->value << endl;
    if (first.top() == second.top() && first.top() == third.top())
    {
        cout << "You win!" << endl;
    }
    else
        cout << "You lose." << endl;
}
