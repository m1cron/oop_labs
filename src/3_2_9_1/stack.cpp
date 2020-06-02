//
// Created by micron on 6/2/2020.
//

#include "stack.h"
stack::stack(std::string name, int size) {
    arr = new int[size];
    this->name = name;
    this->capacity = size;
    top = -1;
}

stack::~stack() { delete arr; }

bool stack::push_front(int value) {
    if (top == capacity - 1) { return false; } // overflow
    arr[++top] = value;
    return true;
}

bool stack::pop_front(int* out) {
    if (top == -1) { return false; } // underflow
    *out = arr[top];
    top--;
    return true;
}
int stack::getSize() { return capacity; }
int stack::getNum() { return top; }
std::string stack::getName() { return name; }