#include "verbete.hpp"

class Dicionario{
    public:
        Verbete* raiz;
        Dicionario();
        void inserirVerbeteAVL(std::string palavra, std::string significado);
        void deletarVerbeteAVL(std::string palavra);
        void deletarPalavrasComSignificadoAVL(Verbete* v, int nivel);
        void printArvoreAVL(Verbete* v, int nivel);
        void destruirArvoreAVL(Verbete* v);
};