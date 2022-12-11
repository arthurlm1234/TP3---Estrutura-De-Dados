#include "significados.hpp"

#ifndef VERBETE_HPP
#define VERBETE_HPP

class Verbete{

    public:
        std::string palavra;
        Significados significados;
        int altura;
        Verbete* filhoEsquerdo;
        Verbete* filhoDireito;
};

#endif