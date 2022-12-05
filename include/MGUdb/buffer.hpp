/* Este archivo es parte de MGUdb */

#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <string>
#include <vector>

namespace mgu
{
  enum TW
  {
    LR = 0x9, /* Remplazando una l�nea */
    F,        /* A�adiendo una linea al final */
    A,        /* A�adiendo una linea en la l�nea especificada */
  };

  //////////////////////////////////////////////////////////////////////
  /// @class buffer
  /// @brief Este clase se encarga de almacenar y administrar los datos,
  /// por lo que sirve de alamc�n en memoria para texto.
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
    /// especificada con el par�metro (line). Si la linea especificada
    /// no existe � si ha habido alg�n error la funci�n devuele una
    /// cadena vac�a.
    /// @brief Este funci�n permite extraer una linea de texto desde
    /// el buffer especificando el numero de linea a trav�z del argumeto
    /// (line).
    ////////////////////////////////////////////////////////////////////
    std::string GetLine(unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function WriteLine
    /// @param data(string) -> datos a escribir.
    /// @param tipo(TW) -> especifica que tipo de escritura se realiza.
    /// @param line(unsigned int) -> especifica un numero de l�nea.
    /// @return bool -> Devuelve false si ha habido alg�n error y true
    /// si todo ha salido bien.
    /// @brief Este funci�n sirve para escribir datos en el buffer
    /// el buffer a escribir se especifica con el par�metro (data).
    /// Hay varias formas de escribir en el buffer:
    /// 1)Reemplazando una linea especificada
    /// 2)A�adiendo una l�nea al final
    /// 3)A�adiendo una l�nea especificada
    /// Para reemplazar o a�adir una l�nea se debe especificar un n�mero
    /// de line v�lido a trav�z del par�metro (line). Cuando simplemente
    /// se a�ande una linea al final el par�metro (line) debe ser cero.
    ////////////////////////////////////////////////////////////////////
    bool WriteLine(std::string data, TW tipo, unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function DeleteLine
    /// @param line(unsigned int) -> especifica un n�mero de l�nea
    /// @return bool -> Devuelve true si todo ha salido bien y en
    /// caso contraro false.
    /// @brief Esta funci�n sirve para borrar una l�nea del buffer.
    ////////////////////////////////////////////////////////////////////
    bool DeleteLine(unsigned int line);

    ////////////////////////////////////////////////////////////////////
    /// @function GetNlines
    /// @param Sin par�metros
    /// @return unsigned int -> Devueleve el numero de lineas.
    /// @brief :)
    ////////////////////////////////////////////////////////////////////
    unsigned int GetNlines();

    ////////////////////////////////////////////////////////////////////
    /// @function GetBuffer
    /// @param Sin par�metros
    /// @brief
    ////////////////////////////////////////////////////////////////////
    std::string GetBuffer();

    ////////////////////////////////////////////////////////////////////
    /// @function ClearBuffer
    /// @param Sin par�metros
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
