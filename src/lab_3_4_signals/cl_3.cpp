//
// Created by micron on 5/21/2020.
//


#include "cl_3.h"
#include <string>
#include <iostream>
using namespace std;

void cl_3::slot(cl_base* ptr, string& mes){
    cout << "\nSignal to " << ptr->getName() << " Text: " << mes;
}
