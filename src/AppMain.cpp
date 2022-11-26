#include "AppMain.hpp"
#include <cstdlib>
#include <cctype>

namespace mgu
{
    //Constructor
    AppMain::AppMain()
    {
        setlocale(LC_CTYPE, "spanish");
        std::cout << "[INICIALIZANDO]" << std::endl;
        WORD ver = MAKEWORD(2,2);
        try
        {
            //Inicializamos el winsock
            int wsOk = WSAStartup(ver, &(this->wsData));
            if(wsOk != 0)
            {
                std::cout << "No ha sido posible inicializar WinSock." << std::endl;
                throw true;
            }

            //Creamos el socket
            this->_server = socket(AF_INET, SOCK_STREAM, 0);
            if(this->_server == INVALID_SOCKET)
            {
                std::cout << "No ha sido posible crear el socket." << std::endl;
                throw true;
            }

            //Asociamos el socket con un puerto
            this->_sint.sin_family = AF_INET;
            this->_sint.sin_port = htons(55100);
            this->_sint.sin_addr.S_un.S_addr = INADDR_ANY;
            bind(this->_server, (sockaddr*)&(this->_sint), sizeof(this->_sint));

            //Ponemos el socket a la escucha
            listen(this->_server, SOMAXCONN);

            std::cout << "[ESPERANDO CONEXIONES]" << std::endl;

        }catch(bool error)
        {
            std::cout << "[ERROR] No se ha podido inicializar el servidor." << std::endl;
            std::cout << "Saliendo...." << std::endl;
            std::exit(1);
        }
    }
    //Destructor
    AppMain::~AppMain()
    {
        std::cout << "[SALIR]" << std::endl;
    }
    //Función principal
    int AppMain::Run()
    {
        bool ejecutando(true);
        //Preparamos el descriptor
        FD_ZERO(&(this->_master));

        //Añadimos el socket al descriptor
        FD_SET(this->_server, &(this->_master));

        while(ejecutando)
        {
            //Creamos esta copia porque según lo que dicen la función es destructiva
            fd_set master = this->_master;

            //Miramos que hay de nuevo
            int SocketCount = select(0, &master, nullptr, nullptr, nullptr);

            //Vemos a cada socket
            for(int i(0); i < SocketCount; i++)
            {
                SOCKET tsock = master.fd_array[i];

                //Vemos si un cliente quiere conectarse
                if(tsock == this->_server)
                {
                    sockaddr_in client_info;
                    int ss = sizeof(sockaddr_in);
                    // Un cliente quiere conectarse
                    // Debemos aceptarlo
                    SOCKET client = accept(this->_server, (sockaddr*)&client_info, &ss);

                    // Y lo añadimos a la lista de clientes
                    FD_SET(client, &(this->_master));
                    //Obteniendo y mos trando la ip
                    std::string client_ip(inet_ntoa(client_info.sin_addr));
                    std::cout << "[NUEVA CONEXIÓN] IP: " << client_ip << " Puerto: " << ntohs(client_info.sin_port) << std::endl;

                    
                    //Hacemos algo con el cliente le enviamos cosas
                    ejecutando = false;
                }else //Parece que es un mensaje
                {
                    /*
                    int bytesIn = recv(sock, buff, 4096, 0);
                    if( bytesIN <= 0)
                    {
                        closesocket(sock);
                        FD_CLR(sock, master);
                        continue;
                    }
                    */
                }
            }
        }

        FD_CLR(this->_server, &(this->_master));
        closesocket(this->_server);

        while(this->_master.fd_count > 0)
        {
            SOCKET sock = this->_master.fd_array[0];
            FD_CLR(sock, &(this->_master));
            closesocket(sock);
        }

        WSACleanup();
        return 0;
    }
}