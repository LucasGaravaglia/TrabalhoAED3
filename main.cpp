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
    inserir(2);
    inserir(3);
    inserir(4);
    inserir(5);
    inserir(7);
    inserir(8);
    inserir(10);
    inserir(11);
    inserir(13);
    inserir(14);
    inserir(18);
    inserir(19);
    inserir(20);
    chave.info = 20;
    arv.mudarNo(6);
    arv.removerChaveNaFolha(chave);
    chave.info = 14;
    arv.mudarNo(5);
    arv.removerChaveNaFolhaComMerge(chave);
    aux.mudarNo(7);
    arv.mudarNo(2);
    chave.info = 10;
    arv.mergeNaoFolha(aux,chave);
    arv.imprimirTodoOsNiveis();
    return 0;
}