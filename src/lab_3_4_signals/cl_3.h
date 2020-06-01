//
// Created by micron on 5/21/2020.
//

#ifndef INC_3_1_CL_3_H
#define INC_3_1_CL_3_H


#include "cl_base.h"
#include <string>
using namespace std;

class cl_3 : public cl_base {
public:
    using cl_base::cl_base;
    static void signal(string&);
    static void slot(cl_base*, string&);
};


#endif //INC_3_1_CL_3_H
