/* Este archivo es parte de MGUdb */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string>
#include <vector>

namespace mgu
{
  enum TW
  {
    LR = 0x9, /* Remplazando una línea */
    F,        /* Añadiendo una linea al final */
    A,        /* Añadiendo una linea en la línea especificada */
  };

  //////////////////////////////////////////////////////////////////////
  /// @class buffer
  /// @brief Este clase se encarga de almacenar y administrar los datos,
  /// por lo que sirve de alamcén en memoria para texto.
  //////////////////////////////////////////////////////////////////////
  class buffer
  {
  public:
    /* Constructor */
    buffer();
    /* Destructor */
    ~buffer();

    ////////////////////////////////////////////////////////////////////
    /// @function GetLine
    /// @param line(unsigned int) -> especifica el numero de linea.
    /// @return std::string -> Devuelve el contenido de la linea
    /// especificada con el parámetro (line). Si la linea especificada
    /// no existe ó si ha habido algún error la función devuele una
    /// cadena vacía.
    /// @brief Este función permite extraer una linea de texto desde
    /// el buffer especificando el numero de linea a travéz del argumeto
    /// (line).
    ////////////////////////////////////////////////////////////////////
    std::string GetLine(unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function WriteLine
    /// @param data(string) -> datos a escribir.
    /// @param tipo(TW) -> especifica que tipo de escritura se realiza.
    /// @param line(unsigned int) -> especifica un numero de línea.
    /// @return bool -> Devuelve false si ha habido algún error y true
    /// si todo ha salido bien.
    /// @brief Este función sirve para escribir datos en el buffer
    /// el buffer a escribir se especifica con el parámetro (data).
    /// Hay varias formas de escribir en el buffer:
    /// 1)Reemplazando una linea especificada
    /// 2)Añadiendo una línea al final
    /// 3)Añadiendo una línea especificada
    /// Para reemplazar o añadir una línea se debe especificar un número
    /// de line válido a travéz del parámetro (line). Cuando simplemente
    /// se añande una linea al final el parámetro (line) debe ser cero.
    ////////////////////////////////////////////////////////////////////
    bool WriteLine(std::string data, TW tipo, unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function DeleteLine
    /// @param line(unsigned int) -> especifica un número de línea
    /// @return bool -> Devuelve true si todo ha salido bien y en
    /// caso contraro false.
    /// @brief Esta función sirve para borrar una línea del buffer.
    ////////////////////////////////////////////////////////////////////
    bool DeleteLine(unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function GetNlines
    /// @param Sin parámetros
    /// @return unsigned int -> Devueleve el numero de lineas.
    /// @brief :)
    ////////////////////////////////////////////////////////////////////
    unsigned int GetNlines();

    ////////////////////////////////////////////////////////////////////
    /// @function GetBuffer
    /// @param Sin parámetros
    /// @brief
    ////////////////////////////////////////////////////////////////////
    std::string GetBuffer();

    ////////////////////////////////////////////////////////////////////
    /// @function ClearBuffer
    /// @param Sin parámetros
    /// @return Sin valor de retorno
    /// @brief Limpia el contenido del buffer
    ////////////////////////////////////////////////////////////////////
    void ClearBuffer();

  private:
    std::vector<std::string *> ab;
    unsigned int cursol;
  };
}

#endif // BUFFER_HPP
