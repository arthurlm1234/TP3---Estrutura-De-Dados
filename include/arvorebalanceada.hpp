#include "verbete.hpp"

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

Verbete *novoVerbete(std::string _palavra, std::string _classeMorfologica, std::string _signficados){
    Verbete *verbete = new Verbete();
    verbete->palavra = _palavra;
    verbete->classeMorfologica = _classeMorfologica;
    verbete->significados = _signficados;
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

Verbete *inserirVerbete(Verbete *verbete, std::string _palavra, std::string _classeMorfologica, std::string _signficados){
    if(verbete == NULL){
        return (novoVerbete(_palavra, _classeMorfologica, _signficados));
    }

    if(_palavra < verbete->palavra)
        verbete->filhoEsquerdo = inserirVerbete(verbete->filhoEsquerdo, _palavra, _classeMorfologica, _signficados);
    
    else if(_palavra > verbete->palavra)
        verbete->filhoDireito = inserirVerbete(verbete->filhoDireito, _palavra, _classeMorfologica, _signficados);
    
    else
        return verbete;
    
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

//print palavras alfabeticamente
void printArvore(Verbete *raiz, int nivel){
    if(raiz != NULL){
        printArvore(raiz->filhoEsquerdo, nivel + 1);
        std::cout << raiz->palavra << std::endl;
        printArvore(raiz->filhoDireito, nivel + 1);
    }
}