#include "src/AppMain.hpp"
#include "include/com_elements.hpp"



int main(int argc, char **argv)
{
    /*int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn; */
    std::string test =  mgu::Query(mgu::COM, "\"hello + hel\"; \"mauro\"").getAsString();
    mgu::Query t;
    t.FromText(test);
    std::cout << t.getComand() << " " << mgu::COM << std::endl;
    return 0;
}
