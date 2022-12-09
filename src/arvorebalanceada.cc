#include "arvorebalanceada.hpp"

void AVL::rotacaoDireita(Verbete* verbete){
    Verbete* aux = verbete->filhoEsquerdo;
    verbete->filhoEsquerdo = aux->filhoDireito;
    aux->filhoDireito = verbete;
    verbete = aux;
}

void AVL::rotacaoEsquerda(Verbete* verbete){
    Verbete* aux = verbete->filhoDireito;
    verbete->filhoDireito = aux->filhoEsquerdo;
    aux->filhoEsquerdo = verbete;
    verbete = aux;
}

int AVL::fatorBalanceamentoVerbete(Verbete* verbete){
    int alturaEsquerda = 0;
    int alturaDireita = 0;
    if(verbete->filhoEsquerdo != NULL)
        alturaEsquerda = verbete->filhoEsquerdo->altura;
    if(verbete->filhoDireito != NULL)
        alturaDireita = verbete->filhoDireito->altura;
    return alturaEsquerda - alturaDireita;
}


//inserir balanceado rotacao
void AVL::inserirAVL(Verbete* verbete){
    
    if(raiz->palavra == verbete->palavra){
        raiz->setSignificado(verbete->getSignificado());
        return;
    }
    if(verbete->pai == NULL){
        raiz = verbete;
        return;
    }
    if(verbete->pai->filhoEsquerdo == NULL){
        verbete->pai->filhoEsquerdo = verbete;
        if(fatorBalanceamentoVerbete(verbete->pai) == 2){
            if(fatorBalanceamentoVerbete(verbete) == 1){
                rotacaoDireita(verbete->pai);
            }
            else{
                rotacaoEsquerda(verbete);
                rotacaoDireita(verbete->pai);
            }
        }
    }
    else{
        verbete->pai->filhoDireito = verbete;
        if(fatorBalanceamentoVerbete(verbete->pai) == -2){
            if(fatorBalanceamentoVerbete(verbete) == -1){
                rotacaoEsquerda(verbete->pai);
            }
            else{
                rotacaoDireita(verbete);
                rotacaoEsquerda(verbete->pai);
            }
        }
    }
}

//Remover balanceado rotacao
void AVL::removerVerbetesComSignificado(){
    if(raiz == NULL)
        return;
    if(raiz->filhoEsquerdo != NULL){
        raiz->filhoEsquerdo->pai = NULL;
        removerVerbetesComSignificado();
    }
    if(raiz->filhoDireito != NULL){
        raiz->filhoDireito->pai = NULL;
        removerVerbetesComSignificado();
    }
    if(raiz->comSignificado()){
        if(raiz->pai == NULL){
            raiz = NULL;
            return;
        }
        if(raiz->pai->filhoEsquerdo == raiz){
            raiz->pai->filhoEsquerdo = NULL;
        }
        else{
            raiz->pai->filhoDireito = NULL;
        }
        raiz = NULL;
    }
}

//Balancear arvore
void AVL::balancearAVL(){
    if(raiz == NULL)
        return;
    if(raiz->filhoEsquerdo != NULL){
        raiz->filhoEsquerdo->pai = NULL;
        balancearAVL();
    }
    if(raiz->filhoDireito != NULL){
        raiz->filhoDireito->pai = NULL;
        balancearAVL();
    }
    if(fatorBalanceamentoVerbete(raiz) == 2){
        if(fatorBalanceamentoVerbete(raiz->filhoEsquerdo) == 1){
            rotacaoDireita(raiz);
        }
        else{
            rotacaoEsquerda(raiz->filhoEsquerdo);
            rotacaoDireita(raiz);
        }
    }
    else if(fatorBalanceamentoVerbete(raiz) == -2){
        if(fatorBalanceamentoVerbete(raiz->filhoDireito) == -1){
            rotacaoEsquerda(raiz);
        }
        else{
            rotacaoDireita(raiz->filhoDireito);
            rotacaoEsquerda(raiz);
        }
    }
}


//Destruir arvore
void AVL::destruirAVL(){
    if(raiz == NULL)
        return;
    if(raiz->filhoEsquerdo != NULL){
        raiz->filhoEsquerdo->pai = NULL;
        destruirAVL();
    }
    if(raiz->filhoDireito != NULL){
        raiz->filhoDireito->pai = NULL;
        destruirAVL();
    }
    delete raiz;
    raiz = NULL;
}
