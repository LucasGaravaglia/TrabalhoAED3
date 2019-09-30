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

int main(){
    BMais *a = new BMais();
    inicializarArquivos("livros.bin","arvore.bin");
    NoBMais *n;
    CabecalhoArvore cab;
    a->insere(8);
    a->insere(10);
    a->insere(7);
    a->insere(9);
    // a->insere(6);
    // a->insere(13);
    //a->insere(12);
    //a->insere(13);
    //a->insere(14);
    // ..........n = arvore->lerNo(2);
    // ..........printVet(n->chave,n->numChaves);
    // ..........printf("pai = %d\n",n->pai);
    // ..........n = arvore->lerNo(0);
    // ..........printVet(n->chave,n->numChaves);
    // ..........printf("pai = %d\n",n->pai);
    n = arvore->lerNo(0);
    printVet(n->chave,n->numChaves);
    printf("pai = %d\neh filho %d",n->pai,n->ehFolha);
    // cab = a->getCab();
    // printf("raiz = %d, topo = %d, poslivre = %d",cab.raiz,cab.topo,cab.posLivre);
    //n = arvore->lerNo(3);
    //printVet(n->chave,n->numChaves);
    delete livros; delete arvore; delete n;
    return 0;
}