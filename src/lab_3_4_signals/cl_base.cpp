#include <iostream>
#include <string>
#include "cl_base.h"
using namespace std;

cl_base::cl_base(cl_base* head) { this->head = head; }

cl_base::cl_base(cl_base* head, string name) {
    setName(name);
    if(head != nullptr){
        this->head = head;
        head->childs.push_back(this);
    }
}

cl_base* cl_base::find(string name){
    if(this->name == name) return this;
    for(int i = 0; i < childs.size(); i++){
        if(childs[i]->find(name) != nullptr) return childs[i]->find(name);
    }
    return nullptr;
}

void cl_base::setName(string name) { this->name = name; }
void cl_base::setState(int state) {this->state = state; }
string cl_base::getName() { return this->name; }

void cl_base::print_tree(string space) {
    cout << space << name;
    space += "    ";
    for(int i = 0; i < childs.size(); i++){
        cout << endl;
        childs[i]->print_tree(space);
    }
}

void cl_base::print_state(bool temp) {
    if(temp) cout << "\nTest result\n";
    cout << "The object " << this->name;
    if(state > 0) cout << " is ready";
    else cout << " is not ready";

    for(int i = 0; i < childs.size(); i++){
        cout << endl;
        childs[i]->print_state(0);
    }
}

string cl_base::get_path(string path, int i_lvl){
    int i_item_start = 1, i_item_end, i_lc = 1;
    while(i_item_start){
        i_item_end = path.find('/', i_item_start);
        if(i_lc == i_lvl) return path.substr(i_item_start, i_item_end - i_item_start);
        i_lc++;
        i_item_start = i_item_end + 1;
    }
    return "";
}

cl_base* cl_base::get_root() {
    if(this->head == nullptr) return this;
    cl_base* base_prev;
    while(base_prev->head)
        base_prev = base_prev->head;
    return base_prev;
}

cl_base* cl_base::get_obj(string path){
    int i_lvl_next = 2; // уровень в программе
    cl_base *base_next = get_root(); // получил указатель на рут
    string temp = get_path(path , 1);
    if(temp != get_root()->getName()) return NULL; // проверка на ошибки
    temp = get_path(path, i_lvl_next);
    while(!temp.empty()){
        cl_base *base_prev = base_next->find(temp);
        if(base_prev){
            base_next = base_prev;
            i_lvl_next++;
            temp = get_path(path, i_lvl_next);
        } else { return NULL; }
    }
    return base_next;
}