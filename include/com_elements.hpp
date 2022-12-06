//Este arhcivo define las solicitudes y respuestas que se pueden hacer
#ifndef COM_ELEMENTS_HPP
#define COM_ELEMENTS_HPP

#include <string>
#include <iostream>
#include <vector>

namespace mgu
{
    
    enum AuthResponseStatus
    {
        ACCEPTED = 0X6348,
        DENIED,
        NOTHING
    };
    enum QueryReturn
    {
        QINVALID = 0x2cc,
        QOK,
        QNULL 
    };
    enum ResponseType
    {
        RERROR = 0x2222,
        RDENIED,
        RDATA,
        ROK,
        RMESSAGE,
        RNULL
    };
    enum QueryType
    {
        not_defined = 0,
        create_db = 0x2f6c,  //Crear una base de datos
        create_tb,           //Crear tablas
        create_tg,           //Crear una etiqueta
        delete_db,           //Borar base de datos
        delete_tb,           //Borra una tabla
        delete_tg,           //Borrar una etiqueta
        delete_row_in_tb,    //Borra una fila en una tabla
        delete_column_in_tb, //Borra una columna en una tabla
        insert_in_tb,        //Insertar datos a una tabla
        mod_tg,              //Modifica datos en una etiqueta
        mod_in_tb,           //Modificar datos en una tabla
        get_tb_rows,         //Devuelve el numero de filas de una tabla
        get_tb_columns,      //Devuelve el numero de columnas de una tabla
        get_tb_column_name, //Devuelve el nombre de una columna
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
        QueryReturn r;
        public:
        //Constructores
        AuthQuery();
        AuthQuery(std::string texto_decode);
        AuthQuery(std::string user, std::string SpecialKey, int ID);
        //Funciones
        QueryReturn getStatus();
        //Creamos una AuthQuery desde una cadena de texto
        QueryReturn FromText(std::string text);
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
        QueryReturn r;
        public:
        //Constructores
        AuthResponse();

        AuthResponse(AuthResponseStatus status);
        //Obtenemos el estado de la conexión
        QueryReturn getStatus();
        AuthResponseStatus getResponse();
        std::string getAsString();
        QueryReturn FromText(std::string text);
        //Cambiamos el dato
        void setResponse(AuthResponseStatus new_response);
    };

    /////////////////////////////////////////////////////////////
    /// @class Query
    /// @brief Se encarga de manejar las solicitudes hacia el 
    /// servidor
    /////////////////////////////////////////////////////////////
    class Query
    {
        private:
        QueryType tp;
        QueryReturn r;
        std::string db;
        std::vector<std::string> params;
        bool isComand(unsigned int );
        public:
        Query() : tp(not_defined) {}
        Query(QueryType c, std::string params, std::string db);
        QueryReturn getStatus();
        QueryReturn FromText(std::string t);
        QueryType getComand();
        std::string getDB();
        std::string getParam(unsigned int index); //Desde cero
        unsigned int getNParams();
        std::string getAsString();

    };
    /////////////////////////////////////////////////////////////
    /// @brief Se encarga de manejar las respuestas del servidor 
    /// al cliente.
    /////////////////////////////////////////////////////////////
    class Response
    {
        private:
        ResponseType rtp;
        std::string mm; //Usos multiples
        QueryReturn r;
        QueryReturn setReturn(QueryReturn n);
        public:
        Response();
        Response(ResponseType tp, std::string data);
        QueryReturn FromText(std::string text);
        std::string getAsString();
        QueryReturn getStatus();
        ResponseType getResponse();
        std::string getData();
    };

}
#endif