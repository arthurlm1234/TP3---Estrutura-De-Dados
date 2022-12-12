#include "listaencadeada.hpp"

ListaEncadeada::ListaEncadeada(){
    primeiro = NULL;
    ultimo = NULL;
}

void ListaEncadeada::insereFinal(Verbete verbete){
    Verbete* novo = new Verbete;
    novo->palavra = verbete.palavra;
    novo->significados = verbete.significados;
    novo->altura = verbete.altura;
    novo->filhoEsquerdo = verbete.filhoEsquerdo;
    novo->filhoDireito = verbete.filhoDireito;
    novo->proximo = NULL;

    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }else{
        ultimo->proximo = novo;
        ultimo = novo;
    }
}

Verbete ListaEncadeada::removeItem(Verbete verbete){
    Verbete* aux = primeiro;
    Verbete* anterior = NULL;

    while(aux != NULL){
        if(aux->palavra == verbete.palavra){
            if(aux == primeiro){
                primeiro = primeiro->proximo;
                aux->proximo = NULL;
                return *aux;
            }else if(aux == ultimo){
                ultimo = anterior;
                anterior->proximo = NULL;
                return *aux;
            }else{
                anterior->proximo = aux->proximo;
                aux->proximo = NULL;
                return *aux;
            }
        }
        anterior = aux;
        aux = aux->proximo;
    }
}

Verbete ListaEncadeada::pesquisaItem(Verbete verbete){
    Verbete* aux = primeiro;

    while(aux != NULL){
        if(aux->palavra == verbete.palavra){
            return *aux;
        }
        aux = aux->proximo;
    }
}

void ListaEncadeada::printLista(){
    Verbete* aux = primeiro;

    while(aux != NULL){
        std::cout << aux->palavra << std::endl;
        aux = aux->proximo;
    }
}