#include "dicionario.hpp"

int main(int argc, char* argv[]) {

    Dicionario* dicionario = new Dicionario();
    dicionario->inserirVerbeteAVL("pera", "aaaa");
    dicionario->inserirVerbeteAVL("morango", "aaaa");
    dicionario->inserirVerbeteAVL("mouse", "");
    dicionario->inserirVerbeteAVL("cachorro", "");
    dicionario->inserirVerbeteAVL("morango", "bbb");

    dicionario->printArvoreAVL(dicionario->raiz, 0);
    dicionario->deletarPalavrasComSignificadoAVL(dicionario->raiz, 0);
    std::cout << std::endl;
    dicionario->printArvoreAVL(dicionario->raiz, 0);

    return 0;

}