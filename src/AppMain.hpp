#ifndef APP_MAIN_HPP
#define APP_MAIN_HPP

#include "../include/database_control.hpp"
#include <iostream>
#include <ws2tcpip.h>
#include <string>


namespace mgu
{
    class AppMain
    {
    public:
        // Constructor
        AppMain();
        // Destructor
        ~AppMain();

        // Funciones
        int Run();

    private:
        WSADATA wsData;
        SOCKET _server;
        sockaddr_in _sint;
        fd_set _master;
        db_control ctrl;
    };
}

#endif // APP_MAIN_HPP
