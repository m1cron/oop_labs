#include "cl_base.h"
#include "cl_app.h"

int main() {
    cl_app app;
    app.start();
    return app.exec_app();
}