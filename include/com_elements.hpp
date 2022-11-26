//Este arhcivo define las solicitudes y respuestas que se pueden hacer
#ifndef COM_ELEMENTS_HPP
#define COM_ELEMENTS_HPP

#include <string>
#include <iostream>

namespace mgu
{
    
    enum AuthResponseStatus
    {
        ACCEPTED = 0X6348,
        DENIED,
        NOTHING
    };

    ////////////////////////////////////////////////////////////
    /// @brief Define la consulta de auntenticación al servidor
    //////////////////////////////////////////////////////////// 
    class AuthQuery
    {   
        private:

        std::string _user;
        std::string _special_key;
        int _id;
        public:
        //Constructores
        AuthQuery();
        AuthQuery(std::string user, std::string SpecialKey, int ID);
        //Funciones

        //Obtenermos la consula en forma de cadena
        std::string getAsString();

        //Obtenemos el usuario
        std::string getUser();

        //Obtenermos la llave especial
        std::string getSpecialKey();

        int getID();

        void setUser(std::string new_user);
        void setSpecialKey(std::string new_key);
        void setID(int new_id);

    };
    /////////////////////////////////////////////////////////////
    /// @brief Define la respuesta que puede dar el servidor al 
    /// momento de auntenticar
    /////////////////////////////////////////////////////////////
    class AuthResponse
    {
        private:
        AuthResponseStatus _status;

        public:
        //Constructores
        AuthResponse();

        AuthResponse(AuthResponseStatus status);
        //Obtenemos el estado de la conexión
        AuthResponseStatus getStatus();

        //Cambiamos el dato
        void setStatus(AuthResponseStatus new_status);
    };
    class Query
    {

    };
    class Reponse
    {

    };
}
#endif