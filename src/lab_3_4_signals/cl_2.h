//
// Created by micron on 6/3/2020.
//

#ifndef CL_2_H
#define CL_2_H

#include <iostream>
#include <string>
#include "cl_base.h"
using namespace std;

class cl_2 : public cl_base{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
};

#endif //CL_2_H
