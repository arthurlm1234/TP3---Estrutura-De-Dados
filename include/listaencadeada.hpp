#include "verbete.hpp"

#ifndef LISTAENCADEADA_HPP
#define LISTAENCADEADA_HPP

class ListaEncadeada{
    public:
        ~ListaEncadeada();
        Verbete* primeiro;
        Verbete* ultimo;
        ListaEncadeada();
        void insereOrdemAlfabetica(Verbete verbete);
        Verbete removeItem(Verbete verbete);
        Verbete pesquisaItem(Verbete verbete);
        bool existeItem(Verbete verbete);
        void removeComSignificado();
        void printLista();
};

#endif