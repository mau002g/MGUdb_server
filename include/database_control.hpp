#ifndef DATABASE_CONTROL
#define DATABASE_CONTROL

#include <string>
#include <vector>
#include <MGUdb/MGUdb.hpp>
#include "com_elements.hpp"

#define DEFDIR "2fc25"
#define CONFIGDIR "aff3"
#define CONFIG_FILE "4f52.xb"

namespace mgu   
{
    class db_control
    {
        private:
        bool conf;
        std::string defdir;
        std::vector<MGUdb*> dtbs;
        std::vector<std::string> dtb_index;
        bool CreateDatabaseIndexOn(std::string directorio);
        bool isConfig();
        void MakeConfig();
        void LoadConfig();
        void xls();
        bool LoadDatabases();
        MGUdb *ref_by_name(std::string name);
        public:
        db_control() {}
        ~db_control();
        bool Start();
        //Recibe una Query como cadena, procesa y devuelve un Response en forma de cadena
        std::string Process(std::string q);
    };
}

#endif