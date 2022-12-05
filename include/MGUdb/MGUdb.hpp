/** Parte del proyecto MGUdb2
    Este módulo se encarga de las operaciones de DB
    Fecha: 27/09/2022 4:06 p.m **/

#ifndef MGUDB_HPP
#define MGUDB_HPP

#include "MGUdb_tabla.hpp"

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

namespace mgu
{
    // Clase principal
    class DLLIMPORT MGUdb
    {
    public:
        MGUdb(): estatus(false) {}
        //**Operaciones de la base de datos**
        //Función que  crea un base de datos, no la abre de una vez
		bool Create(std::string ruta);
        //Borra una base de datos
        bool Delete(std::string ruta);
        // Clean()
        void Clean();
        // Abre Una base de datos
        bool UseDB(std::string ruta);

        // Operaciones con etiquetas
        bool CreateTag(std::string nombre, std::string dato);
        bool CreateTag(std::string nombre, int dato);
        bool CreateTag(std::string nombre, double dato);
        bool CreateTag(std::string nombre, bool dato);
        bool DeleteTag(std::string nombre);
        std::string getStringFromTag(std::string nombre); // Obtiene los  datos de la etiqueta especificada en formato de cadena(Varchar), el tipo de de la etiqueta debe ser tambien cadena
        int getIntFromTag(std::string nombre);            // Lo mismo que lo anterior pero para enteros
        double getDecimalFromTag(std::string nombre);      // Ahora para decimales
        bool getBooleanFromTag(std::string nombre);       // Finalmente para boleanos
        bool ModTag(std::string nombre, std::string dato); //Modifca el dato de una etiqueta, se harán cuanto funciones para cada caso
		bool ModTag(std::string nombre, int dato);
		bool ModTag(std::string nombre, double dato);
		bool ModTag(std::string nombre, bool dato);
        // Obtener numero de tablas y etiquetas
        unsigned int NTablas();
        unsigned int NEtiquetas();

        //**Operaciones para tablas
        /* La función CreateTable crea una tabla, nombre especifica el nombre de la tabla...
		en columnas se debe especficar así: c@nombre,c@passwd eso especifica dos columnas que contienen cadenas y se llaman nombre y passwd */
		bool CreateTable(std::string nombre, std::string columnas);
        bool DeleteTable(std::string nombre);//Borra la tabla especificada
        bool AddDataToTable(std::string nombre, std::string datos);//Añade datos a la tabla
        bool RemoveDataFromTable(std::string nombre, unsigned int fila, std::string columna, bool toda_la_fila = false);//Borra Datos de la tabla
        unsigned int SearchInTable(std::string nombre, std::string columna, std::string cosa_a_buscar);//Busca en la columna y devuelve la posición en caso de encontrarlo
        std::string getStringFromTable(std::string nombre, std::string columna, unsigned int indice);//Obtiene datos desde una tabla
		int getIntFromTable(std::string nombre, std::string columna, unsigned int indice);//Para entero
		double getDecimalFromTable(std::string nombre, std::string columna, unsigned int indice);//Para decimales
		bool getBooleanFromTable(std::string nombre, std::string columna, unsigned int indice);//para boleanos
        bool ModDataFromTable(std::string nombre, std::string columna, unsigned int fila, std::string datos, bool modificar_todas_las_columnas = false);//Modifica las columnas completas de una fila
        bool AddColumnToTable(std::string nombre, std::string columna, eTIPO tipos_de_dato_columa);
        bool RemoveColumnFromTable(std::string nombre, std::string columna);

        unsigned int GetTableRows(std::string nombre); //Obtinenes las filas de las tablas
        unsigned int GetTableColumns(std::string nombre); //Obtienes las columnas de las tablas
        
        //Funciones para obtener el nombre de las etiquetas y las tablas
        std::string getTagName(unsigned int index);
        std::string getTableName(unsigned int index);
        std::string getTableColumnsName(std::string tname, unsigned int cindex);
        eTIPO getTagType(std::string nombre); //Obtiene el tipo de la etiqueta
        eTIPO getTableColumnsType(std::string nombre, unsigned int cindex); //cindes desde 0 hasta GetTableColumns

        void FlushDB();
        // Destructor
        ~MGUdb();

    private:
        bool estatus;
        std::vector<MGUdb_etiqueta *> etq; // Guarda las etiquetas
        std::vector<MGUdb_tabla *> tbl;    // Guarda las tablas
        MGUdb_archivo file;                // Manejador de archivo
        unsigned int ExisteEtiqueta(std::string nombre);
        unsigned int ExisteTabla(std::string nombre);
    };
} // Namespace

#endif // MGUDB_HPP
