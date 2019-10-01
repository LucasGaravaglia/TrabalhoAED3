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

int main(){
    inicializarArquivos("livros.bin","arvore.bin");
    arv = new BMais();
    arv->insere(10);
    arv->insere(20);
    arv->insere(30);
    arv->insere(40);
    arv->insere(50);
    arv->insere(60);
    arv->insere(70);
    //imprimirArvore(4);
    arv->imprimirTodoOsNiveis();
    printf("Altura: %d\n",arv->altura());
    delete livros; delete arvore; delete arv; delete no; delete cab;
    return 0;
}