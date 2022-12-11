#include "dicionario.hpp"
#include "arvorebalanceada.hpp"

Dicionario::Dicionario(){
    raiz = NULL;
}

void Dicionario::inserirVerbeteAVL(std::string palavra, std::string significado){
    raiz = inserirVerbete(raiz, palavra, significado);
}

void Dicionario::deletarVerbeteAVL(std::string palavra){
    raiz = deletarVerbete(raiz, palavra);
}

void Dicionario::deletarPalavrasComSignificadoAVL(Verbete* v, int nivel){
    buscarPalavrasComSignificado(v, nivel);

    for(int i = 0; i < cont; i++){
        deletarVerbete(raiz, palavras[i]);
    }
}

void Dicionario::printArvoreAVL(Verbete* v, int nivel){
    printArvore(v, nivel);
}