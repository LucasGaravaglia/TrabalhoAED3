#include <iostream>
#include <string>
#include "arquivo.h"
#include "interacao.h"

using namespace std;

Arquivo arvore;
Arquivo livros;
Gerente gerente;
InfoLivro livro;
BMais arv;
Chave chave;

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
    BMais aux;
    inserir(1);
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    inserir(6);
    inserir(7);
    inserir(8);
    inserir(9);
    inserir(10);
    inserir(11);
    inserir(12);
    inserir(13);
    arv.imprimirTodoOsNiveis();
    printf("\n\n\n");
    chave.info = 6;
    arv.remover(chave);
    arv.imprimirTodoOsNiveis();
    return 0;
}