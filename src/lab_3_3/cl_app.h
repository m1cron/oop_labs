//
// Created by micron on 5/21/2020.
//

#ifndef INC_3_1_TRY_1_CL_APP_H
#define INC_3_1_TRY_1_CL_APP_H


#include "cl_base.h"

class cl_app : public cl_base {
public:
    using cl_base::cl_base;
    void start();
    void print_path();
    int exe_app();
};


#endif //INC_3_1_TRY_1_CL_APP_H
