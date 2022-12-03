#include <com_elements.hpp>
#include <stdexcept>

namespace
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
        decltype(len) i(0), ref(0);
        bool not_found(false);
        while (i < len)
        {
            // Search the first separator
            auto comma = str.find(separator, i);
            if (comma == std::string::npos)
            {
                comma = len;
            }
            if (CheckElements(&str, ref, comma, '"', &pos))
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
                             _id(0),
                             r(QNULL) {}

    AuthQuery::AuthQuery(std::string user, std::string SpecialKey, int ID) : _user(user),
                                                                             _special_key(SpecialKey),
                                                                             _id(ID),
                                                                             r(QNULL) {}
    AuthQuery::AuthQuery(std::string texto) : _user(""),
                                              _special_key(""),
                                              _id(0),
                                              r(QNULL) { this->FromText(texto); }
    // Funci�n para obtener desde una cadena de texto
    QueryReturn AuthQuery::FromText(std::string t)
    {
        std::vector<std::string> vt = sToVector(t, ';');
        std::string tuser, tsk;
        int tid(0);
        if (vt.empty() || (vt.size() != 4U))
        {
            r = QINVALID;
            return this->r;
        }
        if (vt[0] == "AUSO32")
        {
            tuser = vt[1];
            tsk = vt[2];
            try
            {
                tid = std::stoi(vt[3], nullptr);
            }
            catch (const std::invalid_argument &error)
            {
                tid = 0;
            }
        }
        else
        {
            this->r = QINVALID;
            return this->r;
        }
        this->_id = tid;
        this->_user = tuser;
        this->_special_key = tsk;
        this->r = QOK;
        return this->r;
    }
    QueryReturn AuthQuery::getStatus()
    {
        return this->r;
    }

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

    // Funci�n que devuelve el formato de cadena
    std::string AuthQuery::getAsString()
    {
        std::string temp("");
        temp += "\"AUSO32\";";
        temp = temp + "\"" + this->_user + "\";\"" + this->_special_key + "\";\"" + std::to_string(this->_id) + "\"";
        return temp;
    }

    //////////////////////
    ///@class AuthResponse
    //////////////////////
    AuthResponse::AuthResponse() : _status(NOTHING),
                                   r(QNULL) {}

    AuthResponse::AuthResponse(AuthResponseStatus s) : _status(s),
                                                       r(QNULL)
    {
    }
    AuthResponseStatus AuthResponse::getResponse()
    {
        return this->_status;
    }
    void AuthResponse::setResponse(AuthResponseStatus s)
    {
        this->_status = s;
    }

    QueryReturn AuthResponse::FromText(std::string t)
    {
        std::vector<std::string> vt = sToVector(t, ';');
        int rp(0);
        if (vt.empty() || (vt.size() != 2U))
        {
            r = QINVALID;
            return this->r;
        }
        if (vt[0] == "AURE32")
        {
            try
            {
                rp = std::stoi(vt[1], nullptr);
            }
            catch (const std::invalid_argument &error)
            {
                rp = 0;
            }
        }
        else
        {
            this->r = QINVALID;
            return this->r;
        }
        this->_status = static_cast<AuthResponseStatus>(rp);
        this->r = QOK;
        return this->r;
    }

    std::string AuthResponse::getAsString()
    {
        std::string temp;
        temp += "\"AURE32\";\"";
        temp += std::to_string(this->_status) + "\"";
        return temp;
    }

    ///////////////////////////////////////////////////////////
    /// @class Query
    ///////////////////////////////////////////////////////////

    // Constructor
    Query::Query(QueryType com, std::string p) : tp(com)
    {
        this->params = sToVector(p, ';');
        if (this->params.empty())
        {
            // No se defini� correctamente la lista de parametros
            this->tp = NO;
            this->r = QINVALID;
            return;
        }
    }
    QueryReturn Query::getStatus()
    {
        return this->r;
    }

    QueryReturn Query::FromText(std::string t)
    {
        unsigned int cmm(0U);
        std::vector<std::string> vec1 = sToVector(t, ';');
        std::vector<std::string> ttm;
        if (vec1.empty() || vec1.size() < 2U)
        {
            this->r = QINVALID;
            return this->r;
        }
        if (vec1[0] == "QRSOL")
        {
            try
            {
                cmm = std::stoul(vec1[1U], nullptr);
                if (!isComand(cmm))
                {
                    this->r = QINVALID;
                    return this->r;
                }
                for (auto i(2U); i < vec1.size(); i++)
                {
                    ttm.push_back(vec1[i]);
                }
                this->tp = static_cast<QueryType>(cmm);
                this->params = ttm;
                this->r = QOK;
                return this->r;
            }
            catch (const std::invalid_argument &)
            {
                this->r = QINVALID;
                return this->r;
            }
        }
        else
        {
            this->r = QINVALID;
        }
        // Tomamos todos los parametros

        return this->r;
    }
    bool Query::isComand(unsigned int c)
    {
        switch (c)
        {
        case COM:
            return true;
        default:
            return false;
        }
    }

    std::string Query::getParam(unsigned int index)
    {
        if (this->r != QINVALID)
        {
            return this->params[index];
        }
        else
            return "";
    }
    std::string Query::getAsString()
    {
        std::string temp("");
        temp += "\"QRSOL\";\"";
        temp += std::to_string(this->tp) + "\"";
        for (auto i = 0U; i < this->params.size(); ++i)
        {
            temp += ";\"";
            temp += this->params[i];
            temp += "\"";
        }
        return temp;
    }

    QueryType Query::getComand()
    {
        return this->tp;
    }
    unsigned int Query::getNParams()
    {
        return this->params.size();
    }
}
