//
// Created by micron on 6/3/2020.
//

#include <iostream>
#include <string>
#include "cl_2.h"
using namespace std;

void cl_2::signal(string& mes){ mes = " Text: " + this->getName()+ " -> " + mes; }
void cl_2::handler(string mes){ cout << "\nSignal to " << getName() << mes; }
