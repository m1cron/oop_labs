//
// Created by micron on 6/2/2020.
//

#include <iostream>
#include "calc.h"
using namespace std;

int main() { // вывод может быть не по тз
    calc calc;
    int n, temp, count = 1; char znak; bool vvod = 0, vvod0 = 1;
    cin >> n >> znak >> temp;
    calc.operation(n, znak, temp);
    while (vvod0) {
        cin >> znak;
        count++;
        if (znak == 'C') break;
        else {
            cin >> temp;
            calc.operation2(znak, temp);
            if (count == 3) {
                count = 0;
                if (vvod) cout << endl;
                cout << calc.getN();
                vvod = 1;
            }
        }
    }
}