#include "dicionario.hpp"

int main(int argc, char* argv[]) {

    /*Dicionario* dicionario = new Dicionario();
    dicionario->inserirVerbeteAVL("pera", "aaaa");
    dicionario->inserirVerbeteAVL("morango", "aaaa");
    dicionario->inserirVerbeteAVL("mouse", "");
    dicionario->inserirVerbeteAVL("cachorro", "");
    dicionario->inserirVerbeteAVL("morango", "bbb");

    dicionario->printArvoreAVL(dicionario->raiz, 0);
    dicionario->deletarPalavrasComSignificadoAVL(dicionario->raiz, 0);
    std::cout << std::endl;
    dicionario->printArvoreAVL(dicionario->raiz, 0);*/

   /* HashTable *hashTable = new HashTable();

    hashTable->inserirVerbete(Verbete("pera", "aaaa"));
    hashTable->inserirVerbete(Verbete("morango", "aaaa"));
    hashTable->inserirVerbete(Verbete("mouse", ""));
    hashTable->inserirVerbete(Verbete("cachorro", ""));
    hashTable->inserirVerbete(Verbete("morango", "bbb"));
    hashTable->inserirVerbete(Verbete("ameixa", "bbb"));
    hashTable->inserirVerbete(Verbete("Cha", "bbb"));
    hashTable->inserirVerbete(Verbete("banana", "bbb"));
    hashTable->inserirVerbete(Verbete("abacaxi", "bbb"));
    hashTable->inserirVerbete(Verbete("abacate", "bbb"));
    hashTable->inserirVerbete(Verbete("cha", "bbb"));
    hashTable->inserirVerbete(Verbete("Cha", "bbbuceta"));
    hashTable->inserirVerbete(Verbete("Mar", ""));
    
    hashTable->imprimirVerbetesSemSignificado();*/

    Dicionario* dicionario = new Dicionario();

    dicionario->inserirVerbeteHT("pera", "aaaa");
    dicionario->inserirVerbeteHT("morango", "aaaa");
    dicionario->inserirVerbeteHT("mouse", "");
    dicionario->inserirVerbeteHT("cachorro", "");
    dicionario->inserirVerbeteHT("morango", "bbb");
    dicionario->inserirVerbeteHT("ameixa", "bbb");
    dicionario->inserirVerbeteHT("Cha", "bbb");
    dicionario->inserirVerbeteHT("banana", "bbb");
    dicionario->inserirVerbeteHT("abacaxi", "bbb");

    dicionario->printHT();
    dicionario->imprimirPalavrasSemSignificadoHT();

    return 0;

}