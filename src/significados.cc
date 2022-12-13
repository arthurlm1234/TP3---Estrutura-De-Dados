#include "significados.hpp"

Significados::Significados(){
    numeroSignificados = 0;
    conteudo = new std::string[1000];
}

void Significados::adicionarSignificado(std::string significado){
   //std::cout << "Adicionando significado: " << significado << std::endl;
    conteudo[numeroSignificados] = significado;
    //std::cout << "Significado adicionado: " << conteudo[numeroSignificados] << std::endl;
    numeroSignificados++;
}

bool Significados::possuiSignificado(){
    for(int i = 0; i < numeroSignificados; i++){
        if(conteudo[i] != "")
            return true;
    }
    return false;
}

void Significados::printSignificados(){
    int cont  = 1;
    for(int i = 0; i < numeroSignificados; i++){
        if(conteudo[i] != ""){
            std::cout << cont << ". " << conteudo[i] << std::endl;
            cont++;
        }
    }
}