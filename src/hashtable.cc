#include "hashtable.hpp"

HashTable::HashTable(){
    for(int i = 0; i < M; i++){
        tabela[i] = ListaEncadeada();
    }
}

int HashTable::funcaoHash(Verbete verbete){
    if(verbete.palavra[0] >= 'A' && verbete.palavra[0] <= 'Z'){
        return verbete.palavra[0] - 'A';
    }else{
        return verbete.palavra[0] - 'a' + 26;
    }
}

Verbete HashTable::buscarVerbete(Verbete verbete){
    int hash = funcaoHash(verbete);
    return tabela[hash].pesquisaItem(verbete);
}

void HashTable::inserirVerbete(Verbete verbete){
    int hash = funcaoHash(verbete);
    bool existe = tabela[hash].existeItem(verbete);

    if(existe){
        return;
    }
    
    tabela[hash].insereOrdemAlfabetica(verbete);
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