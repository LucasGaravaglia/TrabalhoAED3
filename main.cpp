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

// int main(){
//     inicializarArquivos("livros.bin","arvore.bin");
//     arv = new BMais();
//     arv->insere(10);
//     arv->insere(20);
//     arv->insere(30);
//     arv->insere(40);
//     arv->insere(50);
//     //arv->insere(60);
//     //arv->insere(70);
//     // debug(1,false,false,false,true);
//     arv->imprimirTodoOsNiveis();
//     printf("Altura: %d\n",arv->altura());
//     delete livros; delete arvore; delete arv; delete no; delete cab;
//     return 0;
// }

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
    arv->DeBug(0);
    arv->DeBug(1);
    arv->DeBug(2);

    //arv->insere(60); 
    // no.numChaves = 1;
    // no.chave[0]  = 30;
    // no.ehFolha   = false;
    // no.pai       = 2;
    // no.filhos[0] = 0;
    // no.filhos[1] = 1;
    // no.filhos[2] = -1;
    // no.filhos[3] = -1;
    // no.filhos[4] = -1;
    // no.filhos[5] = -1;
    // arvore->escreverNo(no,2);
    // no.numChaves = 2;
    // no.chave[0]  = 10;
    // no.chave[1]  = 20;
    // no.ehFolha   = true;
    // no.pai       = 2;
    // no.filhos[0] = -1;
    // no.filhos[1] = -1;
    // no.filhos[2] = -1;
    // no.filhos[3] = -1;
    // no.filhos[4] = -1;
    // no.filhos[5] = 1;
    // arvore->escreverNo(no,0);
    // no.numChaves = 3;
    // no.chave[0]  = 30;
    // no.chave[1]  = 40;
    // no.chave[2]  = 50;
    // no.ehFolha   = true;
    // no.pai       = 2;
    // no.filhos[0] = -1;
    // no.filhos[1] = -1;
    // no.filhos[2] = -1;
    // no.filhos[3] = -1;
    // no.filhos[4] = -1;
    // no.filhos[5] = -1;
    // arvore->escreverNo(no,1);
    // cab.raiz = 2;
    // cab.posLivre = -1;
    // cab.topo = 3;
    // arvore->escreverCabecalhoArvore(cab);
    // arv->imprimirTodoOsNiveis();
    delete livros; delete arvore; delete arv;
    return 0;
}