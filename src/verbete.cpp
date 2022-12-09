#include "verbete.hpp"

Verbete::Verbete(int altura, std::string palavra, std::string classeMorfologica, std::string significado){
    this->altura = altura;
    this->palavra = palavra;
    this->classeMorfologica = classeMorfologica;
    significados = significado;
    contSignificados = 1;
    filhoEsquerdo = NULL;
    filhoDireito = NULL;
    pai = NULL;
}

bool Verbete::comSignificado(){
    return significados.size() != 0;
}

void Verbete::setSignificado(std::string significado){
    significados += "\n" + std::to_string(contSignificados) + ". " + significado;
    contSignificados++;
}

void Verbete::printVerbete(){
    if(!comSignificado())
        return;
    
    std::cout << "1. ";
    std::cout << palavra << " (" << classeMorfologica << ") " << std::endl;
    std::cout << significados << std::endl;
}