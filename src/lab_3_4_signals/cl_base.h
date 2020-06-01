//
// Created by micron on 5/21/2020.
//

#ifndef INC_3_1_TRY_1_CL_BASE_H
#define INC_3_1_TRY_1_CL_BASE_H

#include <vector>
#include <string>
using namespace std;

class cl_base;
typedef void (*s_signal)(string&);
typedef void (*s_slot)(cl_base*, string& s);
#define SIGNAL(ssignal) ((s_signal) (&ssignal)) // наш любимый тупедеф <3
#define SLOT(slt) ((s_slot) (&slt))


class cl_base {
private:
    string name;
    cl_base* head;
    vector<cl_base*> childs;
    int state;

    struct connect{
        cl_base* base;
        s_signal sig;
        s_slot slt;
    };
    vector<connect> connects;

public:
    cl_base(cl_base* head = nullptr);
    cl_base(cl_base* head, string name);
    cl_base* find(string);
    void setName(string);
    void print_tree(string);
    void print_state(bool temp = 1);
    void setState(int);
    string getName();
    string get_path(string, int);
    cl_base* get_root();
    cl_base* get_obj(string);
    void set_connect(s_signal, s_slot, cl_base*);
    void del_connect(s_signal, s_slot, cl_base*);
    void emit_signal(s_signal, string&);
};

#endif //INC_3_1_TRY_1_CL_BASE_H