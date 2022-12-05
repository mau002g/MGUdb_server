//#include "src/AppMain.hpp"
#include "include/database_control.hpp"
#include <cstdlib>


int main(int argc, char **argv)
{
    /*int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn; */

    mgu::db_control db;
    db.Start();
    std::system("pause");
    return 0;
}
