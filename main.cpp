#include <iostream>
#include "estruturaLivro.h"
#include "estruturaArvore.h"
#include "arquivo.h"
#include "arvore.h"

using namespace std;

Arquivo* arvore;
Arquivo* livros;

void inicializarArquivos(string liv, string arv){
    arvore = new Arquivo(arv,arv);
    livros = new Arquivo(liv,liv);

    arvore->escreverArquivoArvoreVazio();
    livros->escreverArquivoLivrosVazio();
}

void printVet(int *v, int n){
    int i;
    printf("V: ");
    for(i=0;i<n;i++){
        printf(" %d ",v[i]);
    }
    printf("\n");
}

void debug(int pos,bool eh_folha = false,bool prox_folha = false ,bool nos = false,bool pai= false){
    NoBMais* n;
    n = arvore->lerNo(pos);
    printf("-------------------------------\n");
    printf("pos = %d\n",pos);
    if(nos) printVet(n->chave,n->numChaves);
    if(n->ehFolha) printf("eh_folha\n"); else printf("nao_folha\n");
    if(prox_folha) printf("prox folha = %d\n",n->filhos[ORDEM]);
    if(pai) printf("pai = %d",n->pai);
    printf("-------------------------------\n");
    delete(n);


}

int main(){
    BMais *a = new BMais();
    inicializarArquivos("livros.bin","arvore.bin");
    CabecalhoArvore cab;
    a->insere(8);
    a->insere(10);
    a->insere(7);
    a->insere(9);
    a->insere(6);
    a->insere(2);
    a->insere(3);
    a->insere(4);
    //a->insere(14);
    // if(a->buscaNo(10) == -1) printf("no nao encontrado");
    // else printf("no encontrado");
    debug(2,true,true,true,false);
    debug(0,true,true,true,false);
    debug(1,true,true,true,false);
    debug(3,true,true,true,false);
    
    delete livros; delete arvore;
    return 0;
}