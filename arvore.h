#ifndef ARVORE_H
#define ARVORE_H

#include <iostream>
#include "arquivo.h"
#include "estruturaArvore.h"

using namespace std;

class BMais{
private:
    NoBMais no;
    CabecalhoArvore cab;
    Arquivo WHFile;
    int pos;
public:
    //contrutor da classe
    BMais();

    //setter da variavel no
    void setNo(NoBMais no);

    //setter da variavel cab
    void setCab(CabecalhoArvore cab);

    //get da variavel no
    NoBMais getNo();

    //get da variavel cab
    CabecalhoArvore getCab();

    //set da variavel pos
    void setPos(int pos);

    //get da variavel pos
    int getPos();

    //set da variavel pos
    void setWhfile(Arquivo WHFile);

    //get da variavel pos
    int getWhfile();

    /* Método que busca a posição em que está ou estaria a chave em um nó
     * Entrada:      Árvore b+, A chave, Ponteiro para a posição em que estaria a chave
     * Retorno:      1 caso a chave esteja presente ou 0 caso contrário
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: Nenhuma
    */
    int buscaPos(int chave, int *pos);

    /* Método que faz o split de um nó interno(Não folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      posição do novo nó no arquivo binario
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    int splitB(int *chavePromovida);

    /* Método que faz o split de um nó interno(Folha)
     * Entrada:      Nó BMais e ponteiro para a chave que foi promovida
     * Retorno:      posição da nova folha no arquivo binario
     * Pré-condição: Nó não pode ser NULL. Nó Deve estar cheio de chaves
     * Pós-condição: O nó sofre split e promove a chave mediana
    */
    int splitBMais(int *chavePromovida);

    /* Método que adiciona uma chave à direita de pos
     * Entrada:      Nó, posição, chave e filho da direita
     * Retorno:      Nenhum
     * Pré-condição: Nó não pode ser NULL
     * Pós-condição: A chave é adiciona à direita de pos
    */
    void adicionaDireita(int pos, int chave, int subarvore);

    /* Método que verifica se tem overflow no nó
     * Entrada:      Nenhuma
     * Retorno:      True se houver overflow false caso contrario
     * Pre-condicao: No não null
     * Pos-condicao: Nenhuma
    */
    bool overflow();

    /* Método auxiliar para inserir uma chave
     * Entrada:      Arvore b+ e chave a ser inserida
     * Retorno:      Nenhum
     * Pré-condição: A árvore não pode ser NULL
     * Pós-condição: A chave é inserida na árvore
    */
    void insereAux(int chave);

    /* Método que insere uma chave na arvore , fazendo split caso necessario
     * Entrada:      chave a ser inserida
     * Retorno:      Nenhum
     * Pre-condicao: Nenhum
     * Pos-condicao: Nenhum
    */
    void insere(int chave);

    //destrutor da classe
    ~BMais();
};

#endif