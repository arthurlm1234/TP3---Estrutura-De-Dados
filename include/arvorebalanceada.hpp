#include "verbete.hpp"

#ifndef ARVOREBALANCEADA_HPP
#define ARVOREBALANCEADA_HPP

//balanced tree verbete
class AVL{

    private:

        Verbete* raiz;
    
    public:

        void pesquisarAVL(Verbete *verbete);
        void inserirAVL(Verbete *verbete);
        void printAVL();
        void removerVerbetesComSignificado();
        void destruirAVL();
        int fatorBalanceamentoVerbete(Verbete* verbete);
        void rotacaoEsquerda(Verbete* verbete);
        void rotacaoDireita(Verbete* verbete);
        void balancearAVL();
};

#endif