#include <iostream>

#ifndef VERBETE_HPP
#define VERBETE_HPP

class Verbete{

    private:
        std::string palavra;
        std::string classeMorfologica;
        std::string significados;
        int contSignificados;
        int altura;
        Verbete* filhoEsquerdo;
        Verbete* filhoDireito;
        Verbete* pai;

    public:
        Verbete(int altura, std::string palavra, std::string classeMorfologica, std::string significado);
        std::string getPalavra();
        std::string getSignificado();
        std::string getClasseMorfologica();
        void setSignificado(std::string significado);
        bool comSignificado();
        void printVerbete();
    
    friend class AVL;
};

#endif