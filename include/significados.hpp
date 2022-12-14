#include <iostream>
#include <fstream>
#include <sstream>

#ifndef SIGNIFICADOS_HPP
#define SIGNIFICADOS_HPP

class Significados{
    public:
        Significados();
        std::string* conteudo;
        int numeroSignificados;
        void adicionarSignificado(std::string significado);
        bool possuiSignificado();
        std::ostringstream printSignificados();

    friend class Verbete;
};

#endif