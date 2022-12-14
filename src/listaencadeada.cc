#include "listaencadeada.hpp"

ListaEncadeada::ListaEncadeada(){
    primeiro = NULL;
    ultimo = NULL;
}

ListaEncadeada::~ListaEncadeada(){
    Verbete* aux = primeiro;
    Verbete* proximo = NULL;

    while(aux != NULL){
        proximo = aux->proximo;
        delete aux;
        aux = proximo;
    }
}

void ListaEncadeada::insereOrdemAlfabetica(Verbete verbete){
    Verbete* novo = new Verbete;
    novo->palavra = verbete.palavra;
    novo->significados = verbete.significados;
    novo->proximo = NULL;

    if(primeiro == NULL){
        primeiro = novo;
        ultimo = novo;
    }else{
        Verbete* aux = primeiro;
        Verbete* anterior = NULL;

        while(aux != NULL){
            LEMEMLOG((long int)(&aux), sizeof(aux),0);
            if(aux->palavra > verbete.palavra){
                if(aux == primeiro){
                    primeiro = novo;
                    novo->proximo = aux;
                    return;
                }else{
                    anterior->proximo = novo;
                    novo->proximo = aux;
                    return;
                }
            }
            anterior = aux;
            aux = aux->proximo;
        }
        ultimo->proximo = novo;
        ultimo = novo;
    }
}

Verbete ListaEncadeada::removeItem(Verbete verbete){
    Verbete* aux = primeiro;
    Verbete* anterior = NULL;

    while(aux != NULL){
        LEMEMLOG((long int)(&aux), sizeof(aux),0);
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

    return *aux;
}

Verbete ListaEncadeada::pesquisaItem(Verbete verbete){
    Verbete* aux = primeiro;

    while(aux != NULL){
        LEMEMLOG((long int)(&aux), sizeof(aux),0);
        if(aux->palavra == verbete.palavra){
            return *aux;
        }
        aux = aux->proximo;
    }

    return *aux;
}

bool ListaEncadeada::existeItem(Verbete verbete){
    Verbete* aux = primeiro;


    while(aux != NULL){
        LEMEMLOG((long int)(&aux), sizeof(aux),0);
        if(aux->palavra == verbete.palavra){
            if(verbete.significados.conteudo[0].size() == 0)
                return true;
            
            aux->significados.adicionarSignificado(verbete.significados.conteudo[0]);
            return true;
        }
        aux = aux->proximo;
    }
    return false;
}

void ListaEncadeada::removeComSignificado(){

    Verbete* aux = primeiro;
    Verbete* anterior = NULL;


    while(aux != NULL){
        LEMEMLOG((long int)(&aux), sizeof(aux),0);
        if(aux->significados.possuiSignificado()){
            if(aux == primeiro){
                primeiro = primeiro->proximo;
                aux->proximo = NULL;
                aux = primeiro;
            }else if(aux == ultimo){
                ultimo = anterior;
                anterior->proximo = NULL;
                aux = NULL;
            }else{
                anterior->proximo = aux->proximo;
                aux->proximo = NULL;
                aux = anterior->proximo;
            }
        }else{
            anterior = aux;
            aux = aux->proximo;
        }
    }
}

void ListaEncadeada::printLista(){
    std::ofstream arquivo;
    arquivo.open("output.txt", std::ios::out | std::ios::app);
    
    Verbete* aux = primeiro;

    while(aux != NULL){
        LEMEMLOG((long int)(&aux), sizeof(aux),0);
        arquivo << aux->palavra << std::endl;
        arquivo << aux->significados.printSignificados().str();
        aux = aux->proximo;
    }
}