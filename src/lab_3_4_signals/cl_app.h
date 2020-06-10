//
// Created by micron on 6/3/2020.
//

#ifndef CL_APP
#define CL_APP
#include <string>
#include "cl_base.h"
using namespace std;
class cl_app : public cl_base{
public:
    using cl_base::cl_base;
    void signal(string& a);
    void handler(string a);
    void start();
    int exec_app();
    TYPE_SIGNAL getSign(int);
    TYPE_HANDLER getHand(int);
};
#endif
