/** Parte del proyecto MGUdb2
    Este módulo se encarga de las operaciones con etiquetas
    Fecha: 17/08/2022 9:23 p.m **/

#ifndef MGUDB_ETIQUETA_HPP
#define MGUDB_ETIQUETA_HPP

#include <string>

namespace mgu
{
    enum eTIPO
    {
        CADENA = 3,
        ENTERO,
        DECIMAL,
        BOOLEANO,
        NINGUNO = 0
    };

    // Función de utilidad
    // Averigua si la sintaxis de una linea corresponde a una etiqueta
    // No verifica tipo de dato
    bool EsEtiqueta(std::string linea);
    extern std::string ObtenerDatos(std::string *datos, char i, char j);

    // Clase de etiquetas
    class MGUdb_etiqueta
    {
    public:
        // Los constructores asignan de forma automática los tipos y elementos
        MGUdb_etiqueta();
        MGUdb_etiqueta(std::string nombre, std::string datos);
        MGUdb_etiqueta(std::string nombre, int dato);
        MGUdb_etiqueta(std::string nombre, double dato);
        MGUdb_etiqueta(std::string nombre, bool dato);

        // Funciones para manupulación

        // Esta función crea una etique a partir de una linea de texto con sitanxis:
        //[ *nombre* ] *tipo*{ *datos* }
        bool CrearDesdeTexto(std::string texto);

        // Crea un linea con sintaxis de etiqueta, con los datos actuales, si no hay datos se devuelve una cadena nula
        std::string GetFormateado();

        // Esta función devuelve el tipo de datos actual
        eTIPO GetTipo();

        // Devuelve el nombre de la etiqueta actual
        std::string GetNombre();

        // Las siguiente funciones son para obtener el tipo de dato que sea necesario
        // Si se quiere obtener, por ejemplo, un entero siendo el dato actual una cadena obtendras un valor nulo.
        std::string GetCadena();
        int GetEntero();
        double GetDecimal();
        bool GetBooleano();
        // Algunas funciones para modificar los datos de la etiqueta
        void SetNombre(std::string nombre);
        void SetDatos(std::string dato);
        void SetDatos(int dato);
        void SetDatos(double dato);
        void SetDatos(bool dato);
        // Otras funciones de utilidad
        void Limpiar();

        ~MGUdb_etiqueta();

    private:
        std::string _nombre;
        std::string temp;
        eTIPO tipo;
        int datoi;
        double datod;
        bool datob;
    };
} // Namespace

#endif // MGUDB_ETIQUETA_HPP
