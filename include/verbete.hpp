#include "significados.hpp"
#include <fstream>

#ifndef VERBETE_HPP
#define VERBETE_HPP

class Verbete{

    public:

        std::string palavra;
        Significados significados;
        int altura;
        Verbete* filhoEsquerdo;
        Verbete* filhoDireito;
        Verbete* proximo;
        /*bool possuiSignificados(){
            return significados.possuiSignificado;
        }*/

        Verbete(std::string _palavra = "", std::string _significado = "")
        {
            palavra = _palavra;
            significados.adicionarSignificado(_significado);
            altura = 0;
            filhoEsquerdo = NULL;
            filhoDireito = NULL;
            proximo = NULL;
        }
};

#endif