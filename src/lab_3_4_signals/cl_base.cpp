//
// Created by micron on 6/3/2020.
//

#include <iostream>
#include <string>
#include "cl_base.h"
using namespace std;

cl_base::cl_base(cl_base* p_parent){
    this->p_parent = p_parent;
    if (p_parent != 0)
        this->p_parent->children.push_back(this);
}

cl_base::cl_base(cl_base* p_parent, string name){
    this->name = name;
    this->p_parent = p_parent;
    if (p_parent != 0)
        this->p_parent->children.push_back(this);
}

void cl_base::setName(string name) { this->name = name; }
string cl_base::getName(){ return this->name; }
void cl_base::setState(int state) { this->state = state; }
int cl_base::getNum() { return a; }
void cl_base::setNum(int a) { this->a = a; }

cl_base* cl_base::get_root() {
    if(this->p_parent == nullptr) return this;
    cl_base* base_prev;
    while(base_prev->p_parent)
        base_prev = base_prev->p_parent;
    return base_prev;
}

cl_base* cl_base::search(string name){
    if (this->name == name) return this;
    for (int i = 0; i < this->children.size(); i++)
        if (this->children[i]->name == name)
            return this->children[i];
    for (int i = 0; i < this->children.size(); i++){
        if (this->children[i]->children.size() != 0){
            cl_base* pointer = children[i]->search(name);
            if (pointer != nullptr)
                return pointer;
        }
    }
    return nullptr;
}

void cl_base::readiness_check(){
    if ((this->search(this->name) != nullptr) && (this->state > 0))
        cout << endl << "The object " << this->name << " is ready";
    else
        cout << endl << "The object " << this->name << " is not ready";
    for (int i = 0; i < this->children.size(); i++)
        children[i]->readiness_check();
}

void cl_base::print_tree(string space) {
    cout << space << name;
    space += " ";
    for(int i = 0; i < children.size(); i++){
        cout << endl;
        children[i]->print_tree(space);
    }
}

cl_base* cl_base::search_coordinates(string coordinates){
    string m_coordinates;
    coordinates.erase(0, 1);
    int number = coordinates.find('/');
    if (number == -1){
        m_coordinates = coordinates;
        coordinates.erase(0, coordinates.size());
    } else {
        for (int i = 0; i < number; i++)
            m_coordinates.push_back(coordinates[i]);
        coordinates.erase(0, number);
    }
    if (this->name == m_coordinates){
        if (coordinates.size() == 0) return this;
        for (int i = 0; i < this->children.size(); i++){
            cl_base* pointer = this->children[i]->search_coordinates(coordinates);
            if (pointer != nullptr)
                return pointer;
        }
    }
    return nullptr;
}

void cl_base::set_connect(TYPE_SIGNAL p_signal, cl_base* p_object,
                          TYPE_HANDLER p_ob_hendler){                       // установить соединение
    for (unsigned int i = 0; i < connects.size(); i++)
        if (connects[i]->p_signal == p_signal &&
            connects[i]->p_cl_base == p_object &&
            connects[i]->p_hendler == p_ob_hendler)
            return;
    o_sh* p_value = new o_sh();
    *p_value = {p_signal, p_object, p_ob_hendler};
    connects.push_back(p_value);                                            // поместить установленную связь ввектор
}

void cl_base::delete_connect(TYPE_SIGNAL p_signal, cl_base* p_object,
                             TYPE_HANDLER p_ob_hendler){                    // удалить соединение
    if (connects.empty()) return;
    for (unsigned int i = 0; i < connects.size(); i++)
        if (connects[i]->p_signal == p_signal &&
            connects[i]->p_cl_base == p_object &&
            connects[i]->p_hendler == p_ob_hendler)
            connects.erase(connects.begin() + i);
}

void cl_base::emit_signal(TYPE_SIGNAL p_signal, string& s_command){         // излучить сигнал
    if (connects.empty()) return;
    it = connects.begin();
    (this->*((*(it))->p_signal))(s_command);
    for (it; it != connects.end(); it++)
        if ((*(it))->p_signal == p_signal)
            (((*(it))->p_cl_base)->*((*(it))->p_hendler))
                    (s_command);
}