//
// Created by micron on 5/21/2020.
//

#ifndef INC_3_1_CL_2_H
#define INC_3_1_CL_2_H


#include "cl_base.h"
#include <string>
using namespace std;

class cl_2 : public cl_base {
public:
    using cl_base::cl_base;
    static void signal(string&);
    static void slot(cl_base*, string&);
};


#endif //INC_3_1_CL_2_H
