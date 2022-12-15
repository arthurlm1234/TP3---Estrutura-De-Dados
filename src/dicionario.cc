#include "dicionario.hpp"
#include "arvorebalanceada.hpp"

Dicionario::Dicionario(std::string _output){
    raiz = NULL;
    hashtable = new HashTable();
    output = _output;
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

void Dicionario::printArvoreAVLFinal(Verbete* v, int nivel){
    printArvoreFinal(v, nivel);
}

void Dicionario::destruirArvoreAVL(Verbete* v){
    destruirArvore(v);
}

void Dicionario::inserirVerbeteHT(std::string palavra, std::string significado){
    hashtable->inserirVerbete(Verbete(palavra, significado));
}

bool Dicionario::existePalavraSemSignificadoAVL(Verbete* v, int nivel){
    return existePalavraSemSignificado(v, nivel);
}

void Dicionario::deletarVerbeteHT(std::string palavra){
    hashtable->deletarVerbete(palavra);
}

void Dicionario::deletarPalavrasComSignificadoHT(){
    hashtable->deletarVerbetesComSignificado();
}

void Dicionario::printHT(){
    hashtable->printTabela();
}

void Dicionario::destruirHT(){
    hashtable->destruirTabela();
}