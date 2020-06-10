//
// Created by micron on 6/3/2020.
//

#ifndef CL_BASE_H
#define CL_BASE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class cl_base;
typedef void (cl_base::* TYPE_SIGNAL) (string&); // объявляю новые типы
typedef void (cl_base::* TYPE_HANDLER) (string);

#define SIGNAL_D(A, signal_f) (TYPE_SIGNAL) (&A::signal_f) // объявляю макросы для преобразования типов
#define HENDLER_D(B, hendler_f) (TYPE_HANDLER) (&B::hendler_f)


class cl_base{
protected:
    string name;
    cl_base* p_parent;
    int state;
    vector <cl_base*> children;
    struct o_sh{
        TYPE_SIGNAL p_signal;
        cl_base* p_cl_base;
        TYPE_HANDLER p_hendler;
    };
    vector <o_sh*> connects;
    vector <o_sh*>::iterator it;
    int a = 1; // a - выбранный класс
public:
    cl_base(cl_base* p_parent = nullptr);
    cl_base(cl_base*, string);
    string getName();
    cl_base* search(string);
    void readiness_check();
    void print_tree(string);
    void setState(int);
    int getNum();
    void setNum(int);
    void setName(string);
    cl_base* get_root();
    cl_base* search_coordinates(string);
    /* lab4 */
    void set_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
    void delete_connect(TYPE_SIGNAL, cl_base*, TYPE_HANDLER);
    void emit_signal(TYPE_SIGNAL, string &);
    virtual void signal(string&) = 0;       // говорю классу cl_base, что реализацией
    virtual void handler(string) = 0;       // этих методов займутся наследники
};
#endif