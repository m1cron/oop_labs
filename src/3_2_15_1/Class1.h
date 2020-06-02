//
// Created by micron on 6/2/2020.
//

#ifndef SOLUTION_CLASS1_H
#define SOLUTION_CLASS1_H

#include "Class0.h"

class Сlass1 {
private:
    int a, b;
public:
    void SetAB(int a, int b);
    friend int max(Сlass0& cl1, Сlass1& cl2);
};


#endif //SOLUTION_CLASS1_H
