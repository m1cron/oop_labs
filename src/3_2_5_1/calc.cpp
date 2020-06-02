//
// Created by micron on 6/2/2020.
//

#include "calc.h"
void calc::operation(int n, char znak, int temp) {
    this->N = n;
    if (znak == '+') this->N = N + temp;
    else if (znak == '-') this->N = N - temp;
    else if (znak == '*') this->N = N * temp;
    else if (znak == '%' && temp != 0) this->N = N % temp;
    else return; // or exit(-1);
}

void calc::operation2(char znak, int temp) {
    operation(N, znak, temp);
}

int calc::getN() { return N; }