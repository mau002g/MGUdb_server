/** Parte del proyecto MGUdb2
    Este módulo se encarga de las operaciones de entrada y salidas de datos desde un archivo
    Fecha: 30/07/2022 10:40 a.m **/
#ifndef MGUDB_ARCHIVO_HPP
#define MGUDB_ARCHIVO_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "buffer.hpp"

#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif

namespace mgu
{
    enum STATUS
    {
        SINABRIR = 3,
        ERROR,
        CARGADO
    };

    // Clase principal
    class DLLIMPORT MGUdb_archivo
    {
    public:
        // Constructor por defecto
        MGUdb_archivo();

        // Abre un archivo especificado en "nombre", devuelve true si todo sale bien y false en caso contrario.
        bool Abrir(std::string nombre);

        // Cierra el archivo actual, devuelve true si todo sale bien y false en caso contrario.
        bool Cerrar();

        // Crea el archivo especificado en "nombre", devuelve true si todo sale bien y false en caso contrario.
        // Puede devolver false en caso de que el archivo ya exista, en caso de que exista se borra el contenido del mismo.
        bool Crear(std::string nombre);

        // Verifica si el archivo "nombre" existe, devuelve true si es así y false si no existe.
        bool Existe(std::string nombre);

        // Escribe una linea en el archivo, coloque 0 para escribir una linea al final
        bool EscribirLinea(std::string datos, unsigned int linea);

        // Remplaza una linea en el archivo
        bool RemplazarLinea(std::string datos, unsigned int linea);

        // Borra Una linea de un archivo
        bool BorrarLinea(unsigned int linea);

        // Obtiene una linea desde el archivo
        std::string ObtenerLinea(unsigned int linea);

        // Devuelve el numero de lineas del archivo
        unsigned int NumeroLineas();

        // Guarda los datos al archivo
        bool Guardar();

        void Limpiar();
        virtual ~MGUdb_archivo();

    private:
        std::fstream archivo;      // Manipulador del archivo.
        std::string NombreArchivo; // Guarda el nombre del archivo.
        buffer bf;
        unsigned short int estatus; // Lleva un control del archivo
    };
}

#endif // MGUDB_ARCHIVO_HPP
