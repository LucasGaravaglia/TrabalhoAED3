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
    int pos,posA;
    arv->inserir(10);
    arv->inserir(20);
    arv->inserir(30);
    arv->inserir(40);
    arv->inserir(50);
    delete livros; delete arvore; delete arv;
    return 0;
}