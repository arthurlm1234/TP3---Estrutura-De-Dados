#include "dicionario.hpp"
#include <getopt.h>

int main(int argc, char* argv[]) {

    /*Dicionario* dicionario = new Dicionario();
    dicionario->inserirVerbeteAVL("pera", "aaaa");
    dicionario->inserirVerbeteAVL("morango", "aaaa");
    dicionario->inserirVerbeteAVL("mouse", "");
    dicionario->inserirVerbeteAVL("cachorro", "");
    dicionario->inserirVerbeteAVL("morango", "bbb");

    dicionario->printArvoreAVL(dicionario->raiz, 0);
    dicionario->deletarPalavrasComSignificadoAVL(dicionario->raiz, 0);
    std::cout << std::endl;
    dicionario->printArvoreAVL(dicionario->raiz, 0);*/

    /*Dicionario* dicionario = new Dicionario("a");

    dicionario->inserirVerbeteHT("pera", "aaaa");
    dicionario->inserirVerbeteHT("morango", "aaaa");
    dicionario->inserirVerbeteHT("mouse", "");
    dicionario->inserirVerbeteHT("cachorro", "");
    dicionario->inserirVerbeteHT("morango", "bbb");
    dicionario->inserirVerbeteHT("ameixa", "bbb");
    dicionario->inserirVerbeteHT("Cha", "bbb");
    dicionario->inserirVerbeteHT("banana", "bbb");
    dicionario->inserirVerbeteHT("abacaxi", "bbb");

    dicionario->printHT();
    std::cout << std::endl;
    dicionario->imprimirPalavrasSemSignificadoHT();*/

    std::string input, output, tipo;

    int opt;

    while ((opt = getopt(argc, argv, "i:o:t:")) != -1) {
        switch (opt) {
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
            case 't':
                tipo = optarg;
                break;
            default:
                std::cout << "Opção inválida" << std::endl;
                break;
        }
    }

    std::ifstream entrada(input);

    Dicionario* dicionario = new Dicionario(output);

    std::string palavra, classe, significado, aux;

    while(!entrada.eof()){
        entrada >> classe;
        
        //getline até ]
        std::getline(entrada, palavra, ']');


        //eliminar [ e espaço no começo de palavra  
        for(long unsigned int i = 0; i < palavra.size(); i++){
            if(palavra[i] != '[' && palavra[i] != ' '){
                palavra = palavra.substr(i, palavra.size());
                break;
            }
        }


        //std::cout << palavra << std::endl;

        palavra = palavra + " (" + classe + ")";

        //salvar até o fim da linha em significados
        std::getline(entrada, significado);

        //eliminar espaço no começo de significado
        for(long unsigned int i = 0; i < significado.size(); i++){
            if(significado[i] != ' '){
                significado = significado.substr(i, significado.size());
                break;
            }
        }

        if(tipo == "avl"){
            dicionario->inserirVerbeteAVL(palavra, significado);
        }else if(tipo == "hash"){
            //std::cout << "insere: " << palavra << " " << significado << std::endl;
            dicionario->inserirVerbeteHT(palavra, significado);
        }

        palavra = "";
        significado = "";
        classe = "";
        aux = "";
    

    }

    //std::cout << "terminou de ler" << std::endl << std::endl;

    if(tipo == "avl"){
        dicionario->printArvoreAVL(dicionario->raiz, 0);
        dicionario->deletarPalavrasComSignificadoAVL(dicionario->raiz, 0);
        dicionario->printArvoreAVL(dicionario->raiz, 0);
    }else if(tipo == "hash"){
        dicionario->printHT();
        dicionario->imprimirPalavrasSemSignificadoHT();
    }
return 0;
}
