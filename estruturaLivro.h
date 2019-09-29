#ifndef ESTRUTURALIVRO_H
#define ESTRUTURALIVRO_H

#include <iostream>

using namespace std;

//Estrutura para armazenar as informações de um livro
typedef struct{
    int codigo,quantidade;
    char titulo[1250],autor[1250];
}InfoLivro;

//Estrutura para armazenar o cabeçalho do arquivo de livros
typedef struct{
    int topo,posLivre;
}CabecalhoLivro;

#endif