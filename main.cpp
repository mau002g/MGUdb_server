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
    mgu::AuthQuery qr2;
    std::string text("'he'l'lo,");
    std::cout << qr.getAsString() << std::endl;
    qr2.FromText(qr.getAsString());
    std::cout << qr2.getAsString() << std::endl;
    //for(auto i(0U); i < p.size(); i++)
      //  std::cout << "Element[" << i << "] : " << p[i] << std::endl;

            return 0;
}
