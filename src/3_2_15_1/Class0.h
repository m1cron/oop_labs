//
// Created by micron on 6/2/2020.
//

#ifndef SOLUTION_CLASS0_H
#define SOLUTION_CLASS0_H


class Сlass1;
class Сlass0 {
private:
    int a;
public:
    Сlass0(int a);
    friend int max(Сlass0 &cl1, Сlass1 &cl2);
};


#endif //SOLUTION_CLASS0_H
