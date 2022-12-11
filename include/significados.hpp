#include <iostream>

#ifndef SIGNIFICADOS_HPP
#define SIGNIFICADOS_HPP

class Significados{
    public:
        Significados();
        std::string* conteudo;
        int numeroSignificados;
        void adicionarSignificado(std::string significado);
        void printSignificados();

    friend class Verbete;
};

#endif