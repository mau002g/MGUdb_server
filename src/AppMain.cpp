#include "AppMain.hpp"

namespace mgu
{
    //Constructor
    AppMain::AppMain()
    {
        std::cout << "Iniciando..." << std::endl;
    }
    //Destructor
    AppMain::~AppMain()
    {
        std::cout << "Saliendo..." << std::endl;
    }
    //Funci�n principal
    int AppMain::Run()
    {
        std::cout << "Hola mundo" << std::endl;
        return 0;
    }
}