//
// Created by micron on 6/3/2020.
//

#include <iostream>
#include <string>
#include "cl_3.h"
using namespace std;

void cl_3::signal(string& mes){ mes = " Text: " + this->getName()+ " -> " + mes; }
void cl_3::handler(string mes){ cout << "\nSignal to " << getName() << mes; }