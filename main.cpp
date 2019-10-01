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

// void debug(int pos,bool eh_folha = false,bool prox_folha = false ,bool nos = false,bool pai= false){
//     NoBMais* n;
//     n = arvore->lerNo(pos);
//     printf("-------------------------------\n");
//     printf("pos = %d\n",pos);
//     if(nos) printvetBMais(n->chave,n->numChaves);
//     if(n->ehFolha) printf("eh_folha\n"); else printf("nao_folha\n");
//     if(prox_folha) printf("prox folha = %d\n",n->filhos[ORDEM]);
//     if(pai) printf("pai = %d",n->pai);
//     printf("-------------------------------\n");
//     delete(n);
// }

int main(){
    inicializarArquivos("livros.bin","arvore.bin");
    arv = new BMais();
    arv->insere(10);
    arv->insere(20);
    arv->insere(30);
    arv->insere(40);
    arv->insere(50);
    arv->insere(60);
    NoBMais teste;
    teste = arv->
    printf("------%d\n")
    // arv->insere(70);
    // debug(1,false,false,false,true);
    arv->imprimirTodoOsNiveis();
    printf("Altura: %d\n",arv->altura());
    delete livros; delete arvore; delete arv; delete no; delete cab;
    return 0;
}