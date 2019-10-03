#ifndef ESTRUTURAARVORE_H
#define ESTRUTURAARVORE_H

#include <iostream>

using namespace std;

#define ORDEM 5
typedef struct{
    int info;
    int posLivro;
}Chave;

// Estrutura para árvore B+
typedef struct{
    int posLivro[ORDEM];  //Posição dos livros no arquivo binário de livros
    int  filhos[ORDEM+1]; //ORDEM é o ponteiro para o irmão
    Chave   chave[ORDEM]; //Vetor de chaves
    int       numChaves;
    bool        ehFolha;
    int             pai; //Posição para o nó pai, ou para a proxima posição livre no arquivo
}NoBMais;

typedef struct{
    int topo,posLivre,raiz;
}CabecalhoArvore;

#endif