//
// Created by micron on 6/2/2020.
//

#ifndef SOLUTION_STACK_H
#define SOLUTION_STACK_H

#include <string>

class stack {
private:
    int* arr;
    int top;
    int capacity;
    std::string name;
public:
    stack(std::string name, int capacity);
    ~stack();

    bool push_front(int);
    bool pop_front(int*);
    int getSize();
    std::string getName();
    int getNum();
};


#endif //SOLUTION_STACK_H
