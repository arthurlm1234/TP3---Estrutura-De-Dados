#include "hashtable.hpp"

HashTable::HashTable(){
    for(int i = 0; i < M; i++){
        tabela[i] = ListaEncadeada();
    }
}

int HashTable::funcaoHash(Verbete verbete){
    int hash = 0;
    for(int i = 0; i < verbete.palavra.length(); i++){
        hash += verbete.palavra[i];
    }
    return hash % M;
}

Verbete HashTable::buscarVerbete(Verbete verbete){
    int hash = funcaoHash(verbete);
    return tabela[hash].pesquisaItem(verbete);
}

void HashTable::inserirVerbete(Verbete verbete){
    int hash = funcaoHash(verbete);
    tabela[hash].insereFinal(verbete);
}

void HashTable::deletarVerbete(Verbete verbete){
    int hash = funcaoHash(verbete);
    tabela[hash].removeItem(verbete);
}

void HashTable::printTabela(){
    for(int i = 0; i < M; i++){
        tabela[i].printLista();
    }
}