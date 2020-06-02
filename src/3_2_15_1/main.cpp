//
// Created by micron on 6/2/2020.
//

#include <iostream>
#include "Class0.h"
#include "Class1.h"
using namespace std;

int max(Сlass0& cl1, Сlass1& cl2) { //дружественная функция, лежит в main.cpp
    int max = (cl2.a > cl2.b) ? cl2.a : cl2.b;  // сравнение А и Б во 2ом КЛАССЕ и передача их в переменную
    return (cl1.a > max) ? cl1.a : max; // сравнение А из 1ого КЛАССА и MAX и возврат большего в функцию
}

int main() { // вывод может быть не по тз
    int n, n1;
    cin >> n;
    Сlass0 cl0(n);

    cin >> n >> n1;
    Сlass1 cl1;
    cl1.SetAB(n, n1);

    cout << "max = " << max(cl0, cl1);
}