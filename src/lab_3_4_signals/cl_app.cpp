//
// Created by micron on 5/21/2020.
//

#include <iostream>
#include "cl_app.h"
#include "cl_2.h"
#include "cl_3.h"
using namespace std;

void cl_app::start(){
    string obj0, obj1;
    int cls, state;
    cin >> obj0;
    this->setName(obj0);
    this->setState(1);

    while ((cin >> obj0) && (obj0 != "endtree")) {
        cin >> obj1 >> cls >> state;
        cl_base *base = this->find(obj0);
        if(cls == 2) {
            cl_2* cls_2 = new cl_2(base, obj1);
            cls_2->setState(state);
        }
        if(cls == 3) {
            cl_3* cls_3 = new cl_3(base, obj1);
            cls_3->setState(state);
        }
    }
    cout << "Object tree\n";
    print_tree("");
    cout << "\nSet connects";
    string number, first, second, message;
    cl_base* from = nullptr;
    cl_base* to = nullptr;
    while ((cin >> number) && (number != "0")){
        cin >> first >> second;
        cout << "\n" << number << " " << first << " " << second;
        from = get_root()->find(first);
        to = get_root()->find(second);
        from->set_connect(SIGNAL(cl_2::signal), SLOT(cl_3::slot), to);
    }
}

int cl_app::exe_app() {
    cout << "\nEmit signals";
    string sender, message;
    cl_base* from = nullptr;
    while ((cin >> sender) && (sender != "endsignals")) {
        cin >> message;
        from = get_root()->find(sender);
        from->emit_signal(SIGNAL(cl_2::signal), message);
    }
    return 1;
}

void cl_app::printPath() {
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