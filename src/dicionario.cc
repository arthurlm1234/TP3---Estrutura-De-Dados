#include "dicionario.hpp"
#include "arvorebalanceada.hpp"

Dicionario::Dicionario(){
    raiz = NULL;
    hashtable = new HashTable();
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

void Dicionario::destruirArvoreAVL(Verbete* v){
    destruirArvore(v);
}

void Dicionario::inserirVerbeteHT(std::string palavra, std::string significado){
    hashtable->inserirVerbete(Verbete(palavra, significado));
}

void Dicionario::deletarVerbeteHT(std::string palavra){
    hashtable->deletarVerbete(palavra);
}

void Dicionario::imprimirPalavrasSemSignificadoHT(){
    hashtable->imprimirVerbetesSemSignificado();
}

void Dicionario::printHT(){
    hashtable->printTabela();
}

void Dicionario::destruirHT(){
    hashtable->destruirTabela();
}