#include <iostream>
#include <string>

using namespace std;

int countAll(const string where, const string what)
{
    int count = 0;
    int pos = where.find(what);
    while (pos != string::npos)
    {
        count++;
        pos = where.find(what, pos + 1);
    }
    return count;
}

void EraseComment(string& text)
{
    int count = 0;
    count = countAll(text, "//");
    int pos = 0;
    while (text.find("//", pos) != string::npos)
    {
        int f = text.find("//");
        int l = text.find("\n", f);
        text.erase(f, l - f);

    }
    while (text.find("/*", pos) != string::npos)
    {
        int f = text.find("/*");
        int l = text.find("*///", f);
        text.erase(f, l - f + 2);
    }

    cout << text;
}

string AddSymbol(string st1, string st2)
{
    string S, S0;
    string st3 = st2;
    st3.insert(0, "(");
    st3.append(")");
    cout << st3;
    int pos = 0;
    while (st1.find(st2, pos) != string::npos)
    {
        pos = st1.find(st2, pos);
        st1.replace(pos, st2.size(), st3);
        pos += 2;
    }
    return st1;
}

int main()
{
    string code
    { R"(
//program
int a; // number of something
int b; // number of count
/*something happens
void Ptint();*/
 )" };
    cout << code << endl;

    EraseComment(code);

    string string1{ "asdgsabdfgab" };
    string string2{ "ab" };
    cout << AddSymbol(string1, string2);
}
