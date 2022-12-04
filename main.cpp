#include "src/AppMain.hpp"
#include "include/com_elements.hpp"



int main(int argc, char **argv)
{
    /*int rtn(0);
    mgu::AppMain *myapp = new mgu::AppMain;
    rtn = myapp->Run();
    delete myapp;
    return rtn; */
    std::string a = mgu::Response(mgu::RDATA, "mauroe").getAsString();
    mgu::Response d; d.FromText(a);
    std::cout <<  d.getData() << "," << mgu::RDATA << std::endl;
    return 0;
}
