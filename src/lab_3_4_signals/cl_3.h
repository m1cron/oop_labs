//
// Created by micron on 6/3/2020.
//

#ifndef CL_3_H
#define CL_3_H

#include <iostream>
#include <string>
#include "cl_base.h"
using namespace std;
class cl_3 : public cl_base{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
};

#endif //CL_3_H
