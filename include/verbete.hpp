#include <iostream>

#ifndef VERBETE_HPP
#define VERBETE_HPP

class Verbete{

    public:
        std::string palavra;
        std::string classeMorfologica;
        std::string significados;
        int altura;
        Verbete* filhoEsquerdo;
        Verbete* filhoDireito;
};

#endif