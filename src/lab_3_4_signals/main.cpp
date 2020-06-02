#include "cl_base.h"
#include "cl_app.h"
#include <iostream>
using namespace std;

void signal(string& mes){
    cout << " -> "<< mes;
}
void slot(cl_base* ptr, string& mes){
    cout << "\nSignal to " << ptr->getName() << " Text: " << mes;
}

int main() {
    cl_app app;
    app.start(signal, slot);
    return app.exe_app(signal);
}