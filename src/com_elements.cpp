#include <com_elements.hpp>

namespace mgu
{
    //Clase AuthQuery
    AuthQuery::AuthQuery() :
        _user(""),
        _special_key(""),
        _id(0) { }
    AuthQuery::AuthQuery(std::string user, std::string SpecialKey, int ID) : 
        _user(user),
        _special_key(SpecialKey),
        _id(ID) { }
    
    //Funciones IO
    std::string AuthQuery::getUser()
    {
        return this->_user;
    }
    std::string AuthQuery::getSpecialKey()
    {
        return this->_special_key;
    }
    int AuthQuery::getID()
    {
        return this->_id;
    }
    void AuthQuery::setUser(std::string u)
    {
        this->_user = u;
    }
    void AuthQuery::setSpecialKey(std::string sk)
    {
        this->_special_key = sk;
    }
    void AuthQuery::setID(int i)
    {
        this->_id = i;
    }

    //Función que devuelve el formato de cadena
    std::string AuthQuery::getAsString()
    {
        std::string temp("");
        temp += "MGUAR32;";
        temp = temp + "\"" + this->_user + "\";\"" + this->_special_key + "\";\"" + std::to_string(this->_id) + "\"";
        return temp;
    }
}
