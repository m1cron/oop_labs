#include <iostream>
#include "cl_app.h"
#include "cl_2.h"
#include "cl_3.h"
using namespace std;

void cl_app::signal(string& mes){ mes = " Text: " + this->getName()+ " -> " + mes; } //метод сигнала
void cl_app::handler(string mes){ cout << "\nSignal to " << getName() <<mes; } //метод обработчика

void cl_app::start(){
    string children, parent;
    int number, state;
    cin >> name;
    this->setName(name);
    this->setState(1);
    cl_base* child = NULL;
    while (cin >> parent && parent != "endtree") {
        cin >> children >> number >> state;
        cl_base *base = this->search(parent);
        if (number == 2)
            child = new cl_2(base, children);
        else if (number == 3)
            child = new cl_3(base, children);
        child->setState(state);
        child->setNum(number);
    }
    cout << "Object tree\n";
    this->print_tree("");
    cout << "\nSet connects";
    string num, first, second;
    while (cin >> num && num != "0"){
        cin >> first >> second;
        cout << "\n" << num << " " << first << " " << second;
        cl_base* from = search(first);
        from->set_connect(getSign(from->getNum()), search(second),
                          getHand(search(second)->getNum())); // установить связь сигнал->слот
    }
}
int cl_app::exec_app(){
    cout << "\nEmit signals";
    string mes, obj;
    while (cin >> obj && obj != "endsignals"){
        cin >> mes;
        cl_base* run = this->search(obj);
        run->emit_signal(getSign(run->getNum()), mes);
// излучить сигнал
    }
    return 1;
}
TYPE_SIGNAL cl_app::getSign(int clNum){
    if (clNum == 1) return SIGNAL_D(cl_app, signal);
    if (clNum == 2) return SIGNAL_D(cl_2, signal);
    if (clNum == 3) return SIGNAL_D(cl_3, signal);
}
TYPE_HANDLER cl_app::getHand(int clNum){
    if (clNum == 1) return HENDLER_D(cl_app, handler);
    if (clNum == 2) return HENDLER_D(cl_2, handler);
    if (clNum == 3) return HENDLER_D(cl_3, handler);
}