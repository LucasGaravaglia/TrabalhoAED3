#include <iostream>
#include "estruturaLivro.h"
#include "estruturaArvore.h"
#include "arquivo.h"

using namespace std;

Arquivo* arvore;
Arquivo* livros;

void inicializarArquivos(string liv, string arv){
    arvore = new Arquivo(arv,arv);
    livros = new Arquivo(liv,liv);

    arvore->escreverArquivoArvoreVazio();
    livros->escreverArquivoLivrosVazio();
}

int main(){
    inicializarArquivos("livros.bin","arvore.bin");
    delete livros; delete arvore;
    return 0;
}