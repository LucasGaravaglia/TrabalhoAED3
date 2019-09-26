#ifndef ESTRUTURAARVORE_H
#define ESTRUTURAARVORE_H
#include <iostream>

using namespace std;
#define ORDEM 5

//Estrutura para árvore B+
typedef struct{
    int posLivro[ORDEM]; //Posição dos livros no arquivo binário de livros
    int  filhos[ORDEM+1]; //ORDEM é o ponteiro para o irmão
    int    chave[ORDEM]; //Vetor de chaves
    int       numChaves;
    bool        ehFolha;
    int             pai;
}NoBMais;

typedef struct{
    int topo,posLivre,raiz;
}CabecalhoArvore;


class BMais{
private:
    NoBMais no;
    CabecalhoArvore cab;
public:
    void setNo(NoBMais no);
    void setCab(CabecalhoArvore cab);
    NoBMais getNo();
    CabecalhoArvore getCab();
};

#endif