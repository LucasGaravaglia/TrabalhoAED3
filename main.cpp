#include <iostream>
#include "estruturaLivro.h"
#include "estruturaArvore.h"
#include "arquivo.h"
#include "arvore.h"

using namespace std;

Arquivo* arvore;
Arquivo* livros;
BMais *arv;
NoBMais *no;
CabecalhoArvore *cab;

void inicializarArquivos(string liv, string arv){
    arvore = new Arquivo(arv,arv);
    livros = new Arquivo(liv,liv);

    arvore->escreverArquivoArvoreVazio();
    livros->escreverArquivoLivrosVazio();
}


int main(){//testando, pra ver oq ta carregando no arquivo
    inicializarArquivos("livros.bin","arvore.bin");
    arv = new BMais();
    NoBMais no;
    CabecalhoArvore cab;
    arv->insere(10);
    arv->insere(20);
    arv->insere(30);
    arv->insere(40);
    arv->insere(50);
    arv->insere(60);
    arv->insere(70);
    arv->insere(80);
    arv->insere(90);
    arv->insere(100);
    arv->insere(110);
    // arv->insere(5);
    // arv->insere(35);
    // arv->insere(55);
    arv->insere(120);
    // arv->insere(25);
    // arv->insere(26);
    // arv->insere(27);
    arv->insere(130);
    arv->DeBug(0);
    arv->DeBug(1);
    arv->DeBug(2);
    arv->DeBug(3);
    arv->DeBug(4);
    arv->DeBug(5);
    arv->DeBug(6);
    arv->DeBug(7);
    arv->DeBug(8);
    // arv->altura();
    //arv->insere(60); 
    // arvore->escreverCabecalhoArvore(cab);
    arv->imprimirTodoOsNiveis();
    delete livros; delete arvore; delete arv;
    return 0;
}