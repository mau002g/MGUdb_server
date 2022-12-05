// nothing
#include <database_control.hpp>
#include <dirent.h>
#include <iostream>

namespace mgu
{
    db_control::~db_control()
    {
        this->xls();
    }
    void db_control::xls()
    {
        if (!this->dtbs.empty())
        {
            for (auto i = dtbs.begin(); i != this->dtbs.end(); ++i)
            {
                delete *i;
            }
            this->dtbs.clear();
        }
        std::cout << "[CERRANDO BASE DE DATOS]" << std::endl;
    }
    bool db_control::LoadDatabases()
    {
        if (this->dtb_index.empty())
            return true; // De segunro no hay bases de datos
        this->dtbs.clear();
        MGUdb *temp = nullptr;
        for (auto i = dtb_index.begin(); i != this->dtb_index.end(); ++i)
        {
            temp = new MGUdb;
            if (!temp->UseDB(this->defdir + "/" + *i))
            {
                delete temp;
                this->xls();
                std::cout << "!NO SE HAN PODIDO CARGAR UNA BASE DE DATOS PORQUE CONTIENE ERRORES." << std::endl;
                return false;
            }
            *i = (*i).substr(0, (*i).length() - ((*i).rfind('.', (*i).length())));
            
            this->dtbs.push_back(temp);
            temp = nullptr;
        }
        return true;
    }
    bool db_control::CreateDatabaseIndexOn(std::string dir)
    {
        std::vector<std::string> dna;
        DIR *directory;
        dirent *elements;
        if ((directory = opendir(dir.c_str())))
        {
            while ((elements = readdir(directory)))
            {
                if (std::string(elements->d_name) != "." && std::string(elements->d_name) != "..")
                {
                    dna.push_back(elements->d_name);
                }
            }
        }
        else
        {
            return false;
        }
        if (dna.empty())
        {
            std::cout << "[?] No hay base de datos." << std::endl;
            return false;
        }
        dtb_index = dna;
        return true;
    }

    bool db_control::isConfig()
    {
        MGUdb f;
        if (!f.UseDB("aff3/4f52.xb"))
        {
            return false;
        }
        if (f.getStringFromTag("defdir").empty())
        {
            return false;
        }
        if (f.GetTableRows("main") == 0)
        {
            return false;
        }
        return true;
    }
    void db_control::MakeConfig()
    {
        std::string dedir("");
        std::string rootpaswd("");
        std::cout << "[CONFIGURACIÓN]" << std::endl;
        std::cout << "Escriba el directorio raiz de las base de datos." << std::endl;
        std::cout << "puede pulsar [ENTER] para usar el directorio por defecto:";
        std::getline(std::cin, dedir);
        std::cout << std::endl;
        if (dedir.empty())
            dedir = DEFDIR;
        std::cout << "¡Porfavor! Debe crear una contraseña de root : ";
        std::getline(std::cin, rootpaswd);
        std::cout << std::endl
                  << "[PROCESANDO...]" << std::endl;
        MGUdb confi;
        if (confi.UseDB("aff3/4f52.xb"))
        {
            confi.Clean();
            confi.CreateTag("defdir", std::string(dedir));
            confi.CreateTable("main", "c@ser,c@pwds");
            confi.AddDataToTable("main", "'root','" + rootpaswd + "'");
            confi.FlushDB();
        }
        else
        {
            std::cout << "Error Faltal... :?" << std::endl;
            return;
        }
        std::cout << "[PROCESADO]" << std::endl;
    }
    MGUdb *db_control::ref_by_name(std::string name)
    {
        for(auto i(0U); i < this->dtb_index.size(); i++)
        {
            if(this->dtb_index[i] == name)
            {
                return this->dtbs[i];
            }
        }
        return nullptr;
    }

    void db_control::LoadConfig()
    {
        MGUdb db;
        if (!db.UseDB("aff3/4f52.xb"))
        {
            std::cout << "No se pudo leer la configuración" << std::endl;
            this->conf = false;
            return;
        }
        this->defdir = db.getStringFromTag("defdir");
    }
    bool db_control::Start()
    {
        // Primero creamos la configuración
        std::cout << "[CARGANDO LA CONFIGURACIÓN]" << std::endl;
        if (!this->isConfig())
        {
            this->MakeConfig();
        }
        this->LoadConfig();
        std::cout << "[CARGANDO LAS BASE DE DATOS]" << std::endl;
        if (!CreateDatabaseIndexOn(this->defdir))
            return false;
        return this->LoadDatabases();
    }
    Response db_control::Process(Query sol)
    {
        
    }
}