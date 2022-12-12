#include "significados.hpp"

Significados::Significados(){
    numeroSignificados = 0;
    conteudo = new std::string[10000];
}

void Significados::adicionarSignificado(std::string significado){
    conteudo[numeroSignificados] = significado;
    numeroSignificados++;
}

void Significados::printSignificados(){
    for(int i = 0; i < numeroSignificados; i++){
        if(!conteudo->empty())
            std::cout << i + 1 << ". " << conteudo[i] << std::endl;
    }
}