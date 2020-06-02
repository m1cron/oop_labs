//
// Created by micron on 6/2/2020.
//

#include <iostream>
#include <iomanip>
#include "stack.h"
using namespace std;

int main() { // вывод может быть не по тз
    int size, value;
    std::string name;
    cin >> name >> size;
    if ((size <= 0) && (name.length() > 10)) exit(-1);
    stack stack0(name, size);

    cin >> name >> size;
    if ((size <= 0) && (name.length() > 10)) exit(-1);
    stack stack1(name, size);
    do {
        cin >> value;
    } while (stack0.push_front(value) && stack1.push_front(value));

    cout << stack0.getName() << " " << stack0.getSize() <<
         "\n" << stack1.getName() << " " << stack1.getSize() << "\n"
         << left << setw(15) << stack0.getName() <<
         setw(15) << stack1.getName();

    int out0, out1;
    bool flag0, flag1 = true;

    while (true) { // рогонова ебет моск этим while(1)
        flag0 = stack0.pop_front(&out0);
        flag1 = stack1.pop_front(&out1);

        if (!flag0 && !flag1) break;
        cout << endl;

        if (flag0) cout << right << setw(15) << out0;
        if (flag0 && flag1) cout << right << setw(15) << out1;
    }
}