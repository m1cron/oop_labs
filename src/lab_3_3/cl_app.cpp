//
// Created by micron on 5/21/2020.
//

#include <iostream>
#include "cl_app.h"
#include "cl_2.h"
#include "cl_3.h"
#include "cl_4.h"
#include "cl_5.h"
#include "cl_6.h"
using namespace std;

void cl_app::start() {
    string obj0, obj1;
    int cls, state;
    cin >> obj0;
    this->setName(obj0);
    this->setState(1);

    while ((cin >> obj0) && (obj0 != "endtree")) {
        cin >> obj1 >> cls >> state;

        cl_base *base = this->get_path(obj0);

        if (cls == 2) {
            cl_2 *cls_2 = new cl_2(base, obj1);
            cls_2->setState(state);
        } else if (cls == 3) {
            cl_3 *cls_3 = new cl_3(base, obj1);
            cls_3->setState(state);
        } else if (cls == 4) {
            cl_4 *cls_4 = new cl_4(base, obj1);
            cls_4->setState(state);
        } else if (cls == 5) {
            cl_5 *cls_5 = new cl_5(base, obj1);
            cls_5->setState(state);
        } else if (cls == 6) {
            cl_6 *cls_6 = new cl_6(base, obj1);
            cls_6->setState(state);
        }
    }
}

void cl_app::print_path() {
    string obj0;
    while ((cin >> obj0) && (obj0 != "//")) {
        cout << endl << obj0 << "     ";
        cl_base* base;
        if (obj0 == "/root" || obj0 == "//root")
            base = this;
        else
            base = this->get_obj(obj0);

        if(base == nullptr)
            cout << "Object not found";
        else
            cout << "Object name: " << base->getName();
    }
}

int cl_app::exe_app() {
    print_tree("");
    print_path();
    //print_state();
    return 1;
}