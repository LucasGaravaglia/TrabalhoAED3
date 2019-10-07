#include <iostream>
#include <string>
#include "arquivo.h"
#include "interacao.h"
#include "menu.h"

using namespace std;

Arquivo arvore;
Arquivo livros;
Gerente gerente;
InfoLivro livro;
BMais arv;
Chave chave;
Interacao menu;

void inicializarArquivos(string liv, string arv){
    arvore = Arquivo(arv,arv);
    livros = Arquivo(liv,liv);

    arvore.escreverArquivoArvoreVazio();
    livros.escreverArquivoLivrosVazio();
}

int main(){
    inicializarArquivos("livros.bin","arvore.bin");
    deciderMenu();
    return 0;
}
