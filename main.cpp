#include <iostream>
#include "list.h"
#include "node.h"

using namespace std;

int main()
{
    List<int> *Minerva = new List<int>;
    Minerva -> push_front(3);
    Minerva -> push_front(2);
    Minerva -> push_back(1);
    Minerva -> pop_front();
    cout << Minerva -> front() << "\n";
    cout << Minerva -> back() << "\n";
    return 0;
}