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
    //Función principal
    int AppMain::Run()
    {
        std::cout << "Hola mundo" << std::endl;
        std::cout << "This is a test" << std::endl;
        return 0;
    }
}