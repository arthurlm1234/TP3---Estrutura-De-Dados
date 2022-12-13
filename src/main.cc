#include "dicionario.hpp"
#include "msgassert.hpp"
#include <getopt.h>

int main(int argc, char* argv[]) {

    std::string input, output, tipo;
    char log [10] = "log.out";
    bool mem = false;

    std::cout << sizeof(Verbete) << std::endl;

    int opt;

    while ((opt = getopt(argc, argv, "i:o:t:p")) != -1) {
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
            case 'p':
                iniciaMemLog(log);
                ativaMemLog();
                mem = true;
                break;
            default:
                erroAssert(true, "Argumentos inválidos");
                break;
        }
    }

    erroAssert(tipo  == "arv" || tipo == "hash", "Tipo inválido");

    std::ifstream entrada(input);
    erroAssert(entrada.is_open(), "Arquivo de entrada não encontrado");

    Dicionario* dicionario = new Dicionario(output);

    std::string palavra, classe, significado, aux;

    while(!entrada.eof()){
        entrada >> classe;

        if(classe == " "){
            break;
        }
        
        std::getline(entrada, palavra, ']');


        //eliminar [ e espaço no começo de palavra  
        for(long unsigned int i = 0; i < palavra.size(); i++){
            if(palavra[i] != '[' && palavra[i] != ' '){
                palavra = palavra.substr(i, palavra.size());
                break;
            }
        }

        palavra = palavra + " (" + classe + ")";

        std::getline(entrada, significado);

        //eliminar espaço no começo de significado
        for(long unsigned int i = 0; i < significado.size(); i++){
            if(significado[i] != ' '){
                significado = significado.substr(i, significado.size());
                break;
            }
        }

        if(palavra != " ()"){
            if(tipo == "arv"){
            dicionario->inserirVerbeteAVL(palavra, significado);
        }else if(tipo == "hash"){
            dicionario->inserirVerbeteHT(palavra, significado);
        }
        }

        palavra = "";
        significado = "";
        classe = "";
        aux = "";
    }
    
    if(tipo == "arv"){
        dicionario->printArvoreAVL(dicionario->raiz, 0);
        dicionario->deletarPalavrasComSignificadoAVL(dicionario->raiz, 0);
        dicionario->printArvoreAVLFinal(dicionario->raiz, 0);
    }else if(tipo == "hash"){
        dicionario->printHT();
        dicionario->imprimirPalavrasSemSignificadoHT();
    }

    if(tipo == "arv"){
        dicionario->destruirArvoreAVL(dicionario->raiz);
    }else if(tipo == "hash"){
        dicionario->destruirHT();
    }

    if(mem){
        desativaMemLog();
        finalizaMemLog();
    }

return 0;
}
