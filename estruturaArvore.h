#ifndef ESTRUTURAARVORE_H
#define ESTRUTURAARVORE_H

#include <iostream>

using namespace std;
#define ORDEM 5

//Estrutura para árvore B+
typedef struct{
    int    flhos[ORDEM]; //ORDEM-1 é o ponteiro para o irmão
    int  chave[ORDEM-1]; //Vetor de chaves
    int             pai;
    bool       ehFolha;
    int      numChaves;
}NoBMais;

typedef struct{
    int topo,posLivre,raiz;
}CabecalhoArvore;


//Classe para representar a árvore B+
class BMais{
private:
    NoBMais no;
    CabecalhoArvore cab;
public:
    //Construtor padrão da classe BMais
    BMais();

    //Construtor com os parâmetros do nó
    BMais(NoBMais no);

    /* Setter da variável no
     * Entrada:      No
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável nó recebe o valor do parâmetro
    */
    void setNo(NoBMais no);

    /* Getter da variável no
     * Entrada:      Nenhuma
     * Retorno:      Nó
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    NoBMais getNo();

    /* Setter da variável cab
     * Entrada:      Cabeçalho do arquivo de árvore
     * Retorno:      Nenhum
     * Pré-condição: Nenhuma
     * Pós-condição: A variável cabeçalho recebe o valor do parâmetro
    */
    void setCabecaloArvore(CabecalhoArvore cab);

    /* Getter da variável cab
     * Entrada:      Nenhuma
     * Retorno:      Cabeçalho do arquivo de árvore
     * Pré-condição: Nenhuma
     * Pós-condição: Nenhuma
    */
    CabecalhoArvore getCabecalhoArvore();

    //Destrutor da classe BMais
    ~BMais();
};

#endif