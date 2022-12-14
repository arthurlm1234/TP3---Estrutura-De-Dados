#include "verbete.hpp"
#include "hashtable.hpp"

class Dicionario{
    public:
        Verbete* raiz;
        Dicionario(std::string _output);
        std::string output;
        void inserirVerbeteAVL(std::string palavra, std::string significado);
        void deletarVerbeteAVL(std::string palavra);
        void deletarPalavrasComSignificadoAVL(Verbete* v, int nivel);
        void printArvoreAVL(Verbete* v, int nivel);
        void printArvoreAVLFinal(Verbete* v, int nivel);
        void destruirArvoreAVL(Verbete* v);

        HashTable* hashtable;
        void inserirVerbeteHT(std::string palavra, std::string significado);
        void deletarVerbeteHT(std::string palavra);
        void deletarPalavrasComSignificadoHT();
        void printHT();
        void destruirHT();
};