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
    inserir(10);
    inserir(20);
    inserir(30);
    inserir(40);
    inserir(50);
    inserir(60);
    inserir(70);
    chave.info = 70;
    arv.mudarNo(3);
    arv.removerChaveNaFolha(chave);
    chave.info = 50;
    arv.removerChaveNaFolhaComMerge(chave);
    arv.imprimirTodoOsNiveis();
    return 0;
}

    // inicializarArquivos("livros.bin","arvore.bin");
    // inserir(10);
    // inserir(20);
    // inserir(30);
    // inserir(40);
    // inserir(50);
    // inserir(60);
    // inserir(70);
    // inserir(80);
    // inserir(90);
    // inserir(100);
    // inserir(110);
    // inserir(120);
    // inserir(130);
    // chave.info = 70;
    // arv.mudarNo(4);
    // arv.removerChaveNaFolhaComMerge(chave);
    // arv.mudarNo(5);
    // arv.mudarNo(8);
    // NoBMais ab;
    // ab = arv.getNo();
    // ab.chave[0].info = 80;
    // chave.info = 80;
    // arv.setNo(ab);
    // arv.arquivo.escreverNo(arv.getNo(),arv.getPos());
    // printf("\n----------\n");
    // arv.mudarNo(7);
    // BMais ddd;
    // ddd.mudarNo(2);
    // ddd.mergeNaoFolhaIntermediario(arv,chave);


    // inicializarArquivos("livros.bin","arvore.bin");
    // inserir(10);
    // inserir(20);
    // inserir(30);
    // inserir(40);
    // inserir(50);
    // inserir(60);
    // inserir(70);
    // inserir(80);
    // inserir(90);
    // inserir(100);
    // inserir(110);
    // inserir(120);
    // inserir(130);
    // chave.info = 50;
    // arv.mudarNo(3);
    // arv.removerChaveNaFolhaComMerge(chave);
    // // arv.mudarNo(8);
    // // NoBMais ab;
    // // ab = arv.getNo();
    // // ab.chave[0].info = 60;
    // // chave.info = 60;
    // // arv.setNo(ab);
    // // arv.arquivo.escreverNo(arv.getNo(),arv.getPos());
    // printf("\n----------\n");
    // arv.mudarNo(7);
    // BMais ddd;
    // ddd.mudarNo(2);
    // ddd.mergeNaoFolhaIntermediario(arv,chave);
    // arv.imprimirTodoOsNiveis();


    //     inserir(10);
    // inserir(20);
    // inserir(30);
    // inserir(40);
    // inserir(50);
    // inserir(60);
    // inserir(70);
    // inserir(80);
    // inserir(90);
    // inserir(100);
    // inserir(110);
    // inserir(120);
    // inserir(130);
    // inserir(140);
    // inserir(150);
    // inserir(160);
    // inserir(170);
    // inserir(180);
    // inserir(190);
    // chave.info = 70;
    // arv.mudarNo(4);
    // arv.removerChaveNaFolhaComMerge(chave);
    // arv.DeBug(5);
    // arv.mudarNo(8);
    // NoBMais ab;
    // ab = arv.getNo();
    // ab.chave[0].info = 80;
    // chave.info = 80;
    // arv.setNo(ab);
    // arv.arquivo.escreverNo(arv.getNo(),arv.getPos());
    // printf("\n----------\n");
    // arv.mudarNo(7);
    // BMais ddd;
    // ddd.mudarNo(2);
    // ddd.mergeNaoFolhaIntermediario(arv,chave);