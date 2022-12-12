#include "verbete.hpp"

#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

class ListaEncadeada{
    public:
        Verbete* primeiro;
        Verbete* ultimo;
        ListaEncadeada();
        void insereFinal(Verbete verbete);
        Verbete removeItem(Verbete verbete);
        Verbete pesquisaItem(Verbete verbete);
        void printLista();
};

#endif