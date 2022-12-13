#include "significados.hpp"

Significados::Significados(){
    numeroSignificados = 0;
    conteudo = new std::string[1000];
}

void Significados::adicionarSignificado(std::string significado){
    //std::cout << "adicionando significado" << std::endl;
    conteudo[numeroSignificados] = significado;
    numeroSignificados++;
}

bool Significados::possuiSignificado(){
    for(int i = 0; i < numeroSignificados; i++){
        if(!conteudo->empty())
            return true;
    }
    return false;
}

void Significados::printSignificados(){
    for(int i = 0; i < numeroSignificados; i++){
        if(!conteudo->empty())
            std::cout << i + 1 << ". " << conteudo[i] << std::endl;
    }
}