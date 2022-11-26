#include "src/AppMain.hpp"

int main(int argc, char **argv)
{
    int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn;
}
