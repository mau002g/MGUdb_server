#include "src/AppMain.hpp"
#include "include/com_elements.hpp"

int main(int argc, char **argv)
{
    /*int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn; */

    mgu::AuthQuery qr("mauro2002", "3012283423324", 365);
    std::string text("'he'l'lo,");
    std::cout << qr.getAsString() << std::endl;

    //for(auto i(0U); i < p.size(); i++)
      //  std::cout << "Element[" << i << "] : " << p[i] << std::endl;

            return 0;
}
