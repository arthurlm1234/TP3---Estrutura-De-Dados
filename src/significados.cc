#include "significados.hpp"

Significados::Significados(){
    numeroSignificados = 0;
    conteudo = new std::string[1000];
}

void Significados::adicionarSignificado(std::string significado){
    conteudo[numeroSignificados] = significado;
    numeroSignificados++;
}

bool Significados::possuiSignificado(){
    for(int i = 0; i < numeroSignificados; i++){
        if(conteudo[i] != "")
            return true;
    }
    return false;
}

std::ostringstream Significados::printSignificados(){
    int cont  = 1;
    std::ostringstream oss;

    for(int i = 0; i < numeroSignificados; i++){
        if(conteudo[i] != ""){
            oss << cont << ". " << conteudo[i] << std::endl;
            cont++;
        }
    }

    return oss;
}