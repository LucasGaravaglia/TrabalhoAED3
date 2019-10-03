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
    Chave envia;
    envia.info = 10;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    envia.info++;
    arv->inserir(envia);
    arv->imprimirTodoOsNiveis();
    delete livros; delete arvore; delete arv;
    return 0;
}