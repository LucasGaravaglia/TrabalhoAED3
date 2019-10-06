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

void inserir(int codigo){
    livro.quantidade = 45;
    livro.codigo = codigo;
    strcpy(livro.autor,"lucas");
    strcpy(livro.titulo,"caio");
    gerente.inserirLivro(livro);
}

void inicializarArquivos(string liv, string arv){
    arvore = Arquivo(arv,arv);
    livros = Arquivo(liv,liv);

    arvore.escreverArquivoArvoreVazio();
    livros.escreverArquivoLivrosVazio();
}

int main(){
    inicializarArquivos("livros.bin","arvore.bin");
    // deciderMenu();
    //BMais aux;
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    inserir(6);
    inserir(7);
    inserir(8);
    inserir(9);
    // arv.DeBug(2);
    arv.imprimirTodoOsNiveis();
    printf("\n");
    chave.info = 3;
    arv.remover(chave);
    arv.imprimirTodoOsNiveis();
    return 0;
}