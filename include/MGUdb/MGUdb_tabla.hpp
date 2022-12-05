/** Parte del proyecto MGUdb2
    Este módulo se encarga de las operaciones con tablas
    Fecha: 25/08/2022 11:50 a.m **/
#ifndef MGUDB_TABLA_HPP
#define MGUDB_TABLA_HPP

#include "MGUdb_archivo.hpp"
#include "MGUdb_etiqueta.hpp"
#include <vector>
#include <cstdio>

// Definimos el espacio de nombre
namespace mgu
{

    // Funciones
    bool esTabla(std::string);         // Verifica si la linea de texto es una tabla
    bool esElementoTabla(std::string); // Verifica si la linea es un elemento de la tabla

    /* Clase <<tabla>> principal */
    class MGUdb_tabla
    {
    private:
        //  Variables
        MGUdb_archivo *Archivo;
        std::string Nombre;
        unsigned int lni, lnf;
        std::vector<std::string> NombresColumnas;
        std::vector<eTIPO> TiposColumnas;
        buffer bf0;
        unsigned int ref;
        // Funciones
        unsigned int CbyN(std::string n);
        std::string CrearHeader();
        void OrganizaIndices();

    public:
        /* Crea una tabla
         * nombre(string): especifica el nombre de la tabla a crear
         * columnas(string): especifica el nombre de las columnas y sus tipos
         * ejemplo: mgu::CrearTabla("prueba", "c@nombre,e@edad", &file);
         * primero se debe colocar el tipo segido de '@' y luego el nombre (sin espacios)
         * para separar usa una coma (,)
         */
        bool CrearTabla(std::string nombre, std::string columnas);
        // Construcor por defecto
        MGUdb_tabla(MGUdb_archivo *fl);

        std::string GetNombre()
        {
            return this->Nombre;
        }
        // Destructor de la clase
        ~MGUdb_tabla();

        // Abrir una tabla, se especifica la linea donde se encuentra
        bool Cargar(unsigned int linea);

        // Limpia los datos de la clase
        void Limpiar();

        // Obtienes el numero de columnas
        unsigned int GetNColumnas();

        // Obtiene el nombre de las columas especificando el numero de columna
        std::string GetNombreColumna(unsigned int index);

        // Obtiene el tipo especificando el numero de columna
        eTIPO GetTipoColumna(unsigned int index);

        // Funciones para filas
        unsigned int GetNFilas();

        // Funciones para datos

        // Devuelve la fila donde se encontró
        // Devuelve -1 si no encuentra nada
        std::size_t BuscaEnLaTabla(std::string ncolumna, std::string a_buscar);
        // Recuperar datos desde la tabla
        std::string ObtenerCadena(unsigned int fila, std::string columna);
        int ObtenerEntero(unsigned int fila, std::string columna);
        double ObtenerDecimal(unsigned int fila, std::string columna);
        bool ObtenerBooleano(unsigned int fila, std::string columna);
        /*
         *   Agrega datos a la tabla
         *   Para colocar datos en la tabla se hace:
         *   por ejemplo si tienes dos columnas de cadenas escribes así
         *   "'hola','mundo'" en el mismo orden que se definieron las columnas
         *   si tienes datos sin valos escribes simplemente ''
         */
        bool AgregaDatosATabla(std::string datos);

        /* modifica datos en la tabla
         * Para agregar los datos se hace igual que en la función de Agregar datos
         * Cabe recordar que el tipo de datos a modificar debe ser el mismo que la columna
         * para cuando se necesita modificar una sola columna se debe colocar el dato entre las
         * comillas "mma"
         * ej:
         * Mod columna 2: "'', 'test', ''"
         * así se modificará las 3 columnas
         * para cuando se necesite modificar todas las columnas a la ves, se coloca el parametro <<forzado>> como true;
         */
        bool ModificaDatosATabla(unsigned int fila, std::string columna, std::string datos, bool forzado = false);

        // Elimina una fila de la tabla
        bool EliminarDatosDeTabla(unsigned int fila, std::string nombre_columna, bool borra_toda_la_fila = false);

        // Funciones para modificar la cantidad de columnas de la tabla
        bool AgregaColumna(std::string nombre, eTIPO t);
        bool EliminaColumna(std::string nombre);
        // Obtienes el buffer para guardar
        std::string GetFormateado();
        // Verifica si la tabla está vacía
        bool Vacia();
    };
} // namespace

#endif // MGUDB_TABLA_HPP
