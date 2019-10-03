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

void inserir(int chave){
    Chave envia;
    envia.info = chave;
    arv->inserir(envia);
}

int main(){//testando, pra ver oq ta carregando no arquivo
    inicializarArquivos("livros.bin","arvore.bin");
    arv = new BMais();
    NoBMais no;
    int j;
    for(j=1;j<100000;j++){
        inserir(j);
    }
    arv->imprimirTodoOsNiveis();
    delete livros; delete arvore; delete arv;
    return 0;
}