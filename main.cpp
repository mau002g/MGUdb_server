//#include "src/AppMain.hpp"
#include "src/AppMain.hpp"
#include <cstdlib>


int main(int argc, char **argv)
{
    int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn;
    return 0;
}
