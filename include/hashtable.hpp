#include "verbete.hpp"
#include "listaencadeada.hpp"

//create a hashtable for creating a dictionary
class HashTable{
    public:
        HashTable(std::string saida);
        std::string saida;
        int funcaoHash(Verbete verbete);
        Verbete buscarVerbete(Verbete verbete);
        void inserirVerbete(Verbete verbete);
        void deletarVerbete(Verbete verbete);
        void imprimirVerbetesSemSignificado();
        static const int M = 52;
        ListaEncadeada tabela[M];
        void printTabela();
        void destruirTabela();
};