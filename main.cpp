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
    inserir(100);
    inserir(200);
    inserir(300);
    inserir(400);
    inserir(500);
    inserir(600);
    inserir(700);
    chave.info = 600;
    arv.mudarNo(3);
    arv.removerChaveNaFolha(chave);
    arv.imprimirTodoOsNiveis();
    cout << "\n\n\n";
    chave.info = 300;
    //arv.mudarNo(1);
    arv.mudarNo(1);
    arv.removerChaveNaFolhaComMerge(chave);
    arv.imprimirTodoOsNiveis();
    return 0;
}