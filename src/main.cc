#include "arvorebalanceada.hpp"

int main(int argc, char* argv[]) {
    
    Verbete* raiz = NULL;
    raiz = inserirVerbete(raiz,"pera", "a", "aaaa");
    raiz = inserirVerbete(raiz,"morango", "a", "aaaa");
    raiz = inserirVerbete(raiz,"banana", "a", "aaaa");
    raiz = inserirVerbete(raiz,"jilo", "a", "aaaa");
    raiz = inserirVerbete(raiz,"pudim", "a", "aaaa");
    raiz = inserirVerbete(raiz,"lasanha", "a", "aaaa");
    raiz = inserirVerbete(raiz,"queijo", "a", "aaaa");
    raiz = inserirVerbete(raiz,"abacaxi", "a", "aaaa");
    raiz = inserirVerbete(raiz,"bucetaaaaaaaaaaaaa", "a", "aaaa");
    raiz = inserirVerbete(raiz,"bucetaaaaaaaaaaaaa", "a", "aaaa");
    raiz = inserirVerbete(raiz,"queijo", "a", "aaaa");
    raiz = inserirVerbete(raiz,"boraaaaaa", "a", "aaaa");
    std::string *comSignificado = new std::string;
    comSignificado = buscarPalavrasComSignificado(raiz,0);
    /*std::cout << raiz->palavra << std::endl;
    std::cout << raiz->filhoDireito-> palavra << std::endl;
    std::cout << raiz->filhoEsquerdo-> palavra << std::endl;*/
    printArvore(raiz, 0);
    return 0;

}