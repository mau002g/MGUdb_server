#include <com_elements.hpp>
#include <vector>
#include <string>

namespace mgu
{
    bool CheckElements(std::string *str, std::size_t beg, std::size_t end, char cc, std::vector<std::size_t> *pos)
    {
        auto pos1(std::string::npos), pos2(std::string::npos);
        pos1 = str->find(cc, beg);
        pos2 = str->rfind(cc, end);

        if (pos1 == std::string::npos ||
            pos2 == std::string::npos ||
            pos2 == pos1)
        {
            pos->clear();
            return false;
        }

        pos->clear();
        pos->push_back(++pos1);
        pos->push_back(pos2 - pos1);
        return true;
    }

    std::vector<std::string> sToVector(std::string str, char separator)
    {
        std::vector<std::string> temp;
        std::vector<std::size_t> pos;
        std::string data("");
        std::size_t len = str.length();
        decltype(len) i(0), ref;
        bool not_found(false);
        while (i < len)
        {
            // Search the first separator
            auto comma = str.find(separator, i);
            if (comma == std::string::npos)
            {
                comma = len;
            }
            if (CheckElements(&str, ref, comma, '\'', &pos))
            {
                not_found = false;
                data.clear();
                data = str.substr(pos[0], pos[1]);
                temp.push_back(data);
                i = comma + 1U;
                ref = i;
            }
            else
            {
                if (!not_found)
                    ref = i;
                not_found = true;
                i = comma + 1U;
            }
        }
        if (not_found)
            temp.clear();
        return temp;
    }
}

namespace mgu
{
    // Clase AuthQuery
    AuthQuery::AuthQuery() : _user(""),
                             _special_key(""),
                             _id(0) {}
    AuthQuery::AuthQuery(std::string user, std::string SpecialKey, int ID) : _user(user),
                                                                             _special_key(SpecialKey),
                                                                             _id(ID) {}

    // Funciones IO
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

    // Función que devuelve el formato de cadena
    std::string AuthQuery::getAsString()
    {
        std::string temp("");
        temp += "MGUAR32;";
        temp = temp + "\"" + this->_user + "\";\"" + this->_special_key + "\";\"" + std::to_string(this->_id) + "\"";
        return temp;
    }
}
