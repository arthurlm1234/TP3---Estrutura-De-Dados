#include "verbete.hpp"

int cont = 0;
std::string palavras[10000];
std::ofstream arquivo("output.txt");

void adicionarPalavra(std::string palavra){
    palavras[cont] = palavra;
    cont++;
}

int altura(Verbete *v){
    if(v == NULL){
        return 0;
    }

    return v->altura;
}

int max(int a, int b){
    if(a > b)
        return a;
    
    return b;
}

Verbete *novoVerbete(std::string _palavra, std::string _signficados){
    Verbete *verbete = new Verbete();
    verbete->palavra = _palavra;
    verbete->significados.adicionarSignificado(_signficados);
    verbete->altura = 1;
    return(verbete);
}

Verbete *rotacaoDireita(Verbete *y){
    Verbete *x = y->filhoEsquerdo;
    Verbete *T2 = x->filhoDireito;
    x->filhoDireito = y;
    y->filhoEsquerdo = T2;
    y->altura = max(altura(y->filhoEsquerdo), altura(y->filhoDireito)) + 1;
    x->altura= max(altura(x->filhoEsquerdo), altura(x->filhoDireito)) + 1;
    return x;
}

Verbete *rotacaoEsquerda(Verbete *x){
    Verbete *y = x->filhoDireito;
    Verbete *T2 = y->filhoEsquerdo;
    y->filhoEsquerdo = x;
    x->filhoDireito = T2;
    x->altura = max(altura(x->filhoEsquerdo), altura(x->filhoDireito)) + 1;
    y->altura = max(altura(y->filhoEsquerdo), altura(y->filhoDireito)) + 1;
    return y;
}

int calcularFatorBalanco(Verbete *n){
    if(n == NULL){
        return 0;
    }
    return altura(n->filhoEsquerdo) - altura(n->filhoDireito);
}

Verbete *inserirVerbete(Verbete *verbete, std::string _palavra, std::string _signficados){
    if(verbete == NULL){
        return (novoVerbete(_palavra, _signficados));
    }

    if(_palavra < verbete->palavra)
        verbete->filhoEsquerdo = inserirVerbete(verbete->filhoEsquerdo, _palavra, _signficados);
    
    else if(_palavra > verbete->palavra)
        verbete->filhoDireito = inserirVerbete(verbete->filhoDireito, _palavra, _signficados);
    
    else{
        if (_signficados != "")
            verbete->significados.adicionarSignificado(_signficados);
        return verbete;
    }
        
    
    verbete->altura = 1 + max(altura(verbete->filhoDireito), altura(verbete->filhoEsquerdo));
    
    int fatorBalanco = calcularFatorBalanco(verbete);

    if(fatorBalanco > 1){
        if(_palavra < verbete->filhoEsquerdo->palavra){
            return rotacaoDireita(verbete);
        }
        else if(_palavra > verbete->filhoEsquerdo->palavra){
            verbete->filhoEsquerdo = rotacaoEsquerda(verbete->filhoEsquerdo);
            return rotacaoDireita(verbete);
        }
    }

    if(fatorBalanco < -1){
        if(_palavra > verbete->filhoDireito->palavra){
            return rotacaoEsquerda(verbete);
        }
        else if(_palavra < verbete->filhoDireito->palavra){
            verbete->filhoDireito = rotacaoDireita(verbete->filhoDireito);
            return rotacaoEsquerda(verbete);
        }
    }
    return verbete;
}

//find word with significado and save in a array palavras
void buscarPalavrasComSignificado(Verbete *raiz, int nivel){
    if(raiz == NULL){
        return;
    }

    LEMEMLOG((long int)(&raiz), sizeof(raiz),0);

    buscarPalavrasComSignificado(raiz->filhoEsquerdo, nivel);
    if(raiz->significados.possuiSignificado()){
        adicionarPalavra(raiz->palavra);
    }
    buscarPalavrasComSignificado(raiz->filhoDireito, nivel);
}


Verbete *ultimaPalavra(Verbete *verbete){
    Verbete *atual = verbete;
    while(atual->filhoEsquerdo != NULL){
        LEMEMLOG((long int)(&atual), sizeof(atual),0);
        atual = atual->filhoEsquerdo;
    }

    return atual;
}

Verbete *deletarVerbete(Verbete *raiz, std::string _palavra){
    if(raiz == NULL){
        return raiz;
    }

    LEMEMLOG((long int)(&raiz), sizeof(raiz),0);
        
    if(_palavra < raiz->palavra)
        raiz->filhoEsquerdo = deletarVerbete(raiz->filhoEsquerdo, _palavra);
    else if(_palavra > raiz->palavra)
        raiz->filhoDireito = deletarVerbete(raiz->filhoDireito, _palavra);
    else{
        if ((raiz->filhoEsquerdo == NULL) || (raiz->filhoDireito == NULL)){
            Verbete *temp = raiz->filhoEsquerdo ? raiz->filhoEsquerdo : raiz->filhoDireito;
            if(temp == NULL){
                temp = raiz;
                raiz = NULL;
            }
            else{
                *raiz = *temp;
            }
            free(temp);
        }
        else{
            Verbete *temp = ultimaPalavra(raiz->filhoDireito);
            raiz->palavra = temp->palavra;
            raiz->filhoDireito = deletarVerbete(raiz->filhoDireito, temp->palavra);
        }
    }

    if(raiz == NULL){
        return raiz;
    }
    
    return raiz;
}

//pecoore toda arvore e ve se possui alguma palvra sem significado
bool existePalavraSemSignificado(Verbete *raiz, int nivel){
    if(raiz == NULL){
        return false;
    }

    LEMEMLOG((long int)(&raiz), sizeof(raiz),0);

    if(!raiz->significados.possuiSignificado()){
        return true;
    }
    else{
        return existePalavraSemSignificado(raiz->filhoEsquerdo, nivel) || existePalavraSemSignificado(raiz->filhoDireito, nivel);
    }
}

void printArvore(Verbete *raiz, int nivel){
    if(raiz != NULL){
        LEMEMLOG((long int)(&raiz), sizeof(raiz),0);
        printArvore(raiz->filhoEsquerdo, nivel + 1);
        arquivo << raiz->palavra << std::endl;
        arquivo << raiz->significados.printSignificados().str();
        printArvore(raiz->filhoDireito, nivel + 1);
    }
}

void printArvoreFinal (Verbete *raiz, int nivel){
    if(raiz != NULL){
        LEMEMLOG((long int)(&raiz), sizeof(raiz),0);
        printArvoreFinal(raiz->filhoEsquerdo, nivel + 1);
        arquivo << raiz->palavra << std::endl;
        printArvoreFinal(raiz->filhoDireito, nivel + 1);
    }
}

void destruirArvore(Verbete *raiz){
    if(raiz != NULL){
        LEMEMLOG((long int)(&raiz), sizeof(raiz),0);
        destruirArvore(raiz->filhoEsquerdo);
        destruirArvore(raiz->filhoDireito);
        delete raiz;
    }
}




